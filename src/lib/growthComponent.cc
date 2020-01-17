#include "growthComponent.h"
#include "src/lib/entityManager.h"

GrowthComponent::GrowthComponent(int valueToAddOnUpdate, std::shared_ptr<Entity> entity) :
    Component("Growth", valueToAddOnUpdate, entity), valueToSpread(100) {}

void GrowthComponent::update()
{
    addGrowth(valueToAddOnUpdate);
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
        manager->createEntity(entity->getEntityType());
    }
}
