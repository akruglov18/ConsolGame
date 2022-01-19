#pragma once
#include "game.h"
#include "menu.h"

int main() {
    sf::RenderWindow window{ sf::VideoMode(1280, 720), "Consol game" };
    Menu main_menu(&window);

    while (true) {
        View_mode mode = main_menu.menu_loop();

        switch (mode) {
            case(View_mode::EXIT):
                window.close();
                return 0;
            case(View_mode::GAME):
                Game game(&window);
                mode = game.game_loop();
                switch (mode) {
                    case(View_mode::EXIT):
                        window.close();
                        return 0;
                    case(View_mode::MAIN_MENU):
                        break;
                    //case(View_mode::PAUSE_MENU): break;
                    //case(View_mode::SETTINGS_MENU): break;
                }
        }
    }

    return 0;
}