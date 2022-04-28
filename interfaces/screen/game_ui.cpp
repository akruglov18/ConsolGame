#include "game_ui.h"

GameUI::GameUI() {
    font = *Resources::FontsHolder::getResource("basic_font");

    gr_items_array_size = 12;
    stats_bar_x = 10.f;
    stats_bar_y = 646.f;
    stats_plate_x = 220.f;
    stats_plate_y = 648.f;
    items_arr_x = 320.f;
    items_arr_y = 648.f;

    // THREE BARS IN THE LEFT BOTTOM CORNER ///////////////////////////////////////////////////////
    stats_bar_sprite.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    stats_bar_sprite.setTextureRect({{448, 180}, {84, 64}});
    stats_bar_sprite.setPosition({10.f, 646.f});

    health_bar_sprite.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    health_bar_sprite.setTextureRect({{350, 40}, {8, 14}});
    health_bar_sprite.setScale({16.f, 1.f});
    health_bar_sprite.setPosition({stats_bar_x + 84.f, stats_bar_y + 5.f});

    hunger_bar_sprite.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    hunger_bar_sprite.setTextureRect({{379, 40}, {8, 14}});
    hunger_bar_sprite.setScale({16.f, 1.f});
    hunger_bar_sprite.setPosition({stats_bar_x + 84.f, stats_bar_y + 25.f});

    mana_bar_sprite.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    mana_bar_sprite.setTextureRect({{379, 56}, {8, 14}});
    mana_bar_sprite.setScale({16.f, 1.f});
    mana_bar_sprite.setPosition({stats_bar_x + 84.f, stats_bar_y + 45.f});

    back_bar_sprite.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    back_bar_sprite.setTextureRect({{284, 42}, {8, 16}});
    back_bar_sprite.setScale({14.f, 1.f});

    edge_bar_sprite.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    edge_bar_sprite.setTextureRect({{324, 40}, {9, 20}});
    edge_bar_sprite.setPosition({stats_bar_x + 196.f, stats_bar_y + 2.f});

    // STATS PLATE BOTTOM /////////////////////////////////////////////////////////////////////////
    stats_plate_spriteL.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    stats_plate_spriteL.setTextureRect({{16, 510}, {16, 40}});
    stats_plate_spriteL.setPosition({stats_plate_x, stats_plate_y});
    stats_plate_spriteL.setScale({1.f, 1.5f});

    stats_plate_spriteM.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    stats_plate_spriteM.setTextureRect({{84, 510}, {16, 40}});
    stats_plate_spriteM.setPosition({stats_plate_x + 16.f, stats_plate_y});
    stats_plate_spriteM.setScale({4.f, 1.5f});

    stats_plate_spriteR.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    stats_plate_spriteR.setTextureRect({{154, 510}, {16, 40}});
    stats_plate_spriteR.setPosition({stats_plate_x + 80.f, stats_plate_y});
    stats_plate_spriteR.setScale({1.f, 1.5f});

    // INVENTORY SLOTS BOTTOM /////////////////////////////////////////////////////////////////////
    for (int i = 0; i < gr_items_array_size; ++i) {
        gr_items_array.push_back(std::make_shared<GraphicSlot>(GraphicSlot()));
        gr_items_array[i]->slot_sprite.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
        if (i == 0) {
            gr_items_array[i]->slot_sprite.setTextureRect({{574, 286}, {38, 40}});
        } else if (i == gr_items_array_size - 1) {
            gr_items_array[i]->slot_sprite.setTextureRect({{650, 286}, {38, 40}});
        } else {
            gr_items_array[i]->slot_sprite.setTextureRect({{613, 286}, {36, 40}});
        }
        float offset_x = 0.f;
        if (i >= 2)
            offset_x = static_cast<float>(i - 1) * 4;
        gr_items_array[i]->slot_sprite.setPosition({items_arr_x + i * 38.f * 1.5f - offset_x, items_arr_y});
        gr_items_array[i]->slot_sprite.setScale({1.5f, 1.5f});
        gr_items_array[i]->slot = std::make_shared<Slot>(Slot());
    }
}

void GameUI::update_UI(Player& p) {
    p;
}

void GameUI::show_UI(sf::RenderWindow& window, std::vector<bool> opened_skills) {

    if (opened_skills[0]) {
        back_bar_sprite.setPosition({stats_bar_x + 84.f, stats_bar_y + 4.f});
        window.draw(back_bar_sprite);
        back_bar_sprite.setPosition({stats_bar_x + 84.f, stats_bar_y + 24.f});
        window.draw(back_bar_sprite);
        back_bar_sprite.setPosition({stats_bar_x + 84.f, stats_bar_y + 44.f});
        window.draw(back_bar_sprite);
        edge_bar_sprite.setPosition({stats_bar_x + 196.f, stats_bar_y + 2.f});
        window.draw(edge_bar_sprite);
        edge_bar_sprite.setPosition({stats_bar_x + 196.f, stats_bar_y + 22.f});
        window.draw(edge_bar_sprite);
        edge_bar_sprite.setPosition({stats_bar_x + 196.f, stats_bar_y + 42.f});

        window.draw(edge_bar_sprite);
        window.draw(stats_bar_sprite);
        window.draw(health_bar_sprite);
        window.draw(hunger_bar_sprite);
        window.draw(mana_bar_sprite);
    }

    if (opened_skills[1]) {
        window.draw(stats_plate_spriteL);
        window.draw(stats_plate_spriteM);
        window.draw(stats_plate_spriteR);
    }

    for (auto& el : gr_items_array)
        el->show_slot(window);
}
