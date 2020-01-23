#include "component.h"

Component::Component(const std::string& type, int valueToAddOnUpdate) :
     type(type), value(0), valueToAddOnUpdate(valueToAddOnUpdate) {}

void Component::setParentEntity(std::shared_ptr<Entity> parentEntity)
{
    this->parentEntity = parentEntity;
}

std::string Component::getType() const
{
    return type;
}

int Component::getValue() const
{
    return value;
}
