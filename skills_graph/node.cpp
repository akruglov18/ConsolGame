#include "node.h"
#include <stdexcept>

Node::Node(std::shared_ptr<Skill> skill, int cost) : _cost(cost){
    _skill = skill;
    _barrier = 0;
}

Node::Node(Node&& other) : _childs(std::move(other._childs)), _skill(std::move(other._skill)) {
    _barrier = other._barrier;
    other._barrier = 0;
    _cost = other._cost;
    other._cost = 0;
}

Node& Node::operator=(Node&& other) {
    if(this == &other)
        return *this;
    _childs = std::move(other._childs);
    _skill = std::move(other._skill);
    _barrier = other._barrier;
    other._barrier = 0;
    _cost = other._cost;
    other._cost = 0;
}

void Node::add_child(std::shared_ptr<Node> child) {
    _childs.push_back(child);
    child->_barrier++;
}

void Node::add_childs(const std::vector<std::shared_ptr<Node>>& childs) {
    for(const auto& child : childs) {
        add_child(child);
    }
}

bool Node::is_locked() const {
    return _barrier != 0;
}

std::shared_ptr<Skill> Node::unlock() {
    if(is_locked())
        throw std::logic_error("Skill is blocked");
    for(const auto& child : _childs) {
        child->_barrier--;
    }
    return _skill;
}
