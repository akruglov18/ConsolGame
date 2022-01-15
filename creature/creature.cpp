#include "creature.h"
#include "Player/player.h"
#include "ResourceHolder.h"

#define STUCK_TIME 3.f

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

Creature::Creature(const std::string& _name, CreatureManager& _manager, int _health, const sf::Vector2f& _pos) :
                   manager(_manager), pos(_pos) {
    current_frame = 0.f;
    health = _health;
    direction = Dirs::DOWN;
    mode = Modes::WALK;
    action_animation_duration = 8;
    body_textures.resize(static_cast<int>(Modes::MODES_SIZE));
    for (int i = 0; i < static_cast<int>(Modes::MODES_SIZE); ++i) {
        body_textures[i] = HOLDER().getResource(_name + Items::suffixes[i]);
    }
    sprite.setTexture(*body_textures[static_cast<int>(Modes::WALK)]);
    sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
    sprite.setPosition(sf::Vector2f(_pos.x, _pos.y - 32));
}

Creature::Creature(const Creature& other) : manager(other.manager), pos(other.pos) {
    current_frame = other.current_frame;
    health = other.health;
    body_textures = other.body_textures;
    sprite = other.sprite;
    creature_type = other.creature_type;
    direction = other.direction;
    action_animation_duration = other.action_animation_duration;
    mode = other.mode;
}

void Creature::set_pos(float x, float y) {
    pos.x = x;
    pos.y = y;
}

void Creature::set_weapon(std::shared_ptr<Weapon> _weapon) {
    weapon = _weapon;
}

void Creature::reduce_health(int value) {
    health -= value;
    //std::cout << "health = " << health << '\n';
    stuck = true;
    stuck_time = STUCK_TIME;
    if (health < 0) {
        died = true;
    }
}

void Creature::update_stuck_frame(float time) {
    if (stuck) {
        stuck_time -= 0.15f * time;
        if (stuck_time < 0) {
            stuck = false;
            stuck_time = 0.f;
        }
    }
}

void Creature::die() {
    manager.creatureDied(this);
}

void Creature::add_experience(int exp) {
    experience += exp;
}

void Creature::show_creature(sf::RenderWindow& window) {
    window.draw(sprite);
    if (direction == Dirs::UP)
        window.draw(get_weapon()->get_sprite());

    for (auto el : get_armor().INNERarmor_set) {
        if (el != nullptr)
            window.draw(el->get_sprite());
    }

    if (get_weapon() != nullptr && direction != Dirs::UP)
        window.draw(get_weapon()->get_sprite());
}

std::string Creature::creature_type_str() const {
    switch(creature_type) {
        case CreatureType::PLAYER:      return "Player";
        case CreatureType::BEETLE:      return "Beetle";
        case CreatureType::WOLF:        return "Wolf";
        case CreatureType::TRADER:      return "Trader";
        case CreatureType::TAUR:        return "Taur";
        case CreatureType::SKELETON:    return "Skeleton";
        case CreatureType::NONE:        return "NONE";
        default:                        throw std::logic_error("Invalid creature type");
    }
}

json Creature::to_json() const {
    json res;
    auto name = creature_type_str();
    res[name]["health"] = health;
    res[name]["experience"] = experience;
    res[name]["pos"]["x"] = pos.x;
    res[name]["pos"]["y"] = pos.y;
    res[name].push_back(armor_set.to_json());
    res[name].push_back(weapon->to_json());
    return res;
}

void Creature::change_mode(Modes _mode) {
    sprite.setTexture(*body_textures[static_cast<int>(_mode)]);
    armor_set.change_mode(_mode);
    if (weapon != nullptr)
        weapon->change_mode(_mode);
    mode = _mode;
}

void CreatureManager::setPlayer(const std::shared_ptr<Player>& _player) {
    player = _player;
}

void CreatureManager::creatureDied(Creature* creature) {
    if(creature->get_type() == CreatureType::NONE)
        throw std::logic_error("Creature died, Creture type: NONE");

    if(creature->get_type() == CreatureType::PLAYER) {
        // end game
        return;
    }

    auto field_ptr = field.lock();

    auto player_ptr = player.lock();
    player_ptr->add_experience(10);
}
