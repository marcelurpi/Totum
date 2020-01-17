#include "component.h"

Component::Component(const std::string& type, int valueToAddOnUpdate, std::shared_ptr<Entity> entity) :
     type(type), value(0), valueToAddOnUpdate(valueToAddOnUpdate), entity(entity){}

void Component::update() {}

std::string Component::getType() const
{
    return type;
}

int Component::getValue() const
{
    return value;
}
