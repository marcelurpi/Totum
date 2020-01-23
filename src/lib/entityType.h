#ifndef LIB_ENTITY_TYPE_H_
#define LIB_ENTITY_TYPE_H_

#include <vector>
#include "component.h"

class EntityType
{
private:
    std::string name;
    std::vector<std::shared_ptr<Component>> components;
public:
    EntityType(const std::string& name);
    template<typename T> void addComponent(int valueToAddOnUpdate);
    std::vector<std::shared_ptr<Component>> getComponents() const;
    std::string getName() const;
};

#endif
