#include "growthComponent.h"
#include "src/lib/entityManager.h"

#include <iostream>

GrowthComponent::GrowthComponent(int valueToAddOnUpdate) :
    Component("Growth", valueToAddOnUpdate), valueToSpread(100) {}

void GrowthComponent::update()
{
    addGrowth(valueToAddOnUpdate);
}

std::shared_ptr<Component> GrowthComponent::clone()
{
    return std::make_shared<GrowthComponent>(*this);
}

void GrowthComponent::addGrowth(int amount)
{
    value += amount;
    if(value >= valueToSpread)
    {
        value -= valueToSpread;
        spread(1);
    }
}

void GrowthComponent::spread(int times) const
{
    auto manager = EntityManager::getInstance();
    for(int i = 0; i < times; ++i)
    {
        manager->createEntity(parentEntity->getEntityType());
    }
}
