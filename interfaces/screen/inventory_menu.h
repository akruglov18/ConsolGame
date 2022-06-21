#pragma once
#include "graphic_inventory.h"
#include "inventory.h"
#include "menu_button.h"
#include "screen.h"

class InventoryMenu : public Screen {
public:
    InventoryMenu();
    sf::Color color;
    sf::Texture inventory_screenIMG;
    sf::Sprite inventory_screen;

    MenuButton b_exit;
    std::vector<MenuButton*> buttons;
    static inline std::shared_ptr<GraphicInventoryRef> gr_inventory;
    static inline std::shared_ptr<GraphicInventoryBar> gr_inventory_bar;
    static inline std::shared_ptr<GraphicInventoryRef> gr_united_inventory;
    static inline std::shared_ptr<sf::Text> gr_money;

    virtual View_mode Run(sf::RenderWindow& window) override;
    static void update_graphic_inventory(const std::vector<std::shared_ptr<Slot>>& items_array, std::size_t _money);

private:
    void show_inventory(sf::RenderWindow& window);
};
