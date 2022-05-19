#include "trade_menu.h"

TradeMenu::TradeMenu() : b_exit("Back", sf::FloatRect({20.f, 20.f}, {150.f, 52.f}), View_mode::GAME) {
    color = sf::Color(240, 164, 99);
    buttons.push_back(&b_exit);

    gr_money_player.setFont(font);
    gr_money_player.setCharacterSize(40);
    gr_money_player.setStyle(sf::Text::Bold);
    gr_money_player.setFillColor(sf::Color(39, 177, 19));
    gr_money_player.setPosition({300.f, 130.f});

    gr_money_trader.setFont(font);
    gr_money_trader.setCharacterSize(40);
    gr_money_trader.setStyle(sf::Text::Bold);
    gr_money_trader.setFillColor(sf::Color(39, 177, 19));
    gr_money_trader.setPosition({700.f, 130.f});
}

View_mode TradeMenu::Run(sf::RenderWindow& window) {
    inventory_screenIMG.loadFromFile("../../images/tmp_inventory.jpg");
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
            std::remove("../../images/tmp_inventory.jpg");
            return View_mode::EXIT;
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::T) {
                std::remove("../../images/tmp_inventory.jpg");
                return View_mode::GAME;
            }
        }

        to_return = MenuButton::buttons_checker(sf::Mouse::getPosition(window), buttons, event);
        if (to_return != View_mode::NONE)
            return to_return;

        window.clear(color);
        window.draw(inventory_screen);
        b_exit.print_button(window);
        show_inventories(window);
        Cursor::move(window);
        window.display();
        play_music();
    }
}

void TradeMenu::bind(const std::vector<std::shared_ptr<GraphicSlot>>& _items_array_player,
                     const sf::Text& _gr_money_player) {
    gr_items_array_player = _items_array_player;
    gr_money_player = _gr_money_player;
}

void TradeMenu::update_graphic_inventories(const std::vector<std::shared_ptr<Slot>>& items_array_player,
                                         const std::vector<std::shared_ptr<Slot>>& items_array_trader,
                                         int _money_player, int _money_trader) {
    for (std::size_t i = 0; i < items_array_player.size(); i++) {
        gr_items_array_player[i]->slot = items_array_player[i];
        if (gr_items_array_player[i]->slot->get_item() != nullptr) {
            float x = gr_items_array_player[i]->slot_sprite.getPosition().x + 16.f;
            float y = gr_items_array_player[i]->slot_sprite.getPosition().y + 16.f;
            gr_items_array_player[i]->slot->get_item()->get_sprite().setPosition({x, y});
            gr_items_array_player[i]->slot->get_item()->get_sprite().setScale({1.25f, 1.25f});
            gr_items_array_player[i]->gr_amount.setString(std::to_string(gr_items_array_player[i]->slot->get_amount()));
            if (gr_items_array_player[i]->slot->get_amount() >= 10 && !gr_items_array_player[i]->gr_amount_offset) {
                float x = gr_items_array_player[i]->gr_amount.getPosition().x - 6.f;
                float y = gr_items_array_player[i]->gr_amount.getPosition().y;
                gr_items_array_player[i]->gr_amount.setPosition(sf::Vector2f({x, y}));
                gr_items_array_player[i]->gr_amount_offset = true;
            }
        }
    }

    for (std::size_t i = 0; i < items_array_trader.size(); i++) {
        gr_items_array_trader[i]->slot = items_array_trader[i];
        if (gr_items_array_trader[i]->slot->get_item() != nullptr) {
            float x = gr_items_array_trader[i]->slot_sprite.getPosition().x + 16.f;
            float y = gr_items_array_trader[i]->slot_sprite.getPosition().y + 16.f;
            gr_items_array_trader[i]->slot->get_item()->get_sprite().setPosition({x, y});
            gr_items_array_trader[i]->slot->get_item()->get_sprite().setScale({1.25f, 1.25f});
            gr_items_array_trader[i]->gr_amount.setString(std::to_string(gr_items_array_trader[i]->slot->get_amount()));
            if (gr_items_array_trader[i]->slot->get_amount() >= 10 && !gr_items_array_trader[i]->gr_amount_offset) {
                float x = gr_items_array_trader[i]->gr_amount.getPosition().x - 6.f;
                float y = gr_items_array_trader[i]->gr_amount.getPosition().y;
                gr_items_array_trader[i]->gr_amount.setPosition(sf::Vector2f({x, y}));
                gr_items_array_trader[i]->gr_amount_offset = true;
            }
        }
    }

    gr_money_player.setString("$ " + std::to_string(_money_player));
    gr_money_trader.setString("$ " + std::to_string(_money_trader));
}

void TradeMenu::show_inventories(sf::RenderWindow& window) {
    for (auto& el : gr_items_array_player)
        el->show_slot(window);
    for (auto& el : gr_items_array_trader)
        el->show_slot(window);
    window.draw(gr_money_player);
    window.draw(gr_money_trader);
}
