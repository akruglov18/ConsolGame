#include "skills_graph.h"
#include <stdexcept>

SkillsGraph::SkillsGraph() {}

std::size_t SkillsGraph::add_skill(std::shared_ptr<Skill> skill, int cost, int parent) {
    if(parent >= static_cast<int>(_skills.size())) {
        throw std::out_of_range("Parent's skill is out of range");
    }
    std::shared_ptr<Node> node(new Node(skill, cost));
    _skills.push_back(node);
    if(parent != -1)
        _skills[parent]->add_child(node);
    return _skills.size() - 1;
}

std::vector<std::size_t> SkillsGraph::add_skills(const std::vector<std::shared_ptr<Skill>>& skills, 
                                         const std::vector<int>& costs, int parent) {
    if(skills.size() != costs.size())
        throw std::out_of_range("Sizes of skills and costs are not equal");
    std::vector<std::size_t> id;
    id.reserve(skills.size());
    for(std::size_t i = 0; i < skills.size(); i++) {
        id.push_back(add_skill(skills[i], costs[i], parent));
    }
    return id;
}

std::vector<std::size_t> SkillsGraph::add_skills(const std::vector<std::shared_ptr<Skill>>& skills, 
                                         const std::vector<int>& costs, const std::vector<int>& parents) {
    if(skills.size() != costs.size() || costs.size() != parents.size())
        throw std::out_of_range("Sizes of skills, costs and parents are not equal");
    std::vector<std::size_t> id;
    id.reserve(skills.size());
    for(std::size_t i = 0; i < skills.size(); i++) {
        id.push_back(add_skill(skills[i], costs[i], parents[i]));
    }
    return id;
}

void SkillsGraph::connect(std::size_t id_from, std::size_t id_to) {
    _skills[id_from]->add_child(_skills[id_to]);
}

bool SkillsGraph::is_locked(std::size_t id) {
    return _skills[id]->is_locked();
}

std::shared_ptr<Skill> SkillsGraph::unlock(std::size_t id) {
    return _skills[id]->unlock();
}
