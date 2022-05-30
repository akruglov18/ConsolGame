#include "inventory_menu.h"

InventoryMenu::InventoryMenu(): b_exit("Back", sf::FloatRect({20.f, 20.f}, {150.f, 52.f}), View_mode::GAME) {
    color = sf::Color(240, 164, 99);
    buttons.push_back(&b_exit);

    gr_inventory = std::shared_ptr<GraphicInventory>(new GraphicInventory());
    gr_money = std::shared_ptr<sf::Text>(new sf::Text());
    gr_money->setFont(font);
    gr_money->setCharacterSize(40);
    gr_money->setStyle(sf::Text::Bold);
    gr_money->setFillColor(sf::Color(39, 177, 19));
    gr_money->setPosition({500.f, 130.f});
}

void InventoryMenu::update_graphic_inventory(const std::vector<std::shared_ptr<Slot>>& items_array, int _money) {
    gr_inventory->set_pos(500.f, 200.f);
    gr_money->setPosition({500.f, 130.f});

    for (std::size_t i = 0; i < items_array.size(); i++) {
        (*gr_inventory)[i]->slot = items_array[i];
        if ((*gr_inventory)[i]->slot->get_item() != nullptr) {
            float x, y;
            if ((*gr_inventory)[i]->slot->get_item()->get_type() == ItemType::WEAPON) {
                x = (*gr_inventory)[i]->slot_sprite.getPosition().x;
                y = (*gr_inventory)[i]->slot_sprite.getPosition().y;
            } else {
                x = (*gr_inventory)[i]->slot_sprite.getPosition().x + 16.f;
                y = (*gr_inventory)[i]->slot_sprite.getPosition().y + 16.f;
            }
            (*gr_inventory)[i]->slot->get_item()->get_icon().setPosition({x, y});
            (*gr_inventory)[i]->slot->get_item()->get_icon().setScale({1.25f, 1.25f});
            (*gr_inventory)[i]->gr_amount.setString(std::to_string((*gr_inventory)[i]->slot->get_amount()));
            if ((*gr_inventory)[i]->slot->get_amount() >= 10 && !(*gr_inventory)[i]->gr_amount_offset) {
                x = (*gr_inventory)[i]->gr_amount.getPosition().x - 6.f;
                y = (*gr_inventory)[i]->gr_amount.getPosition().y;
                (*gr_inventory)[i]->gr_amount.setPosition(sf::Vector2f({x, y}));
                (*gr_inventory)[i]->gr_amount_offset = true;
            }
        }
    }
    gr_money->setString("$ " + std::to_string(_money));
}

void InventoryMenu::show_inventory(sf::RenderWindow& window) {
    for (auto& el : gr_inventory->gr_items_array)
        el->show_slot(window);
    window.draw(*gr_money);
    if (GraphicInventory::chosen_one != LLONG_MAX) {
        gr_inventory->gr_items_array[GraphicInventory::chosen_one]->show_slot(window);
    }
}

View_mode InventoryMenu::Run(sf::RenderWindow& window) {
    inventory_screenIMG.loadFromFile("../../images/tmp.jpg");
    inventory_screen.setTexture(inventory_screenIMG);
    inventory_screen.setColor(sf::Color(210, 164, 120, 130));

    sf::Event event;
    window.pollEvent(event);
    event.type = sf::Event::GainedFocus;
    View_mode to_return{View_mode::NONE};
    window.setView(window.getDefaultView());
    while (true) {
        window.pollEvent(event);

        if (event.type == sf::Event::Closed) {
            std::remove("../../images/tmp.jpg");
            return View_mode::EXIT;
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::E) {
                std::remove("../../images/tmp.jpg");
                return View_mode::GAME;
            }
        }

        to_return = MenuButton::buttons_checker(sf::Mouse::getPosition(window), buttons, event);
        if (to_return != View_mode::NONE)
            return to_return;

        GraphicInventory::check_move_objects(sf::Mouse::getPosition(window), gr_inventory->gr_items_array);

        window.clear(color);
        window.draw(inventory_screen);
        b_exit.print_button(window);
        show_inventory(window);
        Cursor::move(window);
        window.display();
        play_music();
    }
}
