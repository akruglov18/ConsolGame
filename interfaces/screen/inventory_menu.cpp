#include "inventory_menu.h"

void GraphicSlot::show_slot(sf::RenderWindow& window) {
    window.draw(slot_sprite);
    if (slot->get_item() != nullptr) {
        window.draw(slot->get_item()->get_sprite());
        window.draw(gr_amount);
    }
}

void GraphicInventory::build_inventory(const std::vector<std::shared_ptr<Slot>>& items, float pos_x, float pos_y) {

    gr_items_array.resize(0);
    gr_items_array.reserve(items.size());
    for (std::size_t i = 0; i < items.size(); ++i) {
        gr_items_array.push_back(std::make_shared<GraphicSlot>(GraphicSlot()));
    }

    pos.x = pos_x;
    pos.y = pos_y;

    std::size_t width = static_cast<std::size_t>(std::sqrt(items.size()));
    std::size_t height = static_cast<std::size_t>(std::sqrt(items.size()));
    for (std::size_t i = 0; i < height; ++i) {
        for (std::size_t j = 0; j < width; ++j) {

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

            auto& slot = gr_items_array[i * width + j];
            slot->slot = items[i * width + j];
            slot->slot_sprite.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
            slot->slot_sprite.setTextureRect({{x, y}, {w, h}});
            slot->slot_sprite.setPosition({(j * 76.f) - offset_x + pos_x, (i * 76.f) - offset_y + pos_y});
            slot->slot_sprite.setScale({2.f, 2.f});

            slot->gr_amount.setFont(*Resources::FontsHolder::getResource("basic_font"));
            slot->gr_amount.setCharacterSize(16);
            slot->gr_amount.setStyle(sf::Text::Bold);
            slot->gr_amount.setFillColor(sf::Color(0, 240, 24));
            slot->gr_amount.setPosition(sf::Vector2f(
                    {(j * 76.f) - offset_amount_x + pos_x + 54.f, (i * 76.f) - offset_amount_y + pos_y + 52.f}));
        }
    }
}

std::shared_ptr<GraphicSlot>& GraphicInventory::operator[](std::size_t index) {
    return gr_items_array[index];
}

void GraphicInventory::set_pos(float x, float y) {
    if (x == pos.x && y == pos.y) {
        return;
    }

    float diff_x = x - pos.x;
    float diff_y = y - pos.y;

    std::cout << "shift " << diff_x << " on x\n";
    std::cout << "shift " << diff_y << " on y\n";

    pos.x = x;
    pos.y = y;

    for (std::size_t i = 0; i < gr_items_array.size(); ++i) {
        auto& posslot = gr_items_array[i]->slot_sprite.getPosition();
        gr_items_array[i]->slot_sprite.setPosition({posslot.x + diff_x, posslot.y + diff_y});
        if (gr_items_array[i]->slot->get_item() != nullptr) {
            auto& positem = gr_items_array[i]->slot->get_item()->get_sprite().getPosition();
            gr_items_array[i]->slot->get_item()->get_sprite().setPosition({positem.x + diff_x, positem.y + diff_y});
        }
    }
}

// INVENTORY MENU /////////////////////////////////////////////////////////////////////////////////////////////////////

InventoryMenu::InventoryMenu(): b_exit("Back", sf::FloatRect({20.f, 20.f}, {150.f, 52.f}), View_mode::GAME) {
    color = sf::Color(240, 164, 99);
    buttons.push_back(&b_exit);
    gr_money.setFont(font);
    gr_money.setCharacterSize(40);
    gr_money.setStyle(sf::Text::Bold);
    gr_money.setFillColor(sf::Color(39, 177, 19));
    gr_money.setPosition({500.f, 130.f});
}

void InventoryMenu::update_graphic_inventory(const std::vector<std::shared_ptr<Slot>>& items_array, int _money) {

    gr_inventory.set_pos(500.f, 200.f);

    for (std::size_t i = 0; i < items_array.size(); i++) {
        gr_inventory[i]->slot = items_array[i];
        if (gr_inventory[i]->slot->get_item() != nullptr) {
            float x = gr_inventory[i]->slot_sprite.getPosition().x + 16.f;
            float y = gr_inventory[i]->slot_sprite.getPosition().y + 16.f;
            gr_inventory[i]->slot->get_item()->get_sprite().setPosition({x, y});
            gr_inventory[i]->slot->get_item()->get_sprite().setScale({1.25f, 1.25f});
            gr_inventory[i]->gr_amount.setString(std::to_string(gr_inventory[i]->slot->get_amount()));
            if (gr_inventory[i]->slot->get_amount() >= 10 && !gr_inventory[i]->gr_amount_offset) {
                float x = gr_inventory[i]->gr_amount.getPosition().x - 6.f;
                float y = gr_inventory[i]->gr_amount.getPosition().y;
                gr_inventory[i]->gr_amount.setPosition(sf::Vector2f({x, y}));
                gr_inventory[i]->gr_amount_offset = true;
            }
        }
    }
    gr_money.setString("$ " + std::to_string(_money));
}

void InventoryMenu::show_inventory(sf::RenderWindow& window) {
    for (auto& el : gr_inventory.gr_items_array)
        el->show_slot(window);
    window.draw(gr_money);
}

View_mode InventoryMenu::Run(sf::RenderWindow& window) {
    inventory_screenIMG.loadFromFile("../../images/tmp_inventory.jpg");
    inventory_screen.setTexture(inventory_screenIMG);
    inventory_screen.setColor(sf::Color(210, 164, 120, 130));

    sf::Event event;
    window.pollEvent(event);
    event.type = sf::Event::GainedFocus;
    View_mode to_return{View_mode::NONE};
    window.setView(window.getDefaultView());
    while (true) {
        window.pollEvent(event);

        if (event.type == sf::Event::Closed) {
            std::remove("../../images/tmp_inventory.jpg");
            return View_mode::EXIT;
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::E) {
                std::remove("../../images/tmp_inventory.jpg");
                return View_mode::GAME;
            }
        }

        to_return = MenuButton::buttons_checker(sf::Mouse::getPosition(window), buttons, event);
        if (to_return != View_mode::NONE)
            return to_return;

        window.clear(color);
        window.draw(inventory_screen);
        b_exit.print_button(window);
        show_inventory(window);
        Cursor::move(window);
        window.display();
        play_music();
    }
}
