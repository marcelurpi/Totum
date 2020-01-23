#ifndef LIB_ENTITY_H_
#define LIB_ENTITY_H_

#include "growthComponent.h"
#include "hungerComponent.h"
#include "entityType.h"

class Entity : public std::enable_shared_from_this<Entity>
{
private:
    EntityType entityType;
    std::vector<std::shared_ptr<Component>> components;

    Entity(EntityType entityType);
public:
    static std::shared_ptr<Entity> create(const EntityType& entityType);
    void setComponents(const EntityType& entityType);
    void update();
    template<typename T> std::shared_ptr<T> addComponent(int valueToAddOnUpdate);
    EntityType getEntityType() const;
    std::vector<std::shared_ptr<Component>> getComponents();
    std::string getName() const;
};

#endif
