#pragma once
#include "creature.h"
#include "../player/player.h"
#include "action.h"
#include "items.h"
#include "common_thing.h"

class TradeRequest {
public:
    TradeRequest();
    void show(sf::RenderWindow& window, sf::Vector2f& pos);

private:
    sf::Sprite request_spriteL;
    sf::Sprite request_spriteM;
    sf::Sprite request_spriteR;
    sf::Text request_text;
    void place_request(sf::Vector2f& pos);
};

class Trader : public Creature {
public:
    Trader(CreatureManager& manager, float health, const sf::Vector2f& pos, std::mt19937& gen);
    void action(float time, Player* player);
    void show_request(sf::RenderWindow& window);

    bool request_available = false;
    Inventory inventory;

private:
    TradeRequest request;
    void fill_inventory(std::mt19937& gen);
};
