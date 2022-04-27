#include "inventory_menu.h"

InventoryMenu::InventoryMenu(): b_exit("Back", sf::FloatRect({20.f, 20.f}, {150.f, 52.f}), View_mode::GAME) {
    color = sf::Color(240, 164, 99);
    buttons.push_back(&b_exit);
}

void InventoryMenu::bind_inventory(std::vector<std::shared_ptr<Slot>>& items) {
    for (int i = 0; i < items.size() / 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            
        }
    }
    /*items_array = */items;
}

void InventoryMenu::update_graphic_inventory() {
    /*for (int i = 0; i < items_array.max_size(); i++) {
        gr_items_array[i].slot = items_array[i];
    }*/
}

View_mode InventoryMenu::Run(sf::RenderWindow& window, std::shared_ptr<Player> player) {
    sf::Event event{sf::Event::EventType::GainedFocus};
    View_mode to_return{View_mode::NONE};
    while (true) {
        window.pollEvent(event);

        if (event.type == sf::Event::Closed)
            return View_mode::EXIT;
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::E)
                return View_mode::GAME;
        }

        to_return = MenuButton::buttons_checker(sf::Mouse::getPosition(window), buttons, event);
        if (to_return != View_mode::NONE)
            return to_return;

        window.setView(window.getDefaultView());
        window.clear(color);
        b_exit.print_button(window);
        window.display();
    }
}
