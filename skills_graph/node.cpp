#include "node.h"
#include <stdexcept>

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

Node::Node(const std::string& name, std::shared_ptr<Skill> _skill, int _cost): cost(_cost) {
    font.loadFromFile("../../fonts/CyrilicOld.TTF");
    text.setFont(font);
    text.setString(name);
    text.setCharacterSize(14);
    text.setFillColor(sf::Color(100, 30, 30));
    text.setStyle(sf::Text::Bold);
    skill = _skill;
    barrier = 0;
    coord = {0.f, 0.f};
    main_texture = HOLDER().getResource("main_ui");

    node_body_l.setTexture(*main_texture);
    node_body_m.setTexture(*main_texture);
    node_body_r.setTexture(*main_texture);

    node_body_l.setTextureRect({16, 184, 40, 64});
    node_body_m.setTextureRect({50, 184, 30, 64});
    node_body_r.setTextureRect({82, 184, 32, 64});
}

Node::Node(Node&& other): childs(std::move(other.childs)), skill(std::move(other.skill)), coord(other.coord) {
    barrier = other.barrier;
    other.barrier = 0;
    cost = other.cost;
    other.cost = 0;
}

Node& Node::operator=(Node&& other) {
    if (this == &other)
        return *this;
    childs = std::move(other.childs);
    skill = std::move(other.skill);
    coord = std::move(other.coord);
    barrier = other.barrier;
    cost = other.cost;
    other.barrier = 0;
    other.cost = 0;
    return *this;
}

void Node::add_child(std::shared_ptr<Node> _child) {
    childs.push_back(_child);
    _child->barrier++;
}

void Node::add_childs(const std::vector<std::shared_ptr<Node>>& childs) {
    for (const auto& child : childs) {
        add_child(child);
    }
}

bool Node::is_locked() const {
    return barrier != 0;
}

std::shared_ptr<Skill> Node::unlock() {
    if (is_locked())
        throw std::logic_error("Skill is blocked");
    for (const auto& child : childs) {
        child->barrier--;
    }
    return skill;
}

void Node::use_skill(Player& p) {
    skill->player_func(p);
}

void Node::print_node(sf::RenderWindow& window) {
    window.draw(node_body_l);
    window.draw(node_body_m);
    window.draw(node_body_r);
    window.draw(text);
}

void Node::set_coord(sf::Vector2f& c) {
    coord = c;
    node_body_l.setPosition(coord);
    node_body_m.setPosition({coord.x + 32, coord.y});
    node_body_r.setPosition({coord.x + 60, coord.y});
    text.setPosition(sf::Vector2f(coord.x, coord.y - 30));
}

void Node::node_checker(sf::Vector2i mouse_pos, const std::vector<std::shared_ptr<Node>>& _skills,
                        const sf::Event& _event, Player& player) {
    for (auto node : _skills) {
        if (mouse_pos.x > node->coord.x && mouse_pos.x < node->coord.x + 96 && mouse_pos.y > node->coord.y &&
            mouse_pos.y < node->coord.y + 63) {
            if (_event.type == sf::Event::MouseButtonPressed) {
                return node->use_skill(player);
            }
        }
    }
}