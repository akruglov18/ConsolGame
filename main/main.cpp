#pragma once
#include "game.h"
#include "screen.h"
#include "main_menu.h"
#include "pause_menu.h"
#include "skills_menu.h"
#include "settings_menu.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

int main() {
	std::shared_ptr<sf::RenderWindow> window(new sf::RenderWindow{ sf::VideoMode(1280, 720), "Application" });
	std::map<View_mode, screen*> screens;
	View_mode screen = View_mode::MAIN_MENU;

	/////////////////////////////////////////////////////////////TIME_CHECK///////////////////////////////////////////////////////////
	auto start = std::chrono::high_resolution_clock::now();
	HOLDER().load_textures();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout << "Textures loading: " << std::setw(9) << diff.count() << " s\n";
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	main_menu m_menu;
	pause_menu p_menu;
	skills_menu sk_menu;
	settings_menu st_menu;
	screens[View_mode::MAIN_MENU] = &m_menu;
	screens[View_mode::PAUSE_MENU] = &p_menu;
	screens[View_mode::SKILLS_MENU] = &sk_menu;
	screens[View_mode::SETTINGS_MENU] = &st_menu;

	while (screen != View_mode::EXIT) {
		screen = screens[screen]->Run(*window);
		if (screen == View_mode::GAME) {
			Game game(window.get());
			while (screen != View_mode::MAIN_MENU && screen != View_mode::EXIT) {
				screen = game.game_loop();
				if (screen == View_mode::EXIT)
					break;
				screen = screens[screen]->Run(*window);
			}
		}
	}

	return EXIT_SUCCESS;
}
