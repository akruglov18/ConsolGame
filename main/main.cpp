#include "cursor.h"
#include "game.h"
#include "gameover_menu.h"
#include "inventory_menu.h"
#include "main_menu.h"
#include "map_menu.h"
#include "pause_menu.h"
#include "screen.h"
#include "settings_menu.h"
#include "skills_menu.h"
#include "trade_menu.h"

int main() {
    std::shared_ptr<sf::RenderWindow> window(new sf::RenderWindow{sf::VideoMode(1280, 720), "Application"});
    window->setMouseCursorVisible(false);

    /////////////////////////////////////////////////////////////TIME_CHECK///////////////////////////////////////////////////////////
    auto start = std::chrono::high_resolution_clock::now();
    Resources::TexturesHolder::load();
    Resources::FontsHolder::load();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Resources loading: " << std::setw(9) << diff.count() << " s\n";
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Cursor::init();

    std::map<View_mode, Screen*> screens;
    View_mode screen = View_mode::MAIN_MENU;
    MainMenu main_menu;
    PauseMenu pause_menu;
    SkillsMenu skills_menu;
    GameSettings settings;
    SettingsMenu stettings_menu(settings);
    GameoverMenu gameover_menu;
    MapMenu map_menu;
    InventoryMenu inventory_menu;
    TradeMenu trade_menu;
    screens[View_mode::MAIN_MENU] = &main_menu;
    screens[View_mode::PAUSE_MENU] = &pause_menu;
    screens[View_mode::SKILLS_MENU] = &skills_menu;
    screens[View_mode::SETTINGS_MENU] = &stettings_menu;
    screens[View_mode::GAMEOVER_MENU] = &gameover_menu;
    screens[View_mode::MAP_MENU] = &map_menu;
    screens[View_mode::INVENTORY_MENU] = &inventory_menu;
    screens[View_mode::TRADE_MENU] = &trade_menu;
    while (screen != View_mode::EXIT) {
        if (screen != View_mode::GAME)
            screen = screens[screen]->Run(*window);
        else {
            Game game(window.get(), settings);
            while (screen != View_mode::MAIN_MENU && screen != View_mode::EXIT) {
                screen = game.game_loop();

                if (screen == View_mode::EXIT)
                    break;

                switch (screen) {
                case View_mode::SKILLS_MENU:
                    screen = screens[screen]->Run(*window, game.get_player().get());
                    break;
                case View_mode::GAMEOVER_MENU:
                case View_mode::INVENTORY_MENU:
                case View_mode::MAP_MENU:
                case View_mode::PAUSE_MENU:
                case View_mode::TRADE_MENU:
                    screen = screens[screen]->Run(*window);
                    break;
                default:
                    throw std::invalid_argument("Wrong screen");
                    break;
                }

                if (game.get_player()->dead && screen == View_mode::GAME)
                    break;
            }
        }
    }

    return EXIT_SUCCESS;
}
