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
    std::shared_ptr<Entity> entity;
public:
    Component(const std::string& type, int valueToAddOnUpdate, std::shared_ptr<Entity> entity);
    virtual void update() = 0;
    std::string getType() const;
    int getValue() const;
};

#endif
