#pragma once
#include "screen.h"

class BaseGraphicSlot {
public:
    sf::Sprite slot_sprite;
    sf::FloatRect pos;
    virtual void show_slot(sf::RenderWindow& window) = 0;
};

class GraphicSlot : public BaseGraphicSlot {
public:
    GraphicSlot(std::shared_ptr<Slot>& other);
    std::shared_ptr<Slot>& slot;
    sf::Text gr_amount;
    bool gr_amount_offset = false;
    void show_slot(sf::RenderWindow& window) override;
};

class PortativeGraphicSlot : public BaseGraphicSlot {
public:
    std::shared_ptr<Slot> slot;
    void show_slot(sf::RenderWindow& window) override;
};

class GraphicInventory {
public:
    std::vector<std::shared_ptr<GraphicSlot>> gr_items_array;
    sf::Vector2f pos;
    static constexpr std::size_t NONE_CHOSEN = std::numeric_limits<std::size_t>::max();
    static std::size_t chosen_one;
    void build_inventory(std::vector<std::shared_ptr<Slot>>& items, float x, float y);
    std::shared_ptr<GraphicSlot>& operator[](std::size_t index);
    void set_pos(float x, float y);
    std::size_t size() const {
        return gr_items_array.size();
    }
    static void check_move_objects(sf::Vector2i mouse_pos, std::vector<std::shared_ptr<GraphicSlot>>& gr_items_array);

private:
    static float click_offset_x;
    static float click_offset_y;
};
