#include "graphic_inventory.h"

void GraphicSlot::show_slot(sf::RenderWindow& window) {
    window.draw(slot_sprite);
    if (slot->get_item() != nullptr) {
        if (slot->get_item()->get_type() == ItemType::WEAPON) {
            window.draw(slot->get_item()->get_icon());
        } else {
            window.draw(slot->get_item()->get_sprite());
        }
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

    pos.x = x;
    pos.y = y;

    for (std::size_t i = 0; i < gr_items_array.size(); ++i) {
        auto& posslot = gr_items_array[i]->slot_sprite.getPosition();
        auto& posamount = gr_items_array[i]->gr_amount.getPosition();
        gr_items_array[i]->slot_sprite.setPosition({posslot.x + diff_x, posslot.y + diff_y});
        gr_items_array[i]->gr_amount.setPosition({posamount.x + diff_x, posamount.y + diff_y});
        if (gr_items_array[i]->slot->get_item() != nullptr) {
            if (gr_items_array[i]->slot->get_item()->get_type() == ItemType::WEAPON) {
                auto& positem = gr_items_array[i]->slot->get_item()->get_icon().getPosition();
                gr_items_array[i]->slot->get_item()->get_icon().setPosition({positem.x + diff_x, positem.y + diff_y});
            } else {
                auto& positem = gr_items_array[i]->slot->get_item()->get_sprite().getPosition();
                gr_items_array[i]->slot->get_item()->get_sprite().setPosition({positem.x + diff_x, positem.y + diff_y});
            }
        }
    }
}
