#include "Game.h"
#include <thread>

Game::Game() {
    // Loading of all essential textures
    load_textures();

    _game_field.generate_field();
    _view.reset(sf::FloatRect(0, 0, 1280, 720));

    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    _player = std::make_shared<Player>(Player(HOLDER().getResource("player"), _manager, 100, {366.f, 366.f}));
    get_player_pos_for_view(_player->get_pos());
    _manager.setPlayer(_player);
    _player->get_armor().set_body(new BodyArmor(HOLDER().getResource("body_armor1"), _player->get_pos()));
    _player->get_armor().set_helmet(new Helmet(HOLDER().getResource("head_armor1"), _player->get_pos()));
    _enemies.push_back(Enemy::spawn_enemy(CreatureType::SKELETON, _manager, 100, {400.f, 256.f}));
    _enemies[0]->get_armor().set_body(new BodyArmor(HOLDER().getResource("body_armor1"), _enemies[0]->get_pos()));
    _enemies[0]->get_armor().set_helmet(new Helmet(HOLDER().getResource("head_armor1"), _enemies[0]->get_pos()));
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

        ////////////RENDER///////////
        render();
        /////////////////////////////
    }
}

void Game::render() {
    _window.setView(_view);
    _window.clear(sf::Color(0, 0, 0));
    _game_field.show_field(_window, _player->get_pos());
    _player->show_player(_window);
    for (auto& x : _enemies) {
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
    // Creatures
    HOLDER().loadFromFile("../../images/player/walkcycle/BODY_male.png", "player");
    HOLDER().loadFromFile("../../images/player/walkcycle/BODY_skeleton.png", "skeleton");

    // Terrain
    HOLDER().loadFromFile("../../images/terrain/128px/grass1.png", "grass1");
    HOLDER().loadFromFile("../../images/terrain/128px/water1.png", "water1");
    HOLDER().loadFromFile("../../images/terrain/128px/water2.png", "water2");
    HOLDER().loadFromFile("../../images/terrain/128px/water3.png", "water3");
    HOLDER().loadFromFile("../../images/terrain/128px/sand1.png", "sand1");
    HOLDER().loadFromFile("../../images/terrain/128px/sand2.png", "sand2");
    HOLDER().loadFromFile("../../images/terrain/128px/sand3.png", "sand3");
    HOLDER().loadFromFile("../../images/terrain/128px/desert1.png", "desert1");
    HOLDER().loadFromFile("../../images/terrain/128px/dry1.png", "dry1");
    HOLDER().loadFromFile("../../images/terrain/128px/borders_sand1.png", "borders_sand1");

    // Terrain Features
    HOLDER().loadFromFile("../../images/terrain/features/desert_features.png", "desert_features");
    HOLDER().loadFromFile("../../images/terrain/features/desert_trees.png", "desert_trees");

    // armors
    HOLDER().loadFromFile("../../images/player/walkcycle/TORSO_chain_armor_torso.png", "body_armor1");
    HOLDER().loadFromFile("../../images/player/walkcycle/HEAD_chain_armor_hood.png", "head_armor1");
}
