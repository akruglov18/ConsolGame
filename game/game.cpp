#include "Game.h"
#include <thread>

Game::Game() {
    // Loading of all essential textures
    load_textures();

    _game_field.generate_field();
    _view.reset(sf::FloatRect(0, 0, 1280, 720));

    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    _player = std::make_shared<Creature>(*Creature::spawn_creature(CreatureType::PLAYER, HOLDER().getResource("player"), _manager));
    _player->set_pos(64, 64); // pixels
    _manager.setPlayer(_player);
}

void Game::game_loop() {    

    sf::Clock clock;

    sf::Keyboard::Key key = sf::Keyboard::Down;
    while (_window.isOpen()) {

        // The regulator of game speed
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 15000;

        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window.close();
        }

        if (event.type == sf::Event::KeyPressed) {
            key = event.key.code;
            _player->update(key, time, _game_region_width, _game_region_height);
            get_player_pos_for_view(_player->get_pos()); 
        }
        else {
            _player->stay(key);
            get_player_pos_for_view(_player->get_pos());
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
    _window.display();
}

sf::View Game::get_player_pos_for_view(const sf::Vector2f& pos) {
    // sets camera center as player's coordinates
    float temp_x = pos.x;
    float temp_y = pos.y;
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
    HOLDER().loadFromFile("../../images/grass.png", "grass");
    HOLDER().loadFromFile("../../images/river.png", "river");
}
