#include "entityType.h"
#include "growthComponent.h"
#include "hungerComponent.h"

EntityType::EntityType(const std::string& name) : name(name) {}

template<typename T>
void EntityType::addComponent(int valueToAddOnUpdate)
{
    components.push_back(std::make_shared<T>(valueToAddOnUpdate));
}

template void EntityType::addComponent<GrowthComponent>(int valueToAddOnUpdate);
template void EntityType::addComponent<HungerComponent>(int valueToAddOnUpdate);

std::vector<std::shared_ptr<Component>> EntityType::getComponents() const
{
    return components;
}

std::string EntityType::getName() const
{
    return name;
}
