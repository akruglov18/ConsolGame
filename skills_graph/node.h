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

    void set_coord(sf::Vector2f& c);

    void print_node(sf::RenderWindow& window);

    void use_skill(Player& p);

    static void node_checker(sf::Vector2i mouse_pos, const std::vector<std::shared_ptr<Node>>& _skills,
                             const sf::Event& _event, Player& player);

    Node(const Node&) = delete;
    Node& operator=(const Node&) = delete;

private:
    std::shared_ptr<sf::Texture> main_texture;
    sf::Sprite node_body_l;
    sf::Sprite node_body_m;
    sf::Sprite node_body_r;
    sf::Sprite node_linker;
    std::vector<std::shared_ptr<Node>> childs;
    std::shared_ptr<Skill> skill;
    sf::Vector2f coord;
    int barrier;
    int cost;
};
