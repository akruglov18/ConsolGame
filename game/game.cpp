#include "Game.h"
#include <thread>

Game::Game() {
    // Loading of all essential textures
    load_textures();

    _game_field.generate_field();
    _view.reset(sf::FloatRect(0, 0, 1280, 720));

    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    _player = std::make_shared<Player>(Player(HOLDER().getResource("player"), _manager, 100, {32.f, 32.f}));
    get_player_pos_for_view(_player->get_pos());
    _manager.setPlayer(_player);

    _enemies.push_back(Enemy::spawn_enemy(CreatureType::SKELETON, _manager, 100, {400.f, 50.f}));
}

void Game::game_loop() {    
    sf::Clock clock;
    sf::Keyboard::Key key = sf::Keyboard::Down;
    render();
    while (_window.isOpen()) {
        // The regulator of game speed
        auto time = clock.getElapsedTime().asMicroseconds() / 15000.f;
        clock.restart();

        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window.close();
        }

        if (event.type == sf::Event::KeyPressed) {
            key = event.key.code;
            _player->action(key, time, _game_region_width, _game_region_height);
            get_player_pos_for_view(_player->get_pos()); 
        }

        for(auto& x : _enemies) {
             x->action(_player, time, _game_region_width, _game_region_height);
        }

        //creatures_movements();
        ////////////RENDER///////////
        render();
        /////////////////////////////
    }
}

void Game::render() {
    _window.setView(_view);
    _window.clear(sf::Color(0, 0, 0));
    _game_field.show_field(_window, _player->get_pos());
    //show_enemies();
    _window.draw(_player->get_sprite());
    for(auto& x : _enemies) {
            _window.draw(x->get_sprite());
    }
    _window.display();
}

sf::View Game::get_player_pos_for_view(const sf::Vector2f& pos) {
    // sets camera center as player's coordinates
    auto temp_x = pos.x;
    auto temp_y = pos.y;
    if (pos.x < _window.getSize().x / 2)
        temp_x = _window.getSize().x / 2;
    if (pos.y < _window.getSize().y / 2)
        temp_y = _window.getSize().y / 2;
    if (pos.x > _game_region_width - _window.getSize().x / 2)
        temp_x = _game_region_width - _window.getSize().x / 2;
    if (pos.y > _game_region_height - _window.getSize().y / 2)
        temp_y = _game_region_height - _window.getSize().y / 2;

    _view.setCenter(sf::Vector2f(temp_x, temp_y));
    return _view;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////TEXTURES LOADING//////////////////////////////////////////////////////////////////////////
void Game::load_textures() {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    HOLDER().loadFromFile("../../images/player/walkcycle/BODY_male.png", "player");
    HOLDER().loadFromFile("../../images/player/walkcycle/BODY_skeleton.png", "skeleton");
    HOLDER().loadFromFile("../../images/grass.png", "grass");
    HOLDER().loadFromFile("../../images/river.png", "river");
}
