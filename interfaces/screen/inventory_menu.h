#pragma once
#include "menu_button.h"
#include "screen.h"
#include "inventory.h"

class GraphicSlot {
public:
    std::shared_ptr<Slot> slot;
    sf::Text gr_amount;
    sf::Sprite slot_sprite;

    bool gr_amount_offset = false;
    void show_slot(sf::RenderWindow& window);
};

class InventoryMenu : public Screen {
public:
    InventoryMenu();
    sf::Color color;
    sf::Texture inventory_screenIMG;
    sf::Sprite inventory_screen;

    MenuButton b_exit;
    std::vector<MenuButton*> buttons;
    static inline std::vector<std::shared_ptr<GraphicSlot>> gr_items_array;
    static inline sf::Text gr_money;

    virtual View_mode Run(sf::RenderWindow& window, std::shared_ptr<Player> player = nullptr) override;
    static void build_inventory(const std::vector<std::shared_ptr<Slot>>& items);
    static void update_graphic_inventory(const std::vector<std::shared_ptr<Slot>>& items_array, int _money);

private:
    void show_inventory(sf::RenderWindow& window);
};
