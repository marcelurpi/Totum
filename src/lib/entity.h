#ifndef LIB_ENTITY_H_
#define LIB_ENTITY_H_

#include <string>
#include <vector>
#include "growthComponent.h"
#include "hungerComponent.h"

struct EntityType
{
    std::string name;
    std::vector<std::pair<std::string, int>> components;
};

class Entity : public std::enable_shared_from_this<Entity>
{
private:
    EntityType entityType;
    std::vector<std::shared_ptr<Component>> components;

    Entity() = default;
public:
    static std::shared_ptr<Entity> create(const EntityType& entityType);
    void setComponents(const EntityType& entityType);
    void update();
    EntityType getEntityType() const;
    std::vector<std::shared_ptr<Component>> getComponents();
    std::string getName() const;
};

#endif
