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

class GraphicInventory {
public:
    std::vector<std::shared_ptr<GraphicSlot>> gr_items_array;
    sf::Vector2f pos;
    void build_inventory(const std::vector<std::shared_ptr<Slot>>& items, float x, float y);
    std::shared_ptr<GraphicSlot>& operator[](std::size_t index);
    void set_pos(float x, float y);
    std::size_t size() const {
        return gr_items_array.size();
    }
};

class InventoryMenu : public Screen {
public:
    InventoryMenu();
    sf::Color color;
    sf::Texture inventory_screenIMG;
    sf::Sprite inventory_screen;

    MenuButton b_exit;
    std::vector<MenuButton*> buttons;
    static inline GraphicInventory gr_inventory;
    static inline sf::Text gr_money;

    virtual View_mode Run(sf::RenderWindow& window) override;
    static void update_graphic_inventory(const std::vector<std::shared_ptr<Slot>>& items_array, int _money);

private:
    void show_inventory(sf::RenderWindow& window);
};
