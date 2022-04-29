#pragma once
#include "player/player.h"
#include "SFML/Graphics.hpp"
#include "inventory_menu.h"

enum class SettingsType { MUSIC };

class SettingsInGame {
private:
    class CheckBox {
    public:
        CheckBox(const std::string& name, sf::Vector2f pos, SettingsType _type) {
            type = _type;
            sprite.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
            sprite.setTextureRect({{831, 122}, {12, 12}});
            sprite.setScale({1.4f, 1.4f});
            sprite.setPosition(pos);

            text.setFont(*Resources::FontsHolder::getResource("basic_font"));
            text.setString(name);
            text.setPosition({pos.x + 22.f, pos.y - 15.f});
            text.setFillColor(sf::Color(255, 0, 0));
            text.setOutlineThickness(1.f);

            box.left = pos.x;
            box.top = pos.y;
            box.width = 20.f + name.size() * 16;
            box.height = 20.f;
        }
        sf::Sprite sprite;
        sf::Text text;
        sf::FloatRect box;
        SettingsType type;
        bool box_pressed = false;
        bool on = true;
        void show_checkbox(sf::RenderWindow& window) {
            window.draw(sprite);
            window.draw(text);
        }
        void switch_mode() {
            on = !on;
            if (on) {
                sprite.setTextureRect({{831, 122}, {12, 12}});
                if (type == SettingsType::MUSIC)
                    Screen::menu_music.play();
            } else {
                sprite.setTextureRect({{818, 122}, {12, 12}});
                if (type == SettingsType::MUSIC)
                    Screen::menu_music.pause();
            }
        }
    };

public:
    SettingsInGame();
    std::vector<std::shared_ptr<CheckBox>> settings;
    void show_settings(sf::RenderWindow& window);
    void check_settings(sf::Vector2i mouse_pos);
};

class GameUI {
public:
    GameUI();
    sf::Font font;

    // BARS AND SETTINGS //////////////////////////////////////////////////////////////////////////
    float stats_bar_x;
    float stats_bar_y;
    bool cogwheel_pressed = false;
    bool show_settings = true;
    bool play_music = true;
    SettingsInGame settings;
    sf::Sprite stats_bar_sprite;
    sf::Sprite cogwheel_sprite;
    sf::Sprite health_bar_sprite;
    sf::Sprite satiety_bar_sprite;
    sf::Sprite expirience_bar_sprite;
    sf::Sprite back_bar_sprite;
    sf::Sprite edge_bar_sprite;

    // MAGIC MENU /////////////////////////////////////////////////////////////////////////////////
    float magic_plate_x;
    float magic_plate_y;
    sf::Sprite magic_plate_spriteL;
    sf::Sprite magic_plate_spriteM;
    sf::Sprite magic_plate_spriteR;

    // INVENTORY //////////////////////////////////////////////////////////////////////////////////
    float items_arr_x;
    float items_arr_y;
    int gr_items_array_size;
    std::vector<std::shared_ptr<GraphicSlot>> gr_items_array;

    // MAP ////////////////////////////////////////////////////////////////////////////////////////
    float map_x;
    float map_y;
    sf::Sprite map_sprite;

    // METHODS ////////////////////////////////////////////////////////////////////////////////////
    void update_UI(Player& p);
    void show_UI(sf::RenderWindow& window, std::vector<bool> opened_mechanics = {false});
    void check_settings_cogwheel(sf::Vector2i mouse_pos);
};
