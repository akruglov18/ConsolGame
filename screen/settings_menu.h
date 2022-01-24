#pragma once
#include "screen.h"

class settings_menu : public screen {
public:
	settings_menu();
	sf::Color _color;

	button b_main_menu;

	std::vector<button*> buttons;

	virtual View_mode Run(sf::RenderWindow& window) override;
};