#include "../enemy.h"

class Spider : public Enemy {
public:
    Spider(CreatureManager& manager, int health, const sf::Vector2f& pos);
};
