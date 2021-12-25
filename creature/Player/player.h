#pragma once
#include "creature.h"

class Player : public Creature {
private:

    // Personal characteristics which will be available in another class of CHARACTER
    // There it's only about graphics and render on screen
    //int _experience;
    //int _strength;		// How much damage will player inflict
    //int _persuasion;		// How profitable will player buy and sell
    //int _intelligence;	// How many experience will player recieve
    //int _flair;			// How well will player detect enemies
    //int _dexterity;		// How long can player run and figth without tireness, high level allows to wear heavy armor

    /*sf::Texture* _head;
    sf::Texture* _torso;
    sf::Texture* _legs;
    sf::Texture* _feet;
    sf::Texture* _hands;

    sf::Sprite _sprite_head;
    sf::Sprite _sprite_torso;
    sf::Sprite _sprite_legs;
    sf::Sprite _sprite_feet;
    sf::Sprite _sprite_hands;*/

public:
    Player(const sf::Texture* texture, CreatureManager& manager);
};

