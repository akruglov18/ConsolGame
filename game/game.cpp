#include "game.h"

Game::Game(sf::RenderWindow* _window, GameSettings& _settings): settings(_settings) {
    std::mt19937 random_for_init;
    auto now = std::chrono::high_resolution_clock::now();
    random_for_init.seed(static_cast<unsigned>(now.time_since_epoch().count()));

    window = _window;
    multiplicator = 1.5f;

    game_field = std::shared_ptr<Field>(new Field(size, size));
    game_field->generate_field();
    view.reset(sf::FloatRect({0, 0}, {1280, 720}));

    player = std::shared_ptr<Player>(new Player(manager, 100.f, {666.f, 260.f}));
    set_player_pos_for_view(player->get_pos());
    manager.setPlayer(player.get());
    manager.setEnemies(&enemies);
    manager.setTraders(&traders);
    manager.setField(game_field.get());

    player->set_armor(BodyArmor::make_body(BodyArmorType::BodyArmor_leather));
    player->set_armor(Helmet::make_helmet(HelmetType::Helmet_chain_helmet));
    player->set_armor(Pants::make_pants(PantsType::Pants_green));
    player->set_armor(Boots::make_boots(BootsType::Boots_brown));
    // player->set_weapon(Axe::make_axe(AxeType::Axe_basic));
    player->set_weapon(Flail::make_flail());
    //player->set_weapon(Halberd::make_halberd());
    std::vector<std::shared_ptr<Items>> tmp_vec;
    tmp_vec.push_back(player->get_weapon());
    tmp_vec.push_back(Axe::make_axe(AxeType::Axe_basic));
    tmp_vec.push_back(Halberd::make_halberd());
    player->inventory.take(tmp_vec);

    for (int i = 0; i < 50; ++i) {
        enemies.push_back(
                Enemy::spawn_enemy(CreatureType::SKELETON, manager, 100.f, {(i % 10 + 4) * 40.f, (i / 10 + 4) * 40.f}));
        enemies[i]->set_armor(BodyArmor::make_body(BodyArmorType::BodyArmor_chain));
        enemies[i]->set_armor(Helmet::make_helmet(HelmetType::Helmet_plate));
        enemies[i]->set_armor(Pants::make_pants(PantsType::Pants_plate));
        enemies[i]->set_weapon(Axe::make_axe(AxeType::Axe_basic));
    }
    // for (int i = 0; i < 3; ++i) {
    //     enemies.push_back(
    //             Enemy::spawn_enemy(CreatureType::SPIDER, manager, 100, {(i % 7 + 1) * 200.f, (i / 7 + 2) * 200.f}));
    // }
    for (int i = 0; i < 10; ++i) {
        traders.push_back(
                std::shared_ptr<Trader>(new Trader(manager, 1000, {(i + 1) * 200.f, 300.f}, random_for_init)));
    }

    game_UI.update_UI(*player);
    // There will be a method that will load inventory from json
    InventoryMenu::gr_inventory->build_inventory(player->inventory.get(), 500.f, 200.f);
    InventoryMenu::gr_inventory_bar->build_inventory(player->inventory.get(), Inventory::bar_size);
    InventoryMenu::gr_united_inventory->build_inventory(*InventoryMenu::gr_inventory, *InventoryMenu::gr_inventory_bar);
    std::vector<std::shared_ptr<Slot>> mock(16);
    TradeMenu::gr_inventory_trader.build_inventory(mock, 700.f, 200.f);
    TradeMenu::bind(InventoryMenu::gr_inventory, InventoryMenu::gr_inventory_bar,
                    InventoryMenu::gr_united_inventory, InventoryMenu::gr_money);
}

Game::~Game() {
    InventoryMenu::gr_inventory->gr_items_array.clear();
    InventoryMenu::gr_inventory_bar->gr_items_array.clear();
    InventoryMenu::gr_united_inventory->gr_items_array.clear();
}

View_mode Game::check_event(sf::Event& event, float time) {
    if (event.type == sf::Event::Closed) {
        std::remove("../../images/tmp.jpg");
        return View_mode::EXIT;
    }

    if (player->dead) {
        countdown_before_gameover_screen += time;
        if (countdown_before_gameover_screen > 5.f) {
            make_screenshot("tmp");
            return View_mode::GAMEOVER_MENU;
        }
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
        case (sf::Keyboard::F1):
            statistics.on = !statistics.on;
            break;
        case (sf::Keyboard::Num1):
        case (sf::Keyboard::Num2):
        case (sf::Keyboard::Num3):
        case (sf::Keyboard::Num4):
        case (sf::Keyboard::Num5):
        case (sf::Keyboard::Num6):
            if (player->inventory.get()[static_cast<std::size_t>(event.key.code - sf::Keyboard::Num1)]->get_item() !=
                        nullptr &&
                player->inventory.get()[static_cast<std::size_t>(event.key.code - sf::Keyboard::Num1)]
                                ->get_item()
                                ->get_type() == ItemType::WEAPON) {
                player->set_weapon(std::dynamic_pointer_cast<BaseWeapon>(
                        player->inventory.get()[static_cast<std::size_t>(event.key.code - sf::Keyboard::Num1)]
                                ->get_item()));
                Animation::stop_animation(player.get());
            }
            break;
        case (sf::Keyboard::B):
            show_boxes = !show_boxes;
            break;
        case (sf::Keyboard::Escape):
            make_screenshot("tmp");
            return View_mode::PAUSE_MENU;
        case (sf::Keyboard::E):
            InventoryMenu::update_graphic_inventory(player->inventory.get(), player->inventory.get_money());
            make_screenshot("tmp");
            return View_mode::INVENTORY_MENU;
        case (sf::Keyboard::T):
            if (player->available_trader != nullptr) {
                TradeMenu::update_graphic_inventories(
                        player->inventory.get(), player->available_trader->inventory.get(),
                        player->inventory.get_money(), player->available_trader->inventory.get_money());
                make_screenshot("tmp");
                return View_mode::TRADE_MENU;
            }
            break;
        default:
            break;
        }
    }
    return View_mode::NONE;
}

View_mode Game::game_loop() {
    sf::Clock clock;
    sf::Event last_event;
    sf::Event event;
    window->pollEvent(event);
    window->pollEvent(last_event);

    event.type = sf::Event::GainedFocus;
    last_event.type = sf::Event::GainedFocus;

    while (window->isOpen()) {
        auto time = clock.getElapsedTime().asMicroseconds() / (multiplicator * 10000);
        clock.restart();

        if (fps.on) {
            fps.add_time(time * multiplicator);
        }
        if (statistics.on) {
            statistics.update(time, fps.get_aver(), enemies.size(), traders.size(), drawable_creatures.size());
        }

        window->pollEvent(event);
        View_mode to_return = check_event(event, time);
        if (to_return != View_mode::NONE)
            return to_return;
        Utils::clear_event(event, last_event, player);

        frame_calculation(time, event, last_event);

        render();

        Screen::play_music();
    }
    return View_mode::NONE;
}

void Game::frame_calculation(float time, sf::Event& event, sf::Event& last_event) {
    // ACTIONS //////////////////////////////////////////////////////
    statistics.start();
    player->action(event, time, game_field.get(), drawable_creatures, animated_sprites);
    for (auto& enemy : enemies) {
        enemy->action(time, game_field.get(), player.get(), settings.difficulty);
    }
    for (auto& trader : traders) {
        trader->action(time, player.get());
    }
    for (auto& sprite : animated_sprites) {
        sprite->action(time);
    }
    statistics.stop(ACTIONS_STAT);
    /////////////////////////////////////////////////////////////////

    // UTILS SECTION ////////////////////////////////////////////////
    statistics.start();
    borders = Utils::get_rendering_borders(window->getSize().x, window->getSize().y, game_field->get_width(),
                                           game_field->get_height(), player->get_pos());
    object_borders = Utils::get_object_borders(borders, game_field->get_width(), game_field->get_height());

    Utils::delete_dead_creatures(enemies, traders);

    Utils::delete_disappeared_sprites(animated_sprites);

    Utils::detect_collisions(drawable_creatures);

    drawable_creatures = Utils::find_drawable_creatures(enemies, traders, object_borders);

    if (!player->dead) {
        drawable_creatures.push_back(player);
    }

    Utils::sort_drawable_creatures(drawable_creatures);

    game_UI.update_UI(*player);
    last_event = std::move(event);
    statistics.stop(PROCESSING_STAT);
    /////////////////////////////////////////////////////////////////
}

void Game::render() {
    window->clear(sf::Color(0, 0, 0));

    // RENDERING DYNAMIC OBJECTS
    set_player_pos_for_view(player->get_pos());
    window->setView(view);

    statistics.start();
    Drawer::show_ground(*window, game_field, borders);
    statistics.stop(GROUND_RENDER_STAT);

    statistics.start();
    Drawer::show_objects(*window, game_field, object_borders, drawable_creatures, show_boxes);
    Drawer::show_animated_sprites(*window, animated_sprites);
    statistics.stop(OBJECTS_RENDER_STAT);

    // RENDERING STATIC UI ELEMENTS
    statistics.start();
    window->setView(window->getDefaultView());
    game_UI.show_UI(*window);
    if (fps.on) {
        fps.show(*window);
    }
    if (statistics.on) {
        statistics.show(*window);
    }
    Cursor::move(*window);
    statistics.stop(GUI_RENDER_STAT);

    statistics.start();
    window->display();
    statistics.stop(DISPLAY_STAT);
}

void Game::set_player_pos_for_view(const sf::Vector2f& pos) {
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
}

void Game::make_screenshot(const std::string& name) {
    sf::Texture texture;
    texture.create(window->getSize().x, window->getSize().y);
    texture.update(*window);
    sf::Image screenshot = texture.copyToImage();
    screenshot.saveToFile("../../images/" + name + ".jpg");
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
