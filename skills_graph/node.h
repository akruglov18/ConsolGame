#pragma once
#include <memory>
#include <vector>
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

    int get_cost() {
        return cost;
    }

    void use_skill(Player& p);

    Node(const Node&) = delete;
    Node& operator=(const Node&) = delete;

private:
    std::vector<std::shared_ptr<Node>> childs;
    std::shared_ptr<Skill> skill;
    int barrier;
    int cost;
};
