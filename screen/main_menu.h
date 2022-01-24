#pragma once
#include "screen.h"

class main_menu : public screen {
public:
	main_menu();
	sf::Color _color;
	virtual View_mode Run(sf::RenderWindow& window) override;
};