#pragma once
#include "inventory.h"
#include "menu_button.h"
#include "screen.h"
#include "inventory_menu.h"

class TradeMenu : public Screen {
public:
    TradeMenu();
    sf::Color color;
    sf::Texture inventory_screenIMG;
    sf::Sprite inventory_screen;

    MenuButton b_exit;
    std::vector<MenuButton*> buttons;
    static inline std::vector<std::shared_ptr<GraphicSlot>>& gr_items_array_player =
            std::vector<std::shared_ptr<GraphicSlot>>();
    static inline std::vector<std::shared_ptr<GraphicSlot>> gr_items_array_trader;
    static inline sf::Text& gr_money_player = sf::Text();
    static inline sf::Text gr_money_trader;

    virtual View_mode Run(sf::RenderWindow& window) override;
    static void build_trader_inventory();
    static void bind(const std::vector<std::shared_ptr<GraphicSlot>>& _items_array_player, const sf::Text& _gr_money_player);
    static void update_graphic_inventories(const std::vector<std::shared_ptr<Slot>>& items_array_player,
                                         const std::vector<std::shared_ptr<Slot>>& items_array_trader, 
                                         int _money_player, int _money_trader);

private:
    void show_inventories(sf::RenderWindow& window);
};
