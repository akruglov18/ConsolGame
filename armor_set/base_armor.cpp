#include "base_armor.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

BaseArmor::BaseArmor(const std::string& name, const sf::Vector2f& pos) {
    _item_type = ItemType::ARMOR;
    _textures.resize(T_SIZE);
    for (int i = 0; i < T_SIZE; ++i) {
        _textures[i] = HOLDER().getResource(name + _suffixes[i]);
    }
    init_scale(pos);
}

void BaseArmor::change_mode(Modes mode, std::shared_ptr<BaseArmor> elem) {
    elem->get_sprite().setTexture(*elem->get_textures()[static_cast<int>(mode)]);
}
