#pragma once
#include "game.h"
#include "screen.h"
#include "main_menu.h"
#include "pause_menu.h"
#include "skills_menu.h"

int main() {
	sf::RenderWindow window{ sf::VideoMode(1280, 720), "Application" };
	std::map<View_mode, screen*> screens;
	View_mode screen = View_mode::MAIN_MENU;

	main_menu m_menu;
	pause_menu p_menu;
	skills_menu sk_menu;
	screens[View_mode::MAIN_MENU] = &m_menu;
	screens[View_mode::PAUSE_MENU] = &p_menu;
	screens[View_mode::SKILLS_MENU] = &sk_menu;

	while (screen != View_mode::EXIT) {
		screen = screens[screen]->Run(window);
		if (screen == View_mode::GAME) {
			Game game(&window);
			while (screen != View_mode::MAIN_MENU) {
				screen = game.game_loop();
				if (screen == View_mode::EXIT)
					break;
				screen = screens[screen]->Run(window);
			}
		}
	}

	return EXIT_SUCCESS;
}
