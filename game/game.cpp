#include "Game.h"
#include <thread>

Game::Game() {
    // Loading of all essential textures
    load_textures();

    _game_field.generate_field();
    _view.reset(sf::FloatRect(0, 0, 1280, 720));

    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    _player = std::make_shared<Player>(Player(HOLDER().getResource("player_walk"), _manager, 100, {366.f, 560.f}));
    get_player_pos_for_view(_player->get_pos());
    _manager.setPlayer(_player);
    _player->init_dress();
    _player->set_weapon(std::make_shared<Weapon>(new Spear), _player->get_pos());

    _enemies.push_back(Enemy::spawn_enemy(CreatureType::SKELETON, _manager, 100, {400.f, 256.f}));
    _enemies[0]->get_armor().set_body(new BodyArmor_chain(_enemies[0]->get_pos()));
    _enemies[0]->get_armor().set_helmet(new Helmet_chain_hood(_enemies[0]->get_pos()));
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
        /////////////////////////////////////////////////////////////TIME_CHECK///////////////////////////////////////////////////////////
        auto start = std::chrono::high_resolution_clock::now();
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        render();
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        std::cout << "fps: " << std::setw(9) << 1 / diff.count() << "\r";
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /////////////////////////////
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

// MAIN THEME PLAYER (MAIN PACK) //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    // bodies//////////////////////////////////////////////////////////////////////////////////////
    HOLDER().loadFromFile("../../images/player/walkcycle/BODY_male.png", "man_walk");
    HOLDER().loadFromFile("../../images/player/thrust/BODY_animation.png", "man_thrust");
    HOLDER().loadFromFile("../../images/player/spellcast/BODY_male.png", "man_spellcast");
    HOLDER().loadFromFile("../../images/player/slash/BODY_human.png", "man_slash");
    HOLDER().loadFromFile("../../images/player/hurt/BODY_male.png", "man_hurt");
    HOLDER().loadFromFile("../../images/player/bow/BODY_animation.png", "man_bow");

    HOLDER().loadFromFile("../../images/player/walkcycle/BODY_skeleton.png", "skeleton_walk");

    // armors /////////////////////////////////////////////////////////////////////////////////////
                                                                                                                                 // WALKCYCLE
    HOLDER().loadFromFile("../../images/player/walkcycle/FEET_plate_armor_shoes.png", "boots_plate_walk");
    HOLDER().loadFromFile("../../images/player/walkcycle/FEET_shoes_brown.png", "boots_brown_walk");
    HOLDER().loadFromFile("../../images/player/walkcycle/HANDS_plate_armor_gloves.png", "gauntlets_plate_walk");
    HOLDER().loadFromFile("../../images/player/walkcycle/HEAD_chain_armor_helmet.png", "head_chain_helmet_walk");
    HOLDER().loadFromFile("../../images/player/walkcycle/HEAD_chain_armor_hood.png", "head_chain_hood_walk");
    HOLDER().loadFromFile("../../images/player/walkcycle/HEAD_leather_armor_hat.png", "head_leather_hat_walk");
    HOLDER().loadFromFile("../../images/player/walkcycle/HEAD_plate_armor_helmet.png", "head_plate_walk");
    HOLDER().loadFromFile("../../images/player/walkcycle/HEAD_robe_hood.png", "head_robe_hood_walk");
    HOLDER().loadFromFile("../../images/player/walkcycle/LEGS_pants_greenish.png", "pants_green_walk");
    HOLDER().loadFromFile("../../images/player/walkcycle/LEGS_plate_armor_pants.png", "pants_plate_walk");
    HOLDER().loadFromFile("../../images/player/walkcycle/LEGS_robe_skirt.png", "pants_robe_skirt_walk");
    HOLDER().loadFromFile("../../images/player/walkcycle/TORSO_chain_armor_jacket_purple.png", "body_chain_purple_walk");
    HOLDER().loadFromFile("../../images/player/walkcycle/TORSO_chain_armor_torso.png", "body_chain_walk");
    HOLDER().loadFromFile("../../images/player/walkcycle/TORSO_leather_armor_bracers.png", "body_leather_bracers_walk");
    HOLDER().loadFromFile("../../images/player/walkcycle/TORSO_leather_armor_shirt_white.png", "body_leather_shirt_walk");
    HOLDER().loadFromFile("../../images/player/walkcycle/TORSO_leather_armor_shoulders.png", "body_leather_shoulders_walk");
    HOLDER().loadFromFile("../../images/player/walkcycle/TORSO_leather_armor_torso.png", "body_leather_walk");
    HOLDER().loadFromFile("../../images/player/walkcycle/TORSO_plate_armor_arms_shoulders.png", "body_plate_shoulders_walk");
    HOLDER().loadFromFile("../../images/player/walkcycle/TORSO_plate_armor_torso.png", "body_plate_walk");
    HOLDER().loadFromFile("../../images/player/walkcycle/TORSO_robe_shirt_brown.png", "body_robe_walk");
                                                                                                                                 // THRUST
    HOLDER().loadFromFile("../../images/player/thrust/FEET_plate_armor_shoes.png", "boots_plate_thrust");
    HOLDER().loadFromFile("../../images/player/thrust/FEET_shoes_brown.png", "boots_brown_thrust");
    HOLDER().loadFromFile("../../images/player/thrust/HANDS_plate_armor_gloves.png", "gauntlets_plate_thrust");
    HOLDER().loadFromFile("../../images/player/thrust/HEAD_chain_armor_helmet.png", "head_chain_helmet_thrust");
    HOLDER().loadFromFile("../../images/player/thrust/HEAD_chain_armor_hood.png", "head_chain_hood_thrust");
    HOLDER().loadFromFile("../../images/player/thrust/HEAD_leather_armor_hat.png", "head_leather_hat_thrust");
    HOLDER().loadFromFile("../../images/player/thrust/HEAD_plate_armor_helmet.png", "head_plate_thrust");
    HOLDER().loadFromFile("../../images/player/thrust/HEAD_robe_hood.png", "head_robe_hood_thrust");
    HOLDER().loadFromFile("../../images/player/thrust/LEGS_pants_greenish.png", "pants_green_thrust");
    HOLDER().loadFromFile("../../images/player/thrust/LEGS_plate_armor_pants.png", "pants_plate_thrust");
    HOLDER().loadFromFile("../../images/player/thrust/LEGS_robe_skirt.png", "pants_robe_skirt_thrust");
    HOLDER().loadFromFile("../../images/player/thrust/TORSO_chain_armor_jacket_purple.png", "body_chain_purple_thrust");
    HOLDER().loadFromFile("../../images/player/thrust/TORSO_chain_armor_torso.png", "body_chain_thrust");
    HOLDER().loadFromFile("../../images/player/thrust/TORSO_leather_armor_bracers.png", "body_leather_bracers_thrust");
    HOLDER().loadFromFile("../../images/player/thrust/TORSO_leather_armor_shirt_white.png", "body_leather_shirt_thrust");
    HOLDER().loadFromFile("../../images/player/thrust/TORSO_leather_armor_shoulders.png", "body_leather_shoulders_thrust");
    HOLDER().loadFromFile("../../images/player/thrust/TORSO_leather_armor_torso.png", "body_leather_thrust");
    HOLDER().loadFromFile("../../images/player/thrust/TORSO_plate_armor_arms_shoulders.png", "body_plate_shoulders_thrust");
    HOLDER().loadFromFile("../../images/player/thrust/TORSO_plate_armor_torso.png", "body_plate_thrust");
    HOLDER().loadFromFile("../../images/player/thrust/TORSO_robe_shirt_brown.png", "body_robe_thrust");
                                                                                                                                 // SPELLCAST
    HOLDER().loadFromFile("../../images/player/spellcast/FEET_plate_armor_shoes.png", "boots_plate_spellcast");
    HOLDER().loadFromFile("../../images/player/spellcast/FEET_shoes_brown.png", "boots_brown_spellcast");
    HOLDER().loadFromFile("../../images/player/spellcast/HANDS_plate_armor_gloves.png", "gauntlets_plate_spellcast");
    HOLDER().loadFromFile("../../images/player/spellcast/HEAD_chain_armor_helmet.png", "head_chain_helmet_spellcast");
    HOLDER().loadFromFile("../../images/player/spellcast/HEAD_chain_armor_hood.png", "head_chain_hood_spellcast");
    HOLDER().loadFromFile("../../images/player/spellcast/HEAD_leather_armor_hat.png", "head_leather_hat_spellcast");
    HOLDER().loadFromFile("../../images/player/spellcast/HEAD_plate_armor_helmet.png", "head_plate_spellcast");
    HOLDER().loadFromFile("../../images/player/spellcast/HEAD_robe_hood.png", "head_robe_hood_spellcast");
    HOLDER().loadFromFile("../../images/player/spellcast/LEGS_pants_greenish.png", "pants_green_spellcast");
    HOLDER().loadFromFile("../../images/player/spellcast/LEGS_plate_armor_pants.png", "pants_plate_spellcast");
    HOLDER().loadFromFile("../../images/player/spellcast/LEGS_robe_skirt.png", "pants_robe_skirt_spellcast");
    HOLDER().loadFromFile("../../images/player/spellcast/TORSO_chain_armor_jacket_purple.png", "body_chain_purple_spellcast");
    HOLDER().loadFromFile("../../images/player/spellcast/TORSO_chain_armor_torso.png", "body_chain_spellcast");
    HOLDER().loadFromFile("../../images/player/spellcast/TORSO_leather_armor_bracers.png", "body_leather_bracers_spellcast");
    HOLDER().loadFromFile("../../images/player/spellcast/TORSO_leather_armor_shirt_white.png", "body_leather_shirt_spellcast");
    HOLDER().loadFromFile("../../images/player/spellcast/TORSO_leather_armor_shoulders.png", "body_leather_shoulders_spellcast");
    HOLDER().loadFromFile("../../images/player/spellcast/TORSO_leather_armor_torso.png", "body_leather_spellcast");
    HOLDER().loadFromFile("../../images/player/spellcast/TORSO_plate_armor_arms_shoulders.png", "body_plate_shoulders_spellcast");
    HOLDER().loadFromFile("../../images/player/spellcast/TORSO_plate_armor_torso.png", "body_plate_spellcast");
    HOLDER().loadFromFile("../../images/player/spellcast/TORSO_robe_shirt_brown.png", "body_robe_spellcast");
                                                                                                                                 // SLASH
    HOLDER().loadFromFile("../../images/player/slash/FEET_plate_armor_shoes.png", "boots_plate_slash");
    HOLDER().loadFromFile("../../images/player/slash/FEET_shoes_brown.png", "boots_brown_slash");
    HOLDER().loadFromFile("../../images/player/slash/HANDS_plate_armor_gloves.png", "gauntlets_plate_slash");
    HOLDER().loadFromFile("../../images/player/slash/HEAD_chain_armor_helmet.png", "head_chain_helmet_slash");
    HOLDER().loadFromFile("../../images/player/slash/HEAD_chain_armor_hood.png", "head_chain_hood_slash");
    HOLDER().loadFromFile("../../images/player/slash/HEAD_leather_armor_hat.png", "head_leather_hat_slash");
    HOLDER().loadFromFile("../../images/player/slash/HEAD_plate_armor_helmet.png", "head_plate_slash");
    HOLDER().loadFromFile("../../images/player/slash/HEAD_robe_hood.png", "head_robe_hood_slash");
    HOLDER().loadFromFile("../../images/player/slash/LEGS_pants_greenish.png", "pants_green_slash");
    HOLDER().loadFromFile("../../images/player/slash/LEGS_plate_armor_pants.png", "pants_plate_slash");
    HOLDER().loadFromFile("../../images/player/slash/LEGS_robe_skirt.png", "pants_robe_skirt_slash");
    HOLDER().loadFromFile("../../images/player/slash/TORSO_chain_armor_jacket_purple.png", "body_chain_purple_slash");
    HOLDER().loadFromFile("../../images/player/slash/TORSO_chain_armor_torso.png", "body_chain_slash");
    HOLDER().loadFromFile("../../images/player/slash/TORSO_leather_armor_bracers.png", "body_leather_bracers_slash");
    HOLDER().loadFromFile("../../images/player/slash/TORSO_leather_armor_shirt_white.png", "body_leather_shirt_slash");
    HOLDER().loadFromFile("../../images/player/slash/TORSO_leather_armor_shoulders.png", "body_leather_shoulders_slash");
    HOLDER().loadFromFile("../../images/player/slash/TORSO_leather_armor_torso.png", "body_leather_slash");
    HOLDER().loadFromFile("../../images/player/slash/TORSO_plate_armor_arms_shoulders.png", "body_plate_shoulders_slash");
    HOLDER().loadFromFile("../../images/player/slash/TORSO_plate_armor_torso.png", "body_plate_slash");
    HOLDER().loadFromFile("../../images/player/slash/TORSO_robe_shirt_brown.png", "body_robe_slash");
                                                                                                                                 // HURT
    HOLDER().loadFromFile("../../images/player/hurt/FEET_plate_armor_shoes.png", "boots_plate_hurt");
    HOLDER().loadFromFile("../../images/player/hurt/FEET_shoes_brown.png", "boots_brown_hurt");
    HOLDER().loadFromFile("../../images/player/hurt/HANDS_plate_armor_gloves.png", "gauntlets_plate_hurt");
    HOLDER().loadFromFile("../../images/player/hurt/HEAD_chain_armor_helmet.png", "head_chain_helmet_hurt");
    HOLDER().loadFromFile("../../images/player/hurt/HEAD_chain_armor_hood.png", "head_chain_hood_hurt");
    HOLDER().loadFromFile("../../images/player/hurt/HEAD_leather_armor_hat.png", "head_leather_hat_hurt");
    HOLDER().loadFromFile("../../images/player/hurt/HEAD_plate_armor_helmet.png", "head_plate_hurt");
    HOLDER().loadFromFile("../../images/player/hurt/HEAD_robe_hood.png", "head_robe_hood_hurt");
    HOLDER().loadFromFile("../../images/player/hurt/LEGS_pants_greenish.png", "pants_green_hurt");
    HOLDER().loadFromFile("../../images/player/hurt/LEGS_plate_armor_pants.png", "pants_plate_hurt");
    HOLDER().loadFromFile("../../images/player/hurt/LEGS_robe_skirt.png", "pants_robe_skirt_hurt");
    HOLDER().loadFromFile("../../images/player/hurt/TORSO_chain_armor_jacket_purple.png", "body_chain_purple_hurt");
    HOLDER().loadFromFile("../../images/player/hurt/TORSO_chain_armor_torso.png", "body_chain_hurt");
    HOLDER().loadFromFile("../../images/player/hurt/TORSO_leather_armor_bracers.png", "body_leather_bracers_hurt");
    HOLDER().loadFromFile("../../images/player/hurt/TORSO_leather_armor_shirt_white.png", "body_leather_shirt_hurt");
    HOLDER().loadFromFile("../../images/player/hurt/TORSO_leather_armor_shoulders.png", "body_leather_shoulders_hurt");
    HOLDER().loadFromFile("../../images/player/hurt/TORSO_leather_armor_torso.png", "body_leather_hurt");
    HOLDER().loadFromFile("../../images/player/hurt/TORSO_plate_armor_arms_shoulders.png", "body_plate_shoulders_hurt");
    HOLDER().loadFromFile("../../images/player/hurt/TORSO_plate_armor_torso.png", "body_plate_hurt");
    HOLDER().loadFromFile("../../images/player/hurt/TORSO_robe_shirt_brown.png", "body_robe_hurt");
                                                                                                                                 // BOW
    HOLDER().loadFromFile("../../images/player/bow/FEET_plate_armor_shoes.png", "boots_plate_bow");
    HOLDER().loadFromFile("../../images/player/bow/FEET_shoes_brown.png", "boots_brown_bow");
    HOLDER().loadFromFile("../../images/player/bow/HANDS_plate_armor_gloves.png", "gauntlets_plate_bow");
    HOLDER().loadFromFile("../../images/player/bow/HEAD_chain_armor_helmet.png", "head_chain_helmet_bow");
    HOLDER().loadFromFile("../../images/player/bow/HEAD_chain_armor_hood.png", "head_chain_hood_bow");
    HOLDER().loadFromFile("../../images/player/bow/HEAD_leather_armor_hat.png", "head_leather_hat_bow");
    HOLDER().loadFromFile("../../images/player/bow/HEAD_plate_armor_helmet.png", "head_plate_bow");
    HOLDER().loadFromFile("../../images/player/bow/HEAD_robe_hood.png", "head_robe_hood_bow");
    HOLDER().loadFromFile("../../images/player/bow/LEGS_pants_greenish.png", "pants_green_bow");
    HOLDER().loadFromFile("../../images/player/bow/LEGS_plate_armor_pants.png", "pants_plate_bow");
    HOLDER().loadFromFile("../../images/player/bow/LEGS_robe_skirt.png", "pants_robe_skirt_bow");
    HOLDER().loadFromFile("../../images/player/bow/TORSO_chain_armor_jacket_purple.png", "body_chain_purple_bow");
    HOLDER().loadFromFile("../../images/player/bow/TORSO_chain_armor_torso.png", "body_chain_bow");
    HOLDER().loadFromFile("../../images/player/bow/TORSO_leather_armor_bracers.png", "body_leather_bracers_bow");
    HOLDER().loadFromFile("../../images/player/bow/TORSO_leather_armor_shirt_white.png", "body_leather_shirt_bow");
    HOLDER().loadFromFile("../../images/player/bow/TORSO_leather_armor_shoulders.png", "body_leather_shoulders_bow");
    HOLDER().loadFromFile("../../images/player/bow/TORSO_leather_armor_torso.png", "body_leather_bow");
    HOLDER().loadFromFile("../../images/player/bow/TORSO_plate_armor_arms_shoulders.png", "body_plate_shoulders_bow");
    HOLDER().loadFromFile("../../images/player/bow/TORSO_plate_armor_torso.png", "body_plate_bow");
    HOLDER().loadFromFile("../../images/player/bow/TORSO_robe_shirt_brown.png", "body_robe_bow");

    // weapons ////////////////////////////////////////////////////////////////////////////////////
    HOLDER().loadFromFile("../../images/player/thrust/WEAPON_spear.png", "thrust_spear");
    HOLDER().loadFromFile("../../images/player/thrust/player_weapons/192x192/new/left_hand_spear_male.png", "universal_spear");
    HOLDER().loadFromFile("../../images/player/thrust/WEAPON_staff.png", "thrust_staff");
    HOLDER().loadFromFile("../../images/player/thrust/WEAPON_shield_cutout_body.png", "thrust_shield");
    HOLDER().loadFromFile("../../images/player/thrust/WEAPON_shield_cutout_chain_armor_helmet.png", "thrust_shield2");
    HOLDER().loadFromFile("../../images/player/walkcycle/WEAPON_shield_cutout_body.png", "walk_shield");
    HOLDER().loadFromFile("../../images/player/walkcycle/WEAPON_shield_cutout_chain_armor_helmet.png", "walk_shield2");

    // additional for creatures ///////////////////////////////////////////////////////////////////
    HOLDER().loadFromFile("../../images/player/thrust/BELT_leather.png", "thrust_belt_leather");
    HOLDER().loadFromFile("../../images/player/thrust/BELT_rope.png", "thrust_belt_rope");
    HOLDER().loadFromFile("../../images/player/thrust/BEHIND_quiver.png", "thrust_quiver");
    HOLDER().loadFromFile("../../images/player/thrust/HEAD_hair_blonde.png", "trhust_hair_blonde");

// TERRAIN AND FEATURES ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
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




}
