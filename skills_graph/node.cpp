#include "node.h"
#include <stdexcept>

Node::Node(std::shared_ptr<Skill> _skill, int _cost): cost(_cost) {
    skill = _skill;
    barrier = 0;
}

Node::Node(Node&& other): childs(std::move(other.childs)), skill(std::move(other.skill)) {
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
    barrier = other.barrier;
    other.barrier = 0;
    cost = other.cost;
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