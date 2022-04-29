#include "game_ui.h"

SettingsInGame::SettingsInGame() {
    settings.push_back(std::make_shared<CheckBox>(CheckBox("music", {10.f, 620.f}, SettingsType::MUSIC)));
}

void SettingsInGame::show_settings(sf::RenderWindow& window) {
    for (auto& el : settings)
        el->show_checkbox(window);
}

void SettingsInGame::check_settings(sf::Vector2i mouse_pos) {
    for (auto& el : settings) {
        if (mouse_pos.x > el->box.left && mouse_pos.x < el->box.left + el->box.width && 
            mouse_pos.y > el->box.top && mouse_pos.y < el->box.top + el->box.height) {
            el->text.setFillColor(sf::Color(255, 255, 0));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !el->box_pressed) {
                el->switch_mode();
                el->box_pressed = true;
            }
            if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                el->box_pressed = false;
            }
        } else {
            el->text.setFillColor(sf::Color(255, 0, 0));
        }
    }
}

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
    stats_bar_sprite.setPosition({stats_bar_x, stats_bar_y});

    cogwheel_sprite.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    cogwheel_sprite.setTextureRect({{721, 512}, {28, 28}});
    cogwheel_sprite.setPosition({stats_bar_x + 32.f, stats_bar_y + 32.f});
    cogwheel_sprite.setOrigin({14.f, 14.f});

    health_bar_sprite.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    health_bar_sprite.setTextureRect({{350, 40}, {8, 14}});
    health_bar_sprite.setScale({16.f, 1.f});
    health_bar_sprite.setPosition({stats_bar_x + 84.f, stats_bar_y + 5.f});

    satiety_bar_sprite.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    satiety_bar_sprite.setTextureRect({{379, 40}, {8, 14}});
    satiety_bar_sprite.setScale({16.f, 1.f});
    satiety_bar_sprite.setPosition({stats_bar_x + 84.f, stats_bar_y + 25.f});

    expirience_bar_sprite.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    expirience_bar_sprite.setTextureRect({{379, 56}, {8, 14}});
    expirience_bar_sprite.setScale({0.f, 1.f});
    expirience_bar_sprite.setPosition({stats_bar_x + 84.f, stats_bar_y + 45.f});

    back_bar_sprite.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    back_bar_sprite.setTextureRect({{284, 42}, {8, 16}});
    back_bar_sprite.setScale({14.f, 1.f});

    edge_bar_sprite.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    edge_bar_sprite.setTextureRect({{324, 40}, {9, 20}});
    edge_bar_sprite.setPosition({stats_bar_x + 196.f, stats_bar_y + 2.f});

    // STATS PLATE BOTTOM /////////////////////////////////////////////////////////////////////////
    magic_plate_spriteL.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    magic_plate_spriteL.setTextureRect({{16, 510}, {16, 40}});
    magic_plate_spriteL.setPosition({stats_plate_x, stats_plate_y});
    magic_plate_spriteL.setScale({1.f, 1.5f});

    magic_plate_spriteM.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    magic_plate_spriteM.setTextureRect({{84, 510}, {16, 40}});
    magic_plate_spriteM.setPosition({stats_plate_x + 16.f, stats_plate_y});
    magic_plate_spriteM.setScale({4.f, 1.5f});

    magic_plate_spriteR.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    magic_plate_spriteR.setTextureRect({{154, 510}, {16, 40}});
    magic_plate_spriteR.setPosition({stats_plate_x + 80.f, stats_plate_y});
    magic_plate_spriteR.setScale({1.f, 1.5f});

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
    float satiety = p.get_satiety();
    float max_satiety = p.get_max_satiety();
    float health = p.get_health();
    float max_health = p.get_max_health();
    int exp = p.get_experience();

    health_bar_sprite.setScale({std::fmax(0.f, (health / max_health) * 16.f), 1.f});
    satiety_bar_sprite.setScale({std::fmax(0.f, (satiety / max_satiety) * 16.f), 1.f});
    expirience_bar_sprite.setScale({std::fmin(16.f, exp * 0.03f), 1.f});
}

void GameUI::show_UI(sf::RenderWindow& window, std::vector<bool> opened_mechanics) {

    check_settings_cogwheel(sf::Mouse::getPosition(window));

    if (opened_mechanics[0]) {
        window.draw(magic_plate_spriteL);
        window.draw(magic_plate_spriteM);
        window.draw(magic_plate_spriteR);
    }

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
    window.draw(cogwheel_sprite);
    window.draw(health_bar_sprite);
    window.draw(satiety_bar_sprite);
    window.draw(expirience_bar_sprite);

    for (auto& el : gr_items_array)
        el->show_slot(window);

    if (show_settings) {
        settings.check_settings(sf::Mouse::getPosition(window));
        settings.show_settings(window);
    }
}

void GameUI::check_settings_cogwheel(sf::Vector2i mouse_pos) {
    if (mouse_pos.x > stats_bar_x + 18.f && mouse_pos.x < stats_bar_x + 46.f &&
        mouse_pos.y > stats_bar_y + 18.f && mouse_pos.y < stats_bar_y + 46.f) {  
        cogwheel_sprite.rotate(sf::degrees(1.f));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !cogwheel_pressed) {
            show_settings = !show_settings;
            cogwheel_pressed = true;
        }
        if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            cogwheel_pressed = false;
        }
    }
}
