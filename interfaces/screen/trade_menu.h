#pragma once
#include "inventory.h"
#include "inventory_menu.h"
#include "menu_button.h"
#include "screen.h"

class TradeMenu : public Screen {
public:
    TradeMenu();
    sf::Color color;
    sf::Texture inventory_screenIMG;
    sf::Sprite inventory_screen;

    MenuButton b_exit;
    std::vector<MenuButton*> buttons;
    static inline GraphicInventoryCopy gr_inventory_trader;
    static inline sf::Text gr_money_trader;
    static inline std::shared_ptr<GraphicInventoryRef> gr_inventory_player;
    static inline std::shared_ptr<sf::Text> gr_money_player;

    virtual View_mode Run(sf::RenderWindow& window) override;
    static void bind(std::shared_ptr<GraphicInventoryRef> _gr_inventory_player,
                     std::shared_ptr<sf::Text> _gr_money_player);
    static void update_graphic_inventories(const std::vector<std::shared_ptr<Slot>>& _gr_inventory_player,
                                           const std::vector<std::shared_ptr<Slot>>& _gr_inventory_trader,
                                           std::size_t _money_player, std::size_t _money_trader);

private:
    void show_inventories(sf::RenderWindow& window);
};
