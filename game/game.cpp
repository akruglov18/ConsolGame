#include "Game.h"
#include <thread>

//#define universal

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

Game::Game() {

    /////////////////////////////////////////////////////////////TIME_CHECK///////////////////////////////////////////////////////////
    auto start = std::chrono::high_resolution_clock::now();
    HOLDER().load_textures();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Textures loading: " << std::setw(9) << diff.count() << " s\n";
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    game_field = std::shared_ptr<Field>(new Field(size, size));
    game_field->generate_field();
    view.reset(sf::FloatRect(0, 0, 1280, 720));
    
    player = std::shared_ptr<Player>(new Player(manager, 100, { 366.f, 560.f }));
    get_player_pos_for_view(player->get_pos());
    manager.setPlayer(player);
    player->init_dress();

    for (int i = 0; i < 20; ++i) {
        enemies.push_back(Enemy::spawn_enemy(CreatureType::SKELETON, manager, 100, { (i % 7) * 200.f, (i / 7 + 1) * 256.f }));
        enemies[i]->get_armor()[ArmorType::TORSO] = std::shared_ptr<BodyArmor>(new BodyArmor_chain(enemies[i]->get_pos()));
        enemies[i]->get_armor()[ArmorType::HELMET] = std::shared_ptr<Helmet>(new Helmet_chain_hood(enemies[i]->get_pos()));
    }    
}

void Game::game_loop() {    
    sf::Clock clock;
    sf::Keyboard::Key key = sf::Keyboard::Down;
    sf::Event last_event;
    while (window.isOpen()) {
        // The regulator of game speed
        auto time = clock.getElapsedTime().asMicroseconds() / 15000.f;
        clock.restart();

        sf::Event event;
        window.pollEvent(event);
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if(event.type == sf::Event::MouseMoved || event.type == sf::Event::MouseWheelScrolled ||
            event.type == sf::Event::MouseLeft || event.type == sf::Event::MouseEntered ||
            event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseButtonReleased) {
            event = std::move(last_event);
        }

        player->action(event, time, game_field, drawable_creatures);
        get_player_pos_for_view(player->get_pos());

        for(auto& x : enemies) {
             x->action(player, time);
        }

        last_event = std::move(event);
        /////////////////////////////////////////////////////////////TIME_CHECK///////////////////////////////////////////////////////////
        auto start = std::chrono::high_resolution_clock::now();
        render();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        std::cout << "fps: " << std::setw(9) << 1 / diff.count() << "\r";
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    }
}

void Game::render() {
    window.setView(view);
    window.clear(sf::Color(0, 0, 0));
    auto borders = Utils::get_rendering_borders(window.getSize().x, window.getSize().y,
                                                game_field->get_width(), game_field->get_height(), player->get_pos());
    auto object_borders = Utils::get_object_borders(borders, game_field->get_width(), game_field->get_height());
    drawable_creatures = Utils::find_drawable_creatures(enemies, object_borders);
    Utils::sort_drawable_creatures(drawable_creatures);
    Drawer::show_everything(window, game_field, borders, object_borders, player, drawable_creatures);
    window.display();
}

sf::View Game::get_player_pos_for_view(const sf::Vector2f& pos) {
    // sets camera center as player's coordinates
    auto temp_x = pos.x;
    auto temp_y = pos.y;
    if (pos.x < window.getSize().x / 2.f)
        temp_x = static_cast<float>(window.getSize().x / 2.f);
    if (pos.y < window.getSize().y / 2.f)
        temp_y = static_cast<float>(window.getSize().y / 2.f);
    if (pos.x > game_region_width - window.getSize().x / 2.f)
        temp_x = static_cast<float>(game_region_width - window.getSize().x / 2.f);
    if (pos.y > game_region_height - window.getSize().y / 2.f)
        temp_y = static_cast<float>(game_region_height - window.getSize().y / 2.f);

    view.setCenter(sf::Vector2f(temp_x, temp_y));
    return view;
}
