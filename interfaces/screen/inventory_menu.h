#pragma once
#include "menu_button.h"
#include "screen.h"
#include "inventory.h"

class GraphicSlot {
public:
    std::shared_ptr<Slot> slot;
    sf::Text gr_amount;
    sf::Sprite slot_sprite;

    void show_slot(sf::RenderWindow& window);
};

class InventoryMenu : public Screen {
public:
    InventoryMenu();
    sf::Color color;

    MenuButton b_exit;
    std::vector<MenuButton*> buttons;
    static inline std::vector<std::shared_ptr<GraphicSlot>> gr_items_array;
    // static std::vector<std::shared_ptr<Slot>>& items_array;

    virtual View_mode Run(sf::RenderWindow& window, std::shared_ptr<Player> player = nullptr) override;
    static void build_inventory(std::vector<std::shared_ptr<Slot>>& items);
    static void update_graphic_inventory();

private:
    void show_inventory(sf::RenderWindow& window);
};