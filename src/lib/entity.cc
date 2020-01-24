#include "entity.h"

Entity::Entity(EntityType entityType) : entityType(entityType) {}

std::shared_ptr<Entity> Entity::create(const EntityType& entityType)
{
    auto entity = std::shared_ptr<Entity>(new Entity(entityType));
    entity->setComponents(entityType);
    return entity;
}

// This function exists to use safely use shared_from_this outside the constructor
void Entity::setComponents(const EntityType& entityType)
{
    auto typeComponents = entityType.getComponents();
    components = std::vector<std::shared_ptr<Component>>(typeComponents.size());
    // Maybe use <algorithm>'s transform with two ranges?
    for(size_t i = 0; i < typeComponents.size(); ++i)
    {
        components[i] = typeComponents[i]->clone();
        components[i]->setParentEntity(shared_from_this());
    }
}

void Entity::update()
{
    for(auto& component : components)
    {
        component->update();
    }
}

template<typename T>
std::shared_ptr<T> Entity::addComponent(int valueToAddOnUpdate)
{
    std::shared_ptr<T> component = std::make_shared<T>(valueToAddOnUpdate);
    component->setParentEntity(shared_from_this());
    components.push_back(component);
    return component;
}

template std::shared_ptr<GrowthComponent> Entity::addComponent<GrowthComponent>(int valueToAddOnUpdate);
template std::shared_ptr<HungerComponent> Entity::addComponent<HungerComponent>(int valueToAddOnUpdate);

EntityType Entity::getEntityType() const
{
    return entityType;
}

std::vector<std::shared_ptr<Component>> Entity::getComponents()
{
    return components;
}

std::string Entity::getName() const
{
    return entityType.getName();
}

void Entity::injectComponent(std::shared_ptr<Component> component)
{
    components.push_back(component);
}
