#include "Game.h"

Game::Game() {
    // Loading of all essential textures
    load_textures();

    _game_field.generate_field();

    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    _player = Creature::spawn_creature(CreatureType::PLAYER, HOLDER().getResource("player"));
}

void Game::load_textures() {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    HOLDER().loadFromFile("../../images/player/walkcycle/BODY_male.png", "player");
    HOLDER().loadFromFile("../../images/grass.png", "grass");
    HOLDER().loadFromFile("../../images/river.png", "river");
}

void Game::game_loop() {    

    sf::Clock clock;

    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

    //Creature* a = Creature::spawn_creature(CreatureType::BEETLE, HOLDER().loadFromFile("images\\enemies\\beetle.png", "beetle"));

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
            _player->update(key, time);
        }
        else {
            _player->stay(key);
        }

        ////////////RENDER///////////
        render();
        /////////////////////////////
    }
}

void Game::render() {
    _window.clear(sf::Color(0, 0, 0));
    _game_field.show_field(_window);
    _window.draw(_player->get_sprite());
    _window.display();
}
