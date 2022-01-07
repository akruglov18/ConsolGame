#include "weapon.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

Weapon::Weapon(const std::string& name, const sf::Vector2f& pos) {
    _item_type = ItemType::WEAPON;
    _textures.resize(static_cast<int>(Modes::MODES_SIZE));
    for (int i = 0; i < static_cast<int>(Modes::MODES_SIZE); ++i) {
        _textures[i] = HOLDER().getResource(name + _suffixes[i]);
    }
    init_scale(pos);
}

Weapon::Weapon(const Weapon& other) {
    _textures = other._textures;
    _sprite = other._sprite;
    _damage = other._damage;
    _critical_chance = other._critical_chance;
    _critical_multiplier = other._critical_multiplier;
    _weapon_type = other._weapon_type;
}

double Weapon::get_damage() const {
    std::random_device device;
    std::mt19937 gen(device());
    int chance = gen() % 101;
    double result = _damage;
    if (chance <= _critical_chance) {
        result = _damage*_critical_multiplier;
    }
    return result;
}

json Weapon::to_json() const {
    json res;
    auto name = std::string("Weapon");
    res[name]["class_type"] = string_type();
    res[name]["damage"] = _damage;
    res[name]["critical_chance"] = _critical_chance;
    res[name]["critical_multiplier"] = _critical_multiplier;
    return res;
}

void Weapon::change_mode(Modes mode) {
    _sprite.setTexture(*_textures[static_cast<int>(mode)]);
}
