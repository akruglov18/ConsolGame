#include "graphic_inventory.h"

///////////////////////////////////////////////////////////////////////////////////////////////////

// BASE_GRAPHIC_INVENTORY /////////////////////////////////////////////////////////////////////////

std::pair<sf::IntRect, std::pair<sf::Vector2f, sf::Vector2f>> BaseGraphicInventory::calculate_slots(
        std::size_t i, std::size_t j, std::size_t width, std::size_t height) {
    int x = 0;
    int y = 0;
    int w = 0;
    int h = 0;
    if (i == 0 && j == 0) {
        x = 190;
        y = 292;
        w = h = 38;
    } else if (j == 0 && i != height - 1) {
        x = 190;
        y = 331;
        w = 38;
        h = 36;
    } else if (j == 0 && i == height - 1) {
        x = 190;
        y = 368;
        w = h = 38;
    } else if (i == 0 && j != width - 1) {
        x = 229;
        y = 292;
        w = 36;
        h = 38;
    } else if (i == 0 && j == width - 1) {
        x = 266;
        y = 292;
        w = h = 38;
    } else if (j == width - 1 && i != height - 1) {
        x = 266;
        y = 331;
        w = 38;
        h = 36;
    } else if (i == height - 1 && j == width - 1) {
        x = 266;
        y = 368;
        w = h = 38;
    } else if (i == height - 1 && j != width - 1) {
        x = 229;
        y = 368;
        w = 36;
        h = 38;
    } else {
        x = 229;
        y = 331;
        w = h = 36;
    }

    float offset_x = 0.f;
    float offset_y = 0.f;
    float offset_amount_x = 0.f;
    float offset_amount_y = 0.f;

    if (j >= 2)
        offset_x = static_cast<float>(j - 1) * 4;
    if (i >= 2)
        offset_y = static_cast<float>(i - 1) * 4;
    if (j >= 1)
        offset_amount_x = static_cast<float>(j) * 4;
    if (i >= 1)
        offset_amount_y = static_cast<float>(i) * 4;

    return {{{x, y}, {w, h}}, {{offset_x, offset_y}, {offset_amount_x, offset_amount_y}}};
}

///////////////////////////////////////////////////////////////////////////////////////////////////

// GRAPHIC_INVENTORY_REF //////////////////////////////////////////////////////////////////////////

GraphicSlotRef::GraphicSlotRef(std::shared_ptr<Slot>& other): slot(other) {
}

void GraphicSlotRef::show_slot(sf::RenderWindow& window) {
    window.draw(slot_sprite);
    if (slot->get_item() != nullptr) {
        window.draw(slot->get_item()->get_icon());
        window.draw(gr_amount);
    }
}

void GraphicInventoryRef::build_inventory(std::vector<std::shared_ptr<Slot>>& items, float pos_x, float pos_y) {
    gr_items_array.resize(0);
    gr_items_array.reserve(items.size());
    for (std::size_t i = Inventory::bar_size; i < items.size(); ++i) {
        gr_items_array.push_back(std::make_shared<GraphicSlotRef>(GraphicSlotRef(items[i])));
    }

    pos.x = pos_x;
    pos.y = pos_y;

    std::size_t width, height;
    width = height = static_cast<std::size_t>(std::sqrt(items.size() - Inventory::bar_size));
    if (width * height != items.size() - Inventory::bar_size)
        throw std::logic_error("Incorrect inventory size!\n");
    for (std::size_t i = 0; i < height; ++i) {
        for (std::size_t j = 0; j < width; ++j) {
            std::pair<sf::IntRect, std::pair<sf::Vector2f, sf::Vector2f>> res = calculate_slots(i, j, width, height);
            float offset_x = res.second.first.x;
            float offset_y = res.second.first.y;
            float offset_amount_x = res.second.second.x;
            float offset_amount_y = res.second.second.y;

            auto& slot = gr_items_array[i * width + j];
            slot->slot_sprite.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
            slot->slot_sprite.setTextureRect(res.first);
            slot->slot_sprite.setPosition({(j * 76.f) - offset_x + pos_x, (i * 76.f) - offset_y + pos_y});
            slot->slot_sprite.setScale({2.f, 2.f});

            slot->gr_amount.setFont(*Resources::FontsHolder::getResource("basic_font"));
            slot->gr_amount.setCharacterSize(16);
            slot->gr_amount.setStyle(sf::Text::Bold);
            slot->gr_amount.setFillColor(sf::Color(0, 240, 24));
            slot->gr_amount.setPosition(sf::Vector2f(
                    {(j * 76.f) - offset_amount_x + pos_x + 54.f, (i * 76.f) - offset_amount_y + pos_y + 52.f}));

            slot->pos = {{slot->slot_sprite.getPosition()},
                         {static_cast<float>(res.first.width * 2), static_cast<float>(res.first.height * 2)}};
        }
    }
}

std::shared_ptr<GraphicSlotRef>& GraphicInventoryRef::operator[](std::size_t index) {
    return gr_items_array[index];
}

void GraphicInventoryRef::set_pos(float x, float y) {
    if (x == pos.x && y == pos.y) {
        return;
    }

    float diff_x = x - pos.x;
    float diff_y = y - pos.y;

    pos.x = x;
    pos.y = y;

    for (std::size_t i = 0; i < gr_items_array.size(); ++i) {
        auto& posslot = gr_items_array[i]->slot_sprite.getPosition();
        auto& posamount = gr_items_array[i]->gr_amount.getPosition();
        gr_items_array[i]->slot_sprite.setPosition({posslot.x + diff_x, posslot.y + diff_y});
        gr_items_array[i]->gr_amount.setPosition({posamount.x + diff_x, posamount.y + diff_y});
        gr_items_array[i]->pos.left = gr_items_array[i]->slot_sprite.getPosition().x;
        gr_items_array[i]->pos.top = gr_items_array[i]->slot_sprite.getPosition().y;
        if (gr_items_array[i]->slot->get_item() != nullptr) {
            auto& positem = gr_items_array[i]->slot->get_item()->get_icon().getPosition();
            gr_items_array[i]->slot->get_item()->get_icon().setPosition({positem.x + diff_x, positem.y + diff_y});
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

// GRAPHIC_INVENTORY_COPY /////////////////////////////////////////////////////////////////////////

void GraphicSlotCopy::show_slot(sf::RenderWindow& window) {
    window.draw(slot_sprite);
    if (slot->get_item() != nullptr) {
        window.draw(slot->get_item()->get_icon());
        window.draw(gr_amount);
    }
}

void GraphicInventoryCopy::build_inventory(std::vector<std::shared_ptr<Slot>>& items, float pos_x, float pos_y) {
    gr_items_array.resize(0);
    gr_items_array.reserve(items.size());
    for (std::size_t i = 0; i < items.size(); ++i) {
        gr_items_array.push_back(std::make_shared<GraphicSlotCopy>(GraphicSlotCopy()));
    }

    pos.x = pos_x;
    pos.y = pos_y;

    std::size_t width, height;
    width = height = static_cast<std::size_t>(std::sqrt(items.size()));
    if (width * height != items.size())
        throw std::logic_error("Incorrect inventory size!\n");
    for (std::size_t i = 0; i < height; ++i) {
        for (std::size_t j = 0; j < width; ++j) {
            std::pair<sf::IntRect, std::pair<sf::Vector2f, sf::Vector2f>> res = calculate_slots(i, j, width, height);
            float offset_x = res.second.first.x;
            float offset_y = res.second.first.y;
            float offset_amount_x = res.second.second.x;
            float offset_amount_y = res.second.second.y;

            auto& slot = gr_items_array[i * width + j];
            slot->slot = items[i * width + j];
            slot->slot_sprite.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
            slot->slot_sprite.setTextureRect(res.first);
            slot->slot_sprite.setPosition({(j * 76.f) - offset_x + pos_x, (i * 76.f) - offset_y + pos_y});
            slot->slot_sprite.setScale({2.f, 2.f});

            slot->gr_amount.setFont(*Resources::FontsHolder::getResource("basic_font"));
            slot->gr_amount.setCharacterSize(16);
            slot->gr_amount.setStyle(sf::Text::Bold);
            slot->gr_amount.setFillColor(sf::Color(0, 240, 24));
            slot->gr_amount.setPosition(sf::Vector2f(
                    {(j * 76.f) - offset_amount_x + pos_x + 54.f, (i * 76.f) - offset_amount_y + pos_y + 52.f}));

            slot->pos = {{slot->slot_sprite.getPosition()},
                         {static_cast<float>(res.first.width * 2), static_cast<float>(res.first.height * 2)}};
        }
    }
}

std::shared_ptr<GraphicSlotCopy>& GraphicInventoryCopy::operator[](std::size_t index) {
    return gr_items_array[index];
}

void GraphicInventoryCopy::set_pos(float x, float y) {
    if (x == pos.x && y == pos.y) {
        return;
    }

    float diff_x = x - pos.x;
    float diff_y = y - pos.y;

    pos.x = x;
    pos.y = y;

    for (std::size_t i = 0; i < gr_items_array.size(); ++i) {
        auto& posslot = gr_items_array[i]->slot_sprite.getPosition();
        auto& posamount = gr_items_array[i]->gr_amount.getPosition();
        gr_items_array[i]->slot_sprite.setPosition({posslot.x + diff_x, posslot.y + diff_y});
        gr_items_array[i]->gr_amount.setPosition({posamount.x + diff_x, posamount.y + diff_y});
        gr_items_array[i]->pos.left = gr_items_array[i]->slot_sprite.getPosition().x;
        gr_items_array[i]->pos.top = gr_items_array[i]->slot_sprite.getPosition().y;
        if (gr_items_array[i]->slot->get_item() != nullptr) {
            auto& positem = gr_items_array[i]->slot->get_item()->get_icon().getPosition();
            gr_items_array[i]->slot->get_item()->get_icon().setPosition({positem.x + diff_x, positem.y + diff_y});
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

// THE LOGIC OF OBJECTS MOVING ////////////////////////////////////////////////////////////////////

std::size_t BaseGraphicInventory::chosen_one = NONE_CHOSEN;
float BaseGraphicInventory::click_offset_x = 0.f;
float BaseGraphicInventory::click_offset_y = 0.f;

void GraphicInventoryRef::check_move_objects(sf::Vector2i _mouse_pos,
                                          std::vector<std::shared_ptr<GraphicSlotRef>>& gr_items_array) {
    sf::Vector2f mouse_pos = {static_cast<float>(_mouse_pos.x), static_cast<float>(_mouse_pos.y)};

    if (chosen_one == NONE_CHOSEN) {
        for (std::size_t i = 0; i < gr_items_array.size(); ++i) {        
            if (gr_items_array[i]->slot->get_item() != nullptr && gr_items_array[i]->pos.contains(mouse_pos)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                    chosen_one = i;
                    if (gr_items_array[chosen_one]->slot->get_item()->get_type() == ItemType::WEAPON) {
                        click_offset_x = mouse_pos.x - gr_items_array[i]->pos.left;
                        click_offset_y = mouse_pos.y - gr_items_array[i]->pos.top;
                    } else {
                        click_offset_x = mouse_pos.x - gr_items_array[i]->pos.left - 16.f;
                        click_offset_y = mouse_pos.y - gr_items_array[i]->pos.top - 16.f;
                    }
                    break;
                }
            }
        }
    } else {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            gr_items_array[chosen_one]->slot->get_item()->get_icon().setPosition(
                    {mouse_pos.x - click_offset_x, mouse_pos.y - click_offset_y});
        } else { 
            // placing item into new slot
            bool released_out_of_the_box = true;
            sf::Vector2f chosen_one_pos = gr_items_array[chosen_one]->slot_sprite.getPosition();

            for (std::size_t i = 0; i < gr_items_array.size(); ++i) {
                if (gr_items_array[i]->pos.contains(mouse_pos)) {
                    released_out_of_the_box = false;

                    // pointers exchanging
                    gr_items_array[i]->slot.swap(gr_items_array[chosen_one]->slot);

                    // correct placing of chosen object which is in [i] index after swap
                    sf::Vector2f new_pos;
                    if (gr_items_array[i]->slot->get_item()->get_type() == ItemType::WEAPON) {
                        new_pos = gr_items_array[i]->slot_sprite.getPosition();
                    } else {
                        new_pos = {gr_items_array[i]->slot_sprite.getPosition().x + 16.f,
                                          gr_items_array[i]->slot_sprite.getPosition().y + 16.f};
                    }
                    gr_items_array[i]->slot->get_item()->get_icon().setPosition(new_pos);

                    // placing into empty slot
                    if (gr_items_array[chosen_one]->slot->get_item() == nullptr) {
                        gr_items_array[i]->gr_amount.setString(std::to_string(gr_items_array[i]->slot->get_amount()));
                        break;
                    }

                    // correct graphic amount
                    gr_items_array[chosen_one]->gr_amount.setString(
                            std::to_string(gr_items_array[chosen_one]->slot->get_amount()));
                    gr_items_array[i]->gr_amount.setString(std::to_string(gr_items_array[i]->slot->get_amount()));

                    // correct replacing of object which is in [chosen_one] index after swap
                    if (gr_items_array[chosen_one]->slot->get_item()->get_type() == ItemType::WEAPON) {
                        gr_items_array[chosen_one]->slot->get_item()->get_icon().setPosition(chosen_one_pos);
                    } else {
                        gr_items_array[chosen_one]->slot->get_item()->get_icon().setPosition(
                                {chosen_one_pos.x + 16.f, chosen_one_pos.y + 16.f});
                    }
                }
            }

            if (released_out_of_the_box) {
                if (gr_items_array[chosen_one]->slot->get_item()->get_type() == ItemType::WEAPON) {
                    gr_items_array[chosen_one]->slot->get_item()->get_icon().setPosition(chosen_one_pos);
                } else {
                    gr_items_array[chosen_one]->slot->get_item()->get_icon().setPosition(
                            {chosen_one_pos.x + 16.f, chosen_one_pos.y + 16.f});
                }
            }

            chosen_one = NONE_CHOSEN;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

// GRAPHIC_INVENTORY_BAR_REF //////////////////////////////////////////////////////////////////////

void GraphicInventoryBar::build_inventory(std::vector<std::shared_ptr<Slot>>& items, std::size_t size) {
    pos.x = 480.f;
    pos.y = 648.f;

    for (std::size_t i = 0; i < size; ++i) {
        float offset_x = 0.f;
        if (i >= 2)
            offset_x = static_cast<float>(i - 1) * 4;
        gr_items_array.push_back(std::make_shared<GraphicSlotRef>(GraphicSlotRef(items[i])));
        gr_items_array[i]->slot_sprite.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
        gr_items_array[i]->slot_sprite.setPosition({pos.x + i * 38.f * 1.5f - offset_x, pos.y});
        gr_items_array[i]->slot_sprite.setScale({ 1.5f, 1.5f });
        auto& slot = gr_items_array[i];
        slot->gr_amount.setFont(*Resources::FontsHolder::getResource("basic_font"));
        slot->gr_amount.setCharacterSize(16);
        slot->gr_amount.setStyle(sf::Text::Bold);
        slot->gr_amount.setFillColor(sf::Color(0, 240, 24));

        float offset_amount_x = 0.f;
        if (i >= 1)
            offset_amount_x = static_cast<float>(i) * 4;
        slot->gr_amount.setPosition({(i * 57.f) - offset_amount_x + pos.x + 60.f, 684.f});
        slot->pos = {{slot->slot_sprite.getPosition()},
                     {static_cast<float>(38.f * 1.5f), static_cast<float>(40.f * 1.5f)}};
        if (i == 0) {
            gr_items_array[i]->slot_sprite.setTextureRect({{574, 286}, {38, 40}});
        } else if (i == size - 1) {
            gr_items_array[i]->slot_sprite.setTextureRect({{650, 286}, {38, 40}});
        } else {
            gr_items_array[i]->slot_sprite.setTextureRect({{613, 286}, {36, 40}});
            slot->pos.width = 36.f * 1.5f;
        }
    }
}

void GraphicInventoryBar::dynamic_update(std::vector<std::shared_ptr<Slot>>& items) {
    items;
}

void GraphicInventoryBar::inventory_menu_scale() {
    for (std::size_t i = 0; i < gr_items_array.size(); ++i) {
        auto& posslot = gr_items_array[i]->slot_sprite.getPosition();
        auto& posamount = gr_items_array[i]->gr_amount.getPosition();
        gr_items_array[i]->slot_sprite.setPosition({posslot.x + i * scale_offset, posslot.y});
        gr_items_array[i]->slot_sprite.setScale({ 2.f, 2.f });
        gr_items_array[i]->gr_amount.setPosition({posamount.x + i * scale_offset, posamount.y + 12.f});
        gr_items_array[i]->pos.left = gr_items_array[i]->slot_sprite.getPosition().x;
        gr_items_array[i]->pos.top = gr_items_array[i]->slot_sprite.getPosition().y;
        if (gr_items_array[i]->slot->get_item() != nullptr) {
            float x, y;
            if (gr_items_array[i]->slot->get_item()->get_type() == ItemType::WEAPON) {
                x = gr_items_array[i]->slot_sprite.getPosition().x;
                y = gr_items_array[i]->slot_sprite.getPosition().y;
            } else {
                x = gr_items_array[i]->slot_sprite.getPosition().x + 16.f;
                y = gr_items_array[i]->slot_sprite.getPosition().y + 16.f;
            }
            gr_items_array[i]->slot->get_item()->get_icon().setPosition({x, y});
            gr_items_array[i]->slot->get_item()->get_icon().setScale({1.25f, 1.25f});
            gr_items_array[i]->gr_amount.setString(std::to_string(gr_items_array[i]->slot->get_amount()));
            if (gr_items_array[i]->slot->get_amount() >= 10 && !gr_items_array[i]->gr_amount_offset) {
                x = gr_items_array[i]->gr_amount.getPosition().x - 6.f;
                y = gr_items_array[i]->gr_amount.getPosition().y;
                gr_items_array[i]->gr_amount.setPosition({x, y});
                gr_items_array[i]->gr_amount_offset = true;
            }
        }
    }
}

void GraphicInventoryBar::in_game_scale() {
    for (std::size_t i = 0; i < gr_items_array.size(); ++i) {
        auto& posslot = gr_items_array[i]->slot_sprite.getPosition();
        auto& posamount = gr_items_array[i]->gr_amount.getPosition();
        gr_items_array[i]->slot_sprite.setPosition({posslot.x - i * scale_offset, posslot.y});
        gr_items_array[i]->slot_sprite.setScale({ 1.5f, 1.5f });
        gr_items_array[i]->gr_amount.setPosition({posamount.x - i * scale_offset, posamount.y - 12.f});
        gr_items_array[i]->pos.left = gr_items_array[i]->slot_sprite.getPosition().x;
        gr_items_array[i]->pos.top = gr_items_array[i]->slot_sprite.getPosition().y;
        if (gr_items_array[i]->slot->get_item() != nullptr) {
            float x, y;
            if (gr_items_array[i]->slot->get_item()->get_type() == ItemType::WEAPON) {
                x = gr_items_array[i]->slot_sprite.getPosition().x;
                y = gr_items_array[i]->slot_sprite.getPosition().y;
            } else {
                x = gr_items_array[i]->slot_sprite.getPosition().x + 12.f;
                y = gr_items_array[i]->slot_sprite.getPosition().y + 12.f;
            }
            gr_items_array[i]->slot->get_item()->get_icon().setPosition({x, y});
            gr_items_array[i]->slot->get_item()->get_icon().setScale({1.f, 1.f});
            gr_items_array[i]->gr_amount.setString(std::to_string(gr_items_array[i]->slot->get_amount()));
            if (gr_items_array[i]->slot->get_amount() >= 10 && !gr_items_array[i]->gr_amount_offset) {
                x = gr_items_array[i]->gr_amount.getPosition().x - 6.f;
                y = gr_items_array[i]->gr_amount.getPosition().y;
                gr_items_array[i]->gr_amount.setPosition({x, y});
                gr_items_array[i]->gr_amount_offset = true;
            }
        }
    }
}
