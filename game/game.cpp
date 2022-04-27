#include "Game.h"
#include <fstream>
#include <thread>
#include "armors.h"
#include "weapons.h"
#include "inventory_menu.h"
#include "items.h"
#include "common_thing.h"

//#define universal

void Game::make_screenshot(const std::string& name) {
    sf::Texture texture;
    texture.create(window->getSize().x, window->getSize().y);
    texture.update(*window);
    sf::Image screenshot = texture.copyToImage();
    screenshot.saveToFile("../../images/" + name + ".jpg");
}

Game::Game(sf::RenderWindow* _window, GameSettings& _settings): settings(_settings) {
    window = _window;

    game_field = std::shared_ptr<Field>(new Field(size, size));
    game_field->generate_field();
    for (int i = 1; i <= 16; i++) {
        (*game_field)(10, i * 2 + 20)->items.push_back(std::shared_ptr<Items>
                    (new CommonThing("bone", i, {32.f * (i * 2.f + 20.f), 32.f * 10.f})));
        (*game_field)(12, i * 2 + 20)->items.push_back(std::shared_ptr<Items>
                    (new CommonThing("antidote", i, {32.f * (i * 2.f + 20.f), 32.f * 12.f})));
    }
    view.reset(sf::FloatRect({0, 0}, {1280, 720}));

    player = std::shared_ptr<Player>(new Player(manager, 100, {666.f, 260.f}));
    get_player_pos_for_view(player->get_pos());
    manager.setPlayer(player.get());
    manager.setEnemies(&enemies);
    manager.setField(game_field.get());

    player->set_armor(BodyArmor::make_body(BodyArmorType::BodyArmor_leather));
    player->set_armor(Helmet::make_helmet(HelmetType::Helmet_chain_helmet));
    player->set_armor(Pants::make_pants(PantsType::Pants_green));
    player->set_armor(Boots::make_boots(BootsType::Boots_brown));
    // player->set_weapon(Axe::make_axe(AxeType::Axe_basic));
    // player->set_weapon(Flail::make_flail());
    player->set_weapon(Halberd::make_halberd());

    for (int i = 0; i < 15; ++i) {
        enemies.push_back(
                Enemy::spawn_enemy(CreatureType::SKELETON, manager, 100, {(i % 7 + 1) * 200.f, (i / 7 + 1) * 256.f}));
        enemies[i]->set_armor(BodyArmor::make_body(BodyArmorType::BodyArmor_chain));
        enemies[i]->set_armor(Helmet::make_helmet(HelmetType::Helmet_plate));
        enemies[i]->set_armor(Pants::make_pants(PantsType::Pants_plate));
        enemies[i]->set_weapon(Axe::make_axe(AxeType::Axe_basic));
    }
    // for (int i = 0; i < 3; ++i) {
    //     enemies.push_back(
    //             Enemy::spawn_enemy(CreatureType::SPIDER, manager, 100, {(i % 7 + 1) * 200.f, (i / 7 + 2) * 200.f}));
    // }

    game_UI.update_UI(*player);
    // There will be a method that will load inventory from json
}

View_mode Game::game_loop() {
    sf::Clock clock;
    sf::Event last_event{sf::Event::EventType::GainedFocus};
    sf::Event event{sf::Event::EventType::GainedFocus};

    InventoryMenu::bind_inventory(player->inventory.get());

    while (window->isOpen()) {
        // The regulator of game speed
        auto time = clock.getElapsedTime().asMicroseconds() / 15000.f;
        clock.restart();
        window->pollEvent(event);

        if (event.type == sf::Event::Closed) {
            return View_mode::EXIT;
        }

        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
            case (sf::Keyboard::Tab):
                return View_mode::SKILLS_MENU;
            case (sf::Keyboard::M):
                return View_mode::MAP_MENU;
            case (sf::Keyboard::Tilde):
                fps.on = !fps.on;
                break;
            case (sf::Keyboard::B):
                show_boxes = !show_boxes;
                break;                
            case (sf::Keyboard::Escape):
                make_screenshot("tmp_pause");
                return View_mode::PAUSE_MENU;
            case (sf::Keyboard::E):
                make_screenshot("tmp_inventory");
                return View_mode::INVENTORY_MENU;
            }
        }

        Utils::clear_event(event, last_event, player);

        player->action(event, time, game_field.get(), drawable_creatures);
        get_player_pos_for_view(player->get_pos());

        for (auto& enemy : enemies) {
            enemy->action(time, drawable_creatures, game_field.get(), player.get(), settings.difficulty);
        }

        if (player->dead) {
            countdown_before_gameover_screen += time;
            if (countdown_before_gameover_screen > 5.f) {
                make_screenshot("tmp_gameover");
                return View_mode::GAMEOVER_MENU;
            }
        }

        Utils::delete_dead_creatures(enemies);  // this method will get several vectors (traders, enemies, animals...)
        Utils::detect_collisions(drawable_creatures);

        last_event = std::move(event);

        game_UI.update_UI(*player);
        render(time);
        window->display();
    }
    return View_mode::NONE;
}

void Game::render(float time) {
    // RENDERING DYNAMIC OBJECTS
    window->setView(view);
    window->clear(sf::Color(0, 0, 0));
    auto borders = Utils::get_rendering_borders(window->getSize().x, window->getSize().y, game_field->get_width(),
                                                game_field->get_height(), player->get_pos());
    auto object_borders = Utils::get_object_borders(borders, game_field->get_width(), game_field->get_height());
    drawable_creatures = Utils::find_drawable_creatures(enemies, object_borders);
    if (!player->dead)
        drawable_creatures.push_back(player);
    Utils::sort_drawable_creatures(drawable_creatures);
    Drawer::show_everything(*window, game_field, borders, object_borders, drawable_creatures, show_boxes);

    // RENDERING STATIC UI ELEMENTS
    window->setView(window->getDefaultView());
    game_UI.show_UI(*window);
    if (fps.on) {
        fps.add_time(time, *window);
    }
}

sf::View Game::get_player_pos_for_view(const sf::Vector2f& pos) {
    // sets camera center as player's coordinates
    auto temp_x = pos.x;
    auto temp_y = pos.y;
    if (pos.x < window->getSize().x / 2.f)
        temp_x = static_cast<float>(window->getSize().x / 2.f);
    if (pos.y < window->getSize().y / 2.f)
        temp_y = static_cast<float>(window->getSize().y / 2.f);
    if (pos.x > game_region_width - window->getSize().x / 2.f)
        temp_x = static_cast<float>(game_region_width - window->getSize().x / 2.f);
    if (pos.y > game_region_height - window->getSize().y / 2.f)
        temp_y = static_cast<float>(game_region_height - window->getSize().y / 2.f);

    view.setCenter(sf::Vector2f(temp_x, temp_y));
    return view;
}

bool Game::save(const std::string& file_name) const {
    std::ofstream out(file_name);
    if (!out.is_open())
        return false;

    json json_out;
    json_out[player->creature_type_str()] = player->to_json();
    out << json_out.dump(4);
    // std::cout << json_out.dump(4) << "\n";
    return true;
}

bool Game::load(const std::string& file_name) {
    std::ifstream in(file_name);
    if (!in.is_open())
        return false;
    auto json_obj = json::parse(in);
    for (auto it = json_obj.begin(); it != json_obj.end(); ++it) {
        if (it.key() == player->creature_type_str()) {
            player->load(it.value());
        } else {
            throw std::invalid_argument("Unused key in json save: " + it.key());
        }
    }
    return true;
}
