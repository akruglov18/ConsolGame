#pragma once
#include "screen.h"

#define NONE_CHOSEN 9223372036854775807

class GraphicSlot {
public:
    std::shared_ptr<Slot> slot;
    sf::Text gr_amount;
    sf::Sprite slot_sprite;
    sf::FloatRect pos;
    bool gr_amount_offset = false;
    void show_slot(sf::RenderWindow& window);
};

class GraphicInventory {
public:
    std::vector<std::shared_ptr<GraphicSlot>> gr_items_array;
    sf::Vector2f pos;
    static std::size_t chosen_one;
    void build_inventory(const std::vector<std::shared_ptr<Slot>>& items, float x, float y);
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
