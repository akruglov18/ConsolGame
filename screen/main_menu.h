#pragma once
#include "screen.h"

class main_menu : public screen {
public:
	main_menu();
	sf::Color color;

	button b_play;
	button b_settings;
	button b_exit;

	std::vector<button*> buttons;

	virtual View_mode Run(sf::RenderWindow& window) override;
};
