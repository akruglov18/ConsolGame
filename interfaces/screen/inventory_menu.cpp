#include "inventory_menu.h"

InventoryMenu::InventoryMenu(): b_exit("Back", sf::FloatRect({20.f, 20.f}, {150.f, 52.f}), View_mode::GAME) {
    color = sf::Color(240, 164, 99);
    buttons.push_back(&b_exit);

    gr_inventory = std::shared_ptr<GraphicInventoryRef>(new GraphicInventoryRef());
    gr_inventory_bar = std::shared_ptr<GraphicInventoryBar>(new GraphicInventoryBar());
    gr_united_inventory = std::shared_ptr<GraphicInventoryRef>(new GraphicInventoryRef());
    gr_money = std::shared_ptr<sf::Text>(new sf::Text());
    gr_money->setFont(font);
    gr_money->setCharacterSize(40);
    gr_money->setStyle(sf::Text::Bold);
    gr_money->setFillColor(sf::Color(39, 177, 19));
    gr_money->setPosition({500.f, 130.f});
}

void InventoryMenu::update_graphic_inventory(const std::vector<std::shared_ptr<Slot>>& items_array,
                                             std::size_t _money) {
    gr_inventory->set_pos(500.f, 200.f);
    gr_money->setPosition({500.f, 130.f});
    for (std::size_t i = 0; i < items_array.size() - Inventory::bar_size; i++) {
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

    gr_inventory_bar->inventory_menu_scale();
    gr_inventory_bar->set_pos(424.f, 636.f);
    gr_money->setString("$ " + std::to_string(_money));
}

void InventoryMenu::show_inventory(sf::RenderWindow& window) {
    window.draw(*gr_money);
    gr_inventory->show(window);
    gr_inventory_bar->show(window);
    if (BaseGraphicInventory::chosen_one != BaseGraphicInventory::NONE_CHOSEN) {
        gr_united_inventory->gr_items_array[BaseGraphicInventory::chosen_one]->show_slot(window, true);
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

        to_return = MenuButton::buttons_checker(sf::Mouse::getPosition(window), buttons, event);

        if (event.type == sf::Event::Closed) {
            std::remove("../../images/tmp.jpg");
            to_return = View_mode::EXIT;
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::E) {
                std::remove("../../images/tmp.jpg");
                to_return = View_mode::GAME;
            }
        }

        if (to_return != View_mode::NONE) {
            gr_inventory_bar->in_game_scale();
            gr_inventory_bar->set_pos(480.f, 648.f);
            return to_return;
        }

        GraphicInventoryRef::check_move_objects(sf::Mouse::getPosition(window), gr_united_inventory->gr_items_array);

        window.clear(color);
        window.draw(inventory_screen);
        b_exit.print_button(window);
        show_inventory(window);
        Cursor::move(window);
        window.display();
        play_music();
    }
}
