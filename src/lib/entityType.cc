#include "entityType.h"

EntityType::EntityType(const std::string& name, std::vector<std::pair<std::string, int>> components) :
    name(name), components(components) {}

std::vector<std::pair<std::string, int>> EntityType::getComponents() const
{
    return components;
}

std::string EntityType::getName() const
{
    return name;
}
