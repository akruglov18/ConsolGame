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

    game_field.generate_field();
    view.reset(sf::FloatRect(0, 0, 1280, 720));
    
    player = std::shared_ptr<Player>(new Player(manager, 100, { 366.f, 560.f }));
    get_player_pos_for_view(player->get_pos());
    manager.setPlayer(player);
    player->init_dress();

    enemies.push_back(Enemy::spawn_enemy(CreatureType::SKELETON, manager, 100, { 400.f, 256.f }));
    enemies[0]->get_armor()[ArmorType::TORSO] = std::shared_ptr<BodyArmor>(new BodyArmor_chain(enemies[0]->get_pos()));
    enemies[0]->get_armor()[ArmorType::HELMET] = std::shared_ptr<Helmet>(new Helmet_chain_hood(enemies[0]->get_pos()));
}

void Game::game_loop() {    
    sf::Clock clock;
    sf::Keyboard::Key key = sf::Keyboard::Down;
    while (window.isOpen()) {
        // The regulator of game speed
        auto time = clock.getElapsedTime().asMicroseconds() / 15000.f;
        clock.restart();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        player->action(event, time, game_field, drawable_creatures);
        get_player_pos_for_view(player->get_pos());

        for(auto& x : enemies) {
             x->action(player, time, game_field);
        }

        /////////////////////////////////////////////////////////////TIME_CHECK///////////////////////////////////////////////////////////
        auto start = std::chrono::high_resolution_clock::now();
        render();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        //std::cout << "fps: " << std::setw(9) << 1 / diff.count() << "\r";
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    }
}

void Game::render() {
    window.setView(view);
    window.clear(sf::Color(0, 0, 0));
    Drawer::show_everything(window, game_field, player, enemies, drawable_creatures);
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
