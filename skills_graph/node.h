#pragma once
#include <memory>
#include <vector>
#include "skill.h"
#include "skill_button.h"

class Node {
public:
    Node(const std::string& name, std::shared_ptr<Skill> skill, int cost, const sf::FloatRect& _coord);
    Node(Node&& other);
    Node& operator=(Node&& other);

    void add_child(std::shared_ptr<Node> child);
    void add_childs(const std::vector<std::shared_ptr<Node>>& childs);

    bool is_locked() const;
    bool is_available() const;
    bool is_opened() const;
    std::shared_ptr<Skill> unlock();

    int get_cost() {
        return cost;
    }

    SkillButton node_button;

    Node(const Node&) = delete;
    Node& operator=(const Node&) = delete;

private:
    std::vector<std::shared_ptr<Node>> childs;
    std::shared_ptr<Skill> skill;
    int barrier;
    int cost;
    bool opened;
};
