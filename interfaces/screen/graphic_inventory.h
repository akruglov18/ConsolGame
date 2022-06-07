#pragma once
#include "screen.h"

class BaseGraphicSlot {
public:
    sf::Sprite slot_sprite;
    sf::FloatRect pos;
    sf::Text gr_amount;
    bool gr_amount_offset = false;
    virtual void show_slot(sf::RenderWindow& window) = 0;
};

class GraphicSlotRef : public BaseGraphicSlot {
public:
    GraphicSlotRef(std::shared_ptr<Slot>& other);
    std::shared_ptr<Slot>& slot;
    void show_slot(sf::RenderWindow& window) override;
};

class GraphicSlotCopy : public BaseGraphicSlot {
public:
    GraphicSlotCopy(){};
    std::shared_ptr<Slot> slot;
    void show_slot(sf::RenderWindow& window) override;
};

// INVENTORIES ////////////////////////////////////////////////////////////////////////////////////

class BaseGraphicInventory {
public:
    sf::Vector2f pos;
    static constexpr std::size_t NONE_CHOSEN = std::numeric_limits<std::size_t>::max();
    static std::size_t chosen_one;
    virtual void build_inventory(std::vector<std::shared_ptr<Slot>>& items, float x, float y) = 0;
    virtual void set_pos(float x, float y) = 0;
    virtual std::size_t size() const = 0;
    std::pair<sf::IntRect, std::pair<sf::Vector2f, sf::Vector2f>> calculate_slots(std::size_t i, std::size_t j, std::size_t width,
                                                        std::size_t height);
    // (x, y, w, h), (offx, offy, offamx, offamy)

protected:
    static float click_offset_x;
    static float click_offset_y;
};

class GraphicInventoryRef : public BaseGraphicInventory {
public:
    std::vector<std::shared_ptr<GraphicSlotRef>> gr_items_array;
    void build_inventory(std::vector<std::shared_ptr<Slot>>& items, float x, float y) override;
    std::shared_ptr<GraphicSlotRef>& operator[](std::size_t index);
    std::size_t size() const override {
        return gr_items_array.size();
    }
    void set_pos(float x, float y) override;
    static void check_move_objects(sf::Vector2i mouse_pos, std::vector<std::shared_ptr<GraphicSlotRef>>& gr_items_array);
};

class GraphicInventoryCopy : public BaseGraphicInventory {
public:
    std::vector<std::shared_ptr<GraphicSlotCopy>> gr_items_array;
    void build_inventory(std::vector<std::shared_ptr<Slot>>& items, float x, float y) override;
    std::shared_ptr<GraphicSlotCopy>& operator[](std::size_t index);
    std::size_t size() const override {
        return gr_items_array.size();
    }
    void set_pos(float x, float y) override;
};

class GraphicInventoryBar : public GraphicInventoryRef {
public:
    void build_inventory(std::vector<std::shared_ptr<Slot>>& items, std::size_t size);
    void dynamic_update(std::vector<std::shared_ptr<Slot>>& items);
    void inventory_menu_scale();
    void in_game_scale();

private:
    float scale_offset = 19.f;
};
