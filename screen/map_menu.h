#pragma once
#include "screen.h"

class map_menu : public screen {
public:
	map_menu();
	sf::Color _color;
	virtual View_mode Run(sf::RenderWindow& window) override;
};