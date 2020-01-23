#ifndef LIB_COMPONENT_H_
#define LIB_COMPONENT_H_

#include <string>
#include <memory>

class Entity;

class Component
{
protected:
    std::string type;
    int value;
    int valueToAddOnUpdate;
    std::shared_ptr<Entity> parentEntity;
public:
    Component(const std::string& type, int valueToAddOnUpdate);
    void setParentEntity(std::shared_ptr<Entity> entity);
    virtual void update() = 0;
    virtual std::shared_ptr<Component> clone() = 0;
    std::string getType() const;
    int getValue() const;
};

#endif
