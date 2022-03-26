#include "node.h"
#include <stdexcept>

Node::Node(const std::string& name, std::shared_ptr<Skill> _skill, int _cost, const sf::FloatRect& _coord)
        : cost(_cost), node_button(name, _coord) {
    skill = _skill;
    barrier = 0;    
    opened = false;
}

Node::Node(Node&& other)
        : childs(std::move(other.childs)), skill(std::move(other.skill)), node_button(std::move(other.node_button)) {
    barrier = other.barrier;
    other.barrier = 0;
    cost = other.cost;
    other.cost = 0;
    opened = other.opened;
    other.opened = false;
}

Node& Node::operator=(Node&& other) {
    if (this == &other)
        return *this;
    childs = std::move(other.childs);
    skill = std::move(other.skill);
    node_button = std::move(other.node_button);
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

bool Node::is_available() const {
    return barrier == 0;
}

bool Node::is_opened() const {
    return opened;
}

std::shared_ptr<Skill> Node::unlock() {
    if (is_locked())
        throw std::logic_error("Skill is blocked");
    for (const auto& child : childs) {
        child->barrier--;
    }
    opened = true;
    return skill;
}


