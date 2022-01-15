#include "DesertTile.h"

Desert_sand::Desert_sand(sf::Sprite& _sprite) : Tile(_sprite) {
	passability = 2;
}

Desert_borders::Desert_borders(sf::Sprite& _sprite) : Tile(_sprite) {
	passability = 0;
	border = true;
}

Desert_cracks::Desert_cracks(sf::Sprite& _sprite) : Tile(_sprite) {
	passability = 2;
}