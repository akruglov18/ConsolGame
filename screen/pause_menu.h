#pragma once
#include "screen.h"

class pause_menu : public screen {
public:
	pause_menu();
	sf::Color _color;
	virtual View_mode Run(sf::RenderWindow& window) override;
};