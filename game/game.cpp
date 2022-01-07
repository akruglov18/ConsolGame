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

    _game_field.generate_field();
    _view.reset(sf::FloatRect(0, 0, 1280, 720));
    
    _player = std::make_shared<Player>(Player(_manager, 100, { 366.f, 560.f }));
    get_player_pos_for_view(_player->get_pos());
    _manager.setPlayer(_player);
    _player->init_dress();

    _enemies.push_back(Enemy::spawn_enemy(CreatureType::SKELETON, _manager, 100, { 400.f, 256.f }));
    _enemies[0]->get_armor()[ArmorType::TORSO] = std::shared_ptr<BodyArmor>(new BodyArmor_chain(_enemies[0]->get_pos()));
    _enemies[0]->get_armor()[ArmorType::HELMET] = std::shared_ptr<Helmet>(new Helmet_chain_hood(_enemies[0]->get_pos()));
}

void Game::game_loop() {    
    sf::Clock clock;
    sf::Keyboard::Key key = sf::Keyboard::Down;
    while (_window.isOpen()) {
        // The regulator of game speed
        auto time = clock.getElapsedTime().asMicroseconds() / 15000.f;
        clock.restart();

        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window.close();
        }

        _player->action(event, time, _game_field);
        get_player_pos_for_view(_player->get_pos());

        for(auto& x : _enemies) {
             x->action(_player, time, _game_field);
        }

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
    _window.setView(_view);
    _window.clear(sf::Color(0, 0, 0));
    Drawer::show_everything(_window, _game_field, _player, _enemies);
    _window.display();
}

sf::View Game::get_player_pos_for_view(const sf::Vector2f& pos) {
    // sets camera center as player's coordinates
    auto temp_x = pos.x;
    auto temp_y = pos.y;
    if (pos.x < _window.getSize().x / 2.f)
        temp_x = static_cast<float>(_window.getSize().x / 2.f);
    if (pos.y < _window.getSize().y / 2.f)
        temp_y = static_cast<float>(_window.getSize().y / 2.f);
    if (pos.x > _game_region_width - _window.getSize().x / 2.f)
        temp_x = static_cast<float>(_game_region_width - _window.getSize().x / 2.f);
    if (pos.y > _game_region_height - _window.getSize().y / 2.f)
        temp_y = static_cast<float>(_game_region_height - _window.getSize().y / 2.f);

    _view.setCenter(sf::Vector2f(temp_x, temp_y));
    return _view;
}
