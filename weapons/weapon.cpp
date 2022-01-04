#include "weapon.h"

Weapon::Weapon() {
    _item_type = ItemType::WEAPON;
    _textures.resize(T_SIZE);
}

//Weapon::Weapon(const Weapon& other) : 
//    _texture(other._texture), _sprite(other._sprite) {
//    _damage = other._damage;
//    _critical_chance = other._critical_chance;
//    _critical_multiplier = other._critical_multiplier;
//    _weapon_type = other._weapon_type;
//}

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

void Weapon::walk() {
    if (this != nullptr && _textures[T_WALK] != nullptr) {
        _sprite.setTexture(*_textures[T_WALK]);
    }
}

void Weapon::thrust() {
    if (this != nullptr && _textures[T_THRUST] != nullptr) {
        _sprite.setTexture(*_textures[T_THRUST]);
    }
}

void Weapon::spellcast() {
    if (this != nullptr && _textures[T_SPELLCAST] != nullptr) {
        _sprite.setTexture(*_textures[T_SPELLCAST]);
    }
}

void Weapon::slash() {
    if (this != nullptr && _textures[T_SLASH] != nullptr) {
        _sprite.setTexture(*_textures[T_SLASH]);
    }
}

void Weapon::hurt() {
    if (this != nullptr && _textures[T_HURT] != nullptr) {
        _sprite.setTexture(*_textures[T_HURT]);
    }
}

void Weapon::bow() {
    if (this != nullptr && _textures[T_BOW] != nullptr) {
        _sprite.setTexture(*_textures[T_BOW]);
    }
}
