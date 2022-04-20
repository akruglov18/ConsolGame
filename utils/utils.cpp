#include "utils.h"

void Utils::delete_dead_creatures(std::vector<std::shared_ptr<Enemy>>& enemies) {
    std::size_t to_resize = enemies.size();
    for (int i = 0; i < to_resize; ++i) {
        if (enemies[i]->dead) {
            std::swap(enemies[i], enemies[--to_resize]);
            if (enemies[i]->dead) {
                --i;
            }
        }
    }
    enemies.resize(to_resize);
}

std::vector<std::shared_ptr<Creature>> Utils::find_drawable_creatures(
        const std::vector<std::shared_ptr<Enemy>>& enemies, const std::vector<int>& object_borders) {
    int obj_top_border = object_borders[0];
    int obj_btm_border = object_borders[1];
    int obj_left_border = object_borders[2];
    int obj_right_border = object_borders[3];
    std::vector<std::shared_ptr<Creature>> drawable_creatures;
    drawable_creatures.resize(0);
    drawable_creatures.reserve(enemies.size());
    for (const auto& x : enemies) {
        if (x->get_pos().y > obj_top_border * 32 && x->get_pos().y < obj_btm_border * 32 &&
            x->get_pos().x > obj_left_border * 32 + 32 && x->get_pos().x < obj_right_border * 32 - 32)
            drawable_creatures.push_back(x);
    }
    return drawable_creatures;
}

void Utils::sort_drawable_creatures(std::vector<std::shared_ptr<Creature>>& drawable_creatures) {
    for (int i = 0; i < drawable_creatures.size(); ++i) {
        for (int j = 0; j < drawable_creatures.size() - i - 1; ++j) {
            if (static_cast<int>(drawable_creatures[j]->get_pos().y / 32) == 
                static_cast<int>(drawable_creatures[j + 1]->get_pos().y / 32)) {
                if (static_cast<int>(drawable_creatures[j]->get_pos().x / 32) > 
                    static_cast<int>(drawable_creatures[j + 1]->get_pos().x / 32)) {
                    std::swap(drawable_creatures[j], drawable_creatures[j + 1]);
                } 
            } else {
                if (static_cast<int>(drawable_creatures[j]->get_pos().y / 32) >
                    static_cast<int>(drawable_creatures[j + 1]->get_pos().y / 32)) {
                    std::swap(drawable_creatures[j], drawable_creatures[j + 1]);
                }
            }
        }
    }
}

void Utils::detect_collisions(std::vector<std::shared_ptr<Creature>>& drawable_creatures) {

    if (drawable_creatures.size() == 1) {
        drawable_creatures[0]->can_move = true;
        return;
    }

    for (int i = 0; i < drawable_creatures.size(); ++i) {
        for (int j = 0; j < drawable_creatures.size(); ++j) {

            if (drawable_creatures[j]->get_pos().y > drawable_creatures[i]->get_pos().y + 48.f)
                break;
            if (i == j ||
                drawable_creatures[j]->get_pos().y < drawable_creatures[i]->get_pos().y - 48.f ||
                drawable_creatures[j]->get_pos().x < drawable_creatures[i]->get_pos().x - 48.f ||
                drawable_creatures[j]->get_pos().x > drawable_creatures[i]->get_pos().x + 48.f)
                continue;

            if (check_collision(drawable_creatures[i]->collision_box, drawable_creatures[j]->collision_box,
                drawable_creatures[i]->direction)) {
                drawable_creatures[i]->can_move = false;
                break;
            } else {
                drawable_creatures[i]->can_move = true;
            }
        }
    }
}

bool Utils::check_collision(sf::FloatRect& box1, sf::FloatRect& box2, Dirs dir) {
    if (box1.findIntersection(box2).has_value()) {
        if (dir == Dirs::LEFT && box1.left > box2.left && box2.left + box2.width - box1.left < 5.f)
            return true;
        if (dir == Dirs::RIGHT && box1.left < box2.left && box1.left + box1.width - box2.left < 5.f)
            return true;
        if (dir == Dirs::UP && box1.top > box2.top && box2.top + box2.height - box1.top < 5.f)
            return true;
        if (dir == Dirs::DOWN && box1.top < box2.top && box1.top + box1.height - box2.top < 5.f)
            return true;
    }
    return false;
}

std::vector<int> Utils::get_rendering_borders(int window_width, int window_height, int field_width, int field_height,
                                              const sf::Vector2f& player_pos) {
    int left_border, right_border, top_border, btm_border;
    int tile_size = 32;  // immutable parameter

    // borders of rendering ///////////////////////////////////////////////////////////////////////////////////
    if (player_pos.x < window_width / 2)
        right_border = window_width / tile_size + 2;
    else
        right_border = std::min(field_width, static_cast<int>(((player_pos.x + window_width / 2) / tile_size) + 1));
    if (player_pos.x > field_width * tile_size - window_width / 2)
        left_border = field_width - window_width / tile_size - 2;
    else
        left_border = std::max(0, static_cast<int>(((player_pos.x - window_width / 2) / tile_size)));
    if (player_pos.y < window_height / 2)
        btm_border = window_height / tile_size + 2;
    else
        btm_border = std::min(static_cast<int>(field_height),
                              static_cast<int>(((player_pos.y + window_height / 2) / tile_size) + 1));
    if (player_pos.y > field_height * tile_size - window_height / 2)
        top_border = field_height - window_height / tile_size - 2;
    else
        top_border = std::max(0, static_cast<int>(((player_pos.y - window_height / 2) / tile_size)));

    return {top_border, btm_border, left_border, right_border};
}

std::vector<int> Utils::get_object_borders(const std::vector<int>& borders, int field_width, int field_height) {
    int obj_top_border = std::max(borders[0] - 1, 0);
    int obj_btm_border = std::min(borders[1] + 4, field_height);
    int obj_left_border = std::max(borders[2] - 2, 0);
    int obj_right_border = std::min(borders[3] + 2, field_width);
    return {obj_top_border, obj_btm_border, obj_left_border, obj_right_border};
}

void Utils::clear_event(sf::Event& event, sf::Event& last_event, std::shared_ptr<Player> player) {
    if (event.type == sf::Event::MouseMoved || event.type == sf::Event::MouseWheelScrolled ||
        event.type == sf::Event::MouseLeft || event.type == sf::Event::MouseEntered ||
        event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseButtonReleased ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Tilde) || sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
        event = std::move(last_event);
    }

    // ignoring the space button if player can't thrust
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !player->get_weapon()->can_thrust)) {
        if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
              sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
                event.type = sf::Event::KeyPressed;
                event.key.code = sf::Keyboard::LShift;
            } else {
                event.type = sf::Event::KeyReleased;
                event.key.code = sf::Keyboard::Unknown;
            }
        } else {
            event = std::move(last_event);
        }
    }
}
