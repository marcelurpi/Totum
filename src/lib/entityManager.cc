#include "entityManager.h"
#include <algorithm>

std::shared_ptr<EntityManager> EntityManager::instance;

std::shared_ptr<EntityManager> EntityManager::getInstance()
{
    if(instance == nullptr) instance = std::make_shared<EntityManager>();
    return instance;
}

std::vector<std::shared_ptr<Entity>> EntityManager::getAllEntities() const
{
    return entities;
}

std::shared_ptr<Entity> EntityManager::createEntity(const EntityType& entityType)
{
    auto entity = Entity::create(entityType);
    entities.push_back(entity);
    return entity;
}

void EntityManager::createEntities(const EntityType& entityType, int amount)
{
    for(int i = 0; i < amount; ++i)
    {
        createEntity(entityType);
    }
}

void EntityManager::destroyEntity(std::shared_ptr<Entity> toDestroy)
{
    auto it = std::find(entities.begin(), entities.end(), toDestroy);
    if(it == entities.end()) return;
    *it = entities.back();
    entities.pop_back();
}

std::shared_ptr<Entity> EntityManager::getEntityByName(const std::string& name)
{
    auto it = std::find_if(entities.begin(), entities.end(),
        [name](std::shared_ptr<Entity> entity){ return entity->getName() == name; });
    if(it == entities.end()) return nullptr;
    return *it;
}

std::shared_ptr<EntityManager> EntityManager::createEmptyInstance()
{
    instance = std::make_shared<EntityManager>();
    return instance;
}
