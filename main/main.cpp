#include "game.h"
#include "gameover_menu.h"
#include "main_menu.h"
#include "pause_menu.h"
#include "screen.h"
#include "settings_menu.h"
#include "skills_menu.h"

int main() {
    std::shared_ptr<sf::RenderWindow> window(new sf::RenderWindow{sf::VideoMode(1280, 720), "Application"});

    /////////////////////////////////////////////////////////////TIME_CHECK///////////////////////////////////////////////////////////
    auto start = std::chrono::high_resolution_clock::now();
    Resources::TexturesHolder::load();
    Resources::FontsHolder::load();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Textures loading: " << std::setw(9) << diff.count() << " s\n";
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    std::map<View_mode, screen*> screens;
    View_mode screen = View_mode::MAIN_MENU;
    main_menu m_menu;
    pause_menu p_menu;
    skills_menu sk_menu;
    settings_menu st_menu;
    gameover_menu gg_menu;
    screens[View_mode::MAIN_MENU] = &m_menu;
    screens[View_mode::PAUSE_MENU] = &p_menu;
    screens[View_mode::SKILLS_MENU] = &sk_menu;
    screens[View_mode::SETTINGS_MENU] = &st_menu;
    screens[View_mode::GAMEOVER_MENU] = &gg_menu;
    while (screen != View_mode::EXIT) {
        if (screen != View_mode::GAME)
            screen = screens[screen]->Run(*window);
        else {
            Game game(window.get());
            while (screen != View_mode::MAIN_MENU && screen != View_mode::EXIT) {
                screen = game.game_loop();
                if (screen == View_mode::EXIT) {
                    break;
                }

                screen = screens[screen]->Run(*window, game.get_player());
                if (game.get_player()->dead && screen == View_mode::GAME)
                    break;
            }
        }
    }

    return EXIT_SUCCESS;
}
