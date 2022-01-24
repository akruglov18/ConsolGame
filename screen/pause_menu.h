#pragma once
#include "screen.h"

class pause_menu : public screen {
public:
	pause_menu();
	sf::Color _color;
	sf::Text _pause_text;
	sf::Texture pause_screenIMG;
	sf::Sprite pause_screen;

	button b_to_game;
	button b_main_menu;

	std::vector<button*> buttons;

	virtual View_mode Run(sf::RenderWindow& window) override;
};