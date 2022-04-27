#include "inventory_menu.h"

void GraphicSlot::show_slot(sf::RenderWindow& window) {
    window.draw(slot_sprite);
    //window.draw(slot->get_item()->get_sprite());
}

InventoryMenu::InventoryMenu(): b_exit("Back", sf::FloatRect({20.f, 20.f}, {150.f, 52.f}), View_mode::GAME) {
    color = sf::Color(240, 164, 99);
    buttons.push_back(&b_exit);
}

void InventoryMenu::build_inventory(std::vector<std::shared_ptr<Slot>>& items) {

    for (int i = 0; i < items.size(); ++i) {
        gr_items_array.push_back(std::make_shared<GraphicSlot>(GraphicSlot()));
    }

    size_t width = static_cast<size_t>(std::sqrt(items.size()));
    size_t height = static_cast<size_t>(std::sqrt(items.size()));
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {

            int x = 0;
            int y = 0;
            int w = 0;
            int h = 0;
            if (i == 0 && j == 0) {
                x = 190;
                y = 292;
                w = h = 38;
            } else if (j == 0 && i != height - 1) {
                x = 190;
                y = 331;
                w = 38;
                h = 36;
            } else if (j == 0 && i == height - 1) {
                x = 190;
                y = 368;
                w = h = 38;
            } else if (i == 0 && j != width - 1) {
                x = 229;
                y = 292;
                w = 36;
                h = 38;
            } else if (i == 0 && j == width - 1) {
                x = 266;
                y = 292;
                w = h = 38;
            } else if (j == width - 1 && i != height - 1) {
                x = 266;
                y = 331;
                w = 38;
                h = 36;
            } else if (i == height - 1 && j == width - 1) {
                x = 266;
                y = 368;
                w = h = 38;
            } else if (i == height - 1 && j != width - 1) {
                x = 229;
                y = 368;
                w = 36;
                h = 38;
            } else {
                x = 229;
                y = 331;
                w = h = 36;
            }

            int offset_x = 0;
            int offset_y = 0;
            if (j >= 2)
                offset_x = static_cast<int>(j - 1) * 4;
            if (i >= 2)
                offset_y = static_cast<int>(i - 1) * 4;

            auto& slot = gr_items_array[i * width + j];
            slot->slot = items[i * width + j];
            slot->slot_sprite.setTexture(*Resources::TexturesHolder::getResource("main_ui"));
            slot->slot_sprite.setTextureRect({{x, y}, {w, h}});
            slot->slot_sprite.setPosition({(j * 76.f) - offset_x + 400.f, (i * 76.f) - offset_y + 100.f});
            slot->slot_sprite.setScale({2.f, 2.f});
        }
    }
}

void InventoryMenu::update_graphic_inventory() {
    /*for (int i = 0; i < items_array.max_size(); i++) {
        gr_items_array[i].slot = items_array[i];
    }*/
}

void InventoryMenu::show_inventory(sf::RenderWindow& window) {
    for (auto& el : gr_items_array)
        el->show_slot(window);
}

View_mode InventoryMenu::Run(sf::RenderWindow& window, std::shared_ptr<Player> player) {
    sf::Event event{sf::Event::EventType::GainedFocus};
    View_mode to_return{View_mode::NONE};
    window.setView(window.getDefaultView());
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

        window.clear(color);
        b_exit.print_button(window);
        show_inventory(window);
        window.display();
    }
}

