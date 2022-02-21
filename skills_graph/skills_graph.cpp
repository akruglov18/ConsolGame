#include "skills_graph.h"
#include <stdexcept>

SkillsGraph::SkillsGraph() {
    skills.reserve(128);
}

void SkillsGraph::init() {

    // Making graph
    add_skill("спрей от жуков", std::make_shared<Skill>(*(new Skill(Skills_Functions::vitality5))), 500);
    add_skill("большой желудок", std::make_shared<Skill>(*(new Skill(Skills_Functions::vitality10))), 1000, 0);
    add_skill("средние доспехи", std::make_shared<Skill>(*(new Skill(Skills_Functions::vitality15))), 1700, 1);

    // Making correct graphics
    skills[0]->set_coord(sf::Vector2f(600.f, 320.f));
    skills[1]->set_coord(sf::Vector2f(740.f, 320.f));
    skills[2]->set_coord(sf::Vector2f(880.f, 320.f));
}

std::size_t SkillsGraph::add_skill(const std::string& name, std::shared_ptr<Skill> skill, int cost, int parent) {
    if (parent >= static_cast<int>(skills.size())) {
        throw std::out_of_range("Parent's skill is out of range");
    }
    std::shared_ptr<Node> node(new Node(name, skill, cost));
    skills.push_back(node);
    if (parent != -1)
        skills[parent]->add_child(node);
    return skills.size() - 1;
}

std::vector<std::size_t> SkillsGraph::add_skills(const std::vector<std::shared_ptr<Skill>>& skills,
                                                 const std::vector<int>& costs, int parent) {
    if (skills.size() != costs.size())
        throw std::out_of_range("Sizes of skills and costs are not equal");
    std::vector<std::size_t> id;
    id.reserve(skills.size());
    for (std::size_t i = 0; i < skills.size(); i++) {
        id.push_back(add_skill("TEMPORARY NOTHING", skills[i], costs[i], parent));
    }
    return id;
}

std::vector<std::size_t> SkillsGraph::add_skills(const std::vector<std::shared_ptr<Skill>>& skills,
                                                 const std::vector<int>& costs, const std::vector<int>& parents) {
    if (skills.size() != costs.size() || costs.size() != parents.size())
        throw std::out_of_range("Sizes of skills, costs and parents are not equal");
    std::vector<std::size_t> id;
    id.reserve(skills.size());
    for (std::size_t i = 0; i < skills.size(); i++) {
        id.push_back(add_skill("TEMPORARY NOTHING", skills[i], costs[i], parents[i]));
    }
    return id;
}

void SkillsGraph::connect(std::size_t id_from, std::size_t id_to) {
    skills[id_from]->add_child(skills[id_to]);
}

bool SkillsGraph::is_locked(std::size_t id) {
    return skills[id]->is_locked();
}

std::shared_ptr<Skill> SkillsGraph::unlock(std::size_t id) {
    return skills[id]->unlock();
}
