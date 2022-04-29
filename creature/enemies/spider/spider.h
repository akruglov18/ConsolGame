#include "../enemy.h"

class Spider : public Enemy {
public:
    Spider(CreatureManager& manager, float health = 100.f, const sf::Vector2f& pos = {500, 500});
};
