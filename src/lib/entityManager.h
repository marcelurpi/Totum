#ifndef LIB_ENTITY_MANAGER_H_
#define LIB_ENTITY_MANAGER_H_

#include <string>
#include <vector>
#include <memory>
#include "entity.h"

class EntityManager
{
private:
    static std::shared_ptr<EntityManager> instance;
    std::vector<std::shared_ptr<Entity>> entities;
public:
    static std::shared_ptr<EntityManager> getInstance();
    std::vector<std::shared_ptr<Entity>> getAllEntities() const;
    std::shared_ptr<Entity> createEntity(const EntityType& entityType);
    void createEntities(const EntityType& entityType, int amount);
    void destroyEntity(std::shared_ptr<Entity> toDestroy);
    std::shared_ptr<Entity> getEntityByName(const std::string& name);
};

#endif
