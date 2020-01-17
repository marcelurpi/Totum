#include "entity.h"

std::shared_ptr<Entity> Entity::create(const EntityType& entityType)
{
    auto entity = std::shared_ptr<Entity>(new Entity);
    entity->entityType = entityType;
    entity->setComponents(entityType);
    return entity;
}

void Entity::setComponents(const EntityType& entityType)
{
    components = std::vector<std::shared_ptr<Component>>(entityType.components.size());
    for(size_t i = 0; i < components.size(); ++i)
    {
        if(entityType.components[i].first == "Growth")
        {
            components[i] = std::make_shared<GrowthComponent>(
                entityType.components[i].second, shared_from_this());
        }
        else if(entityType.components[i].first == "Hunger")
        {
            components[i] = std::make_shared<HungerComponent>(
                entityType.components[i].second, shared_from_this());
        }
    }
}

void Entity::update()
{
    for(auto& component : components)
    {
        component->update();
    }
}

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
    return entityType.name;
}
