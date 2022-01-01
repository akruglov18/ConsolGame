# pragma once
#include <vector>
#include <memory>
#include "skill.h"

class Node {
public:
    Node(std::shared_ptr<Skill> skill, int cost);
    Node(Node&& other);
    Node& operator=(Node&& other);

    void add_child(std::shared_ptr<Node> child);
    void add_childs(const std::vector<std::shared_ptr<Node>>& childs);

    bool is_locked() const;
    std::shared_ptr<Skill> unlock();

    int get_cost() { return _cost; }

    Node(const Node&) = delete;
    Node& operator=(const Node&) = delete;
private:
    std::vector<std::shared_ptr<Node>> _childs;
    std::shared_ptr<Skill> _skill;
    int _barrier;
    int _cost;
};
