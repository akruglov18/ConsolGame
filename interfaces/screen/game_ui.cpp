#include "game_ui.h"

// SETTINGS ///////////////////////////////////////////////////////////////////////////////////////
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

// MAP ////////////////////////////////////////////////////////////////////////////////////////
MiniMap::MiniMap() {
    map_x = 1205.f;
    map_y = 645.f;

    map_sprite.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    map_sprite.setTextureRect({{847, 290}, {-128, 128}});
    map_sprite.setOrigin({64.f, 64.f});
    map_sprite.setRotation(sf::degrees(180.f));
    map_sprite.setPosition({map_x, map_y});

    linker1.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    linker1.setTextureRect({{815, 417}, {20, 6}});
    linker1.setPosition({map_x + 32.f, map_y - 70});
    linker2.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    linker2.setTextureRect({{815, 417}, {20, 6}});
    linker2.setPosition({map_x + 32.f, map_y - 120.f});

    show_battles_button.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    show_battles_button.setTextureRect({{802, 431}, {44, 44}});
    show_battles_button.setPosition({map_x + 20.f, map_y - 114.f});

    open_help_button.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    open_help_button.setTextureRect({{802, 431}, {44, 44}});
    open_help_button.setPosition({map_x + 20.f, map_y - 164.f});

    show_battles_inner.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    show_battles_inner.setTextureRect({{722, 486}, {27, 24}});
    show_battles_inner.setPosition({map_x + 29.f, map_y - 104.f});

    open_help_inner.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    open_help_inner.setTextureRect({{758, 505}, {26, 18}});
    open_help_inner.setPosition({map_x + 29.f, map_y - 152.f});
}

void MiniMap::show_minimap(sf::RenderWindow& window) {
    window.draw(map_sprite);
    window.draw(show_battles_button);
    window.draw(open_help_button);
    window.draw(show_battles_inner);
    window.draw(open_help_inner);
    window.draw(linker1);
    window.draw(linker2);
}

void MiniMap::check_buttons(sf::Vector2i mouse_pos) {
    if (mouse_pos.x > open_help_button.getPosition().x && mouse_pos.x < open_help_button.getPosition().x + 44.f &&
        mouse_pos.y > open_help_button.getPosition().y && mouse_pos.y < open_help_button.getPosition().y + 44.f) {
        if (!help_hovered) {
            open_help_button.setTextureRect({{802, 481}, {44, 44}});
            help_hovered = true;
        }
    } 
    else {
        if (help_hovered) {
            open_help_button.setTextureRect({{802, 431}, {44, 44}});
            help_hovered = false;
        }
    }
    if (mouse_pos.x > show_battles_button.getPosition().x && mouse_pos.x < show_battles_button.getPosition().x + 44.f &&
        mouse_pos.y > show_battles_button.getPosition().y && mouse_pos.y < show_battles_button.getPosition().y + 44.f) {
        if (!battles_hovered) {
            show_battles_button.setTextureRect({{802, 481}, {44, 44}});
            battles_hovered = true;
        }
    } else {
        if (battles_hovered) {
            show_battles_button.setTextureRect({{802, 431}, {44, 44}});
            battles_hovered = false;
        }
    }
}


GameUI::GameUI() {
    font = *Resources::FontsHolder::getResource("basic_font");    

    // BARS AND SETTINGS //////////////////////////////////////////////////////////////////////////
    stats_bar_x = 10.f;
    stats_bar_y = 646.f;

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

    // MAGIC MENU /////////////////////////////////////////////////////////////////////////////////
    magic_plate_x = 220.f;
    magic_plate_y = 648.f;

    magic_plate_spriteL.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    magic_plate_spriteL.setTextureRect({{16, 510}, {16, 40}});
    magic_plate_spriteL.setPosition({magic_plate_x, magic_plate_y});
    magic_plate_spriteL.setScale({1.f, 1.5f});

    magic_plate_spriteM.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    magic_plate_spriteM.setTextureRect({{84, 510}, {16, 40}});
    magic_plate_spriteM.setPosition({magic_plate_x + 16.f, magic_plate_y});
    magic_plate_spriteM.setScale({4.f, 1.5f});

    magic_plate_spriteR.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
    magic_plate_spriteR.setTextureRect({{154, 510}, {16, 40}});
    magic_plate_spriteR.setPosition({magic_plate_x + 80.f, magic_plate_y});
    magic_plate_spriteR.setScale({1.f, 1.5f});

    // INVENTORY //////////////////////////////////////////////////////////////////////////////////
    gr_items_array_size = 12;
    items_arr_x = 320.f;
    items_arr_y = 648.f;

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

    if (show_settings) {
        settings.check_settings(sf::Mouse::getPosition(window));
        settings.show_settings(window);
    }

    for (auto& el : gr_items_array)
        el->show_slot(window);

    minimap.check_buttons(sf::Mouse::getPosition(window));
    minimap.show_minimap(window);
}

void GameUI::check_settings_cogwheel(sf::Vector2i mouse_pos) {
    if (mouse_pos.x > stats_bar_x + 18.f && mouse_pos.x < stats_bar_x + 46.f &&
        mouse_pos.y > stats_bar_y + 18.f && mouse_pos.y < stats_bar_y + 46.f) {  
        cogwheel_sprite.rotate(sf::degrees(0.5f));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !cogwheel_pressed) {
            show_settings = !show_settings;
            cogwheel_pressed = true;
        }
        if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            cogwheel_pressed = false;
        }
    }
}
