#include "hungerComponent.h"
#include "src/lib/entityManager.h"

#include <iostream>

HungerComponent::HungerComponent(int valueToAddOnUpdate, std::shared_ptr<Entity> entity) :
    Component("Hunger", valueToAddOnUpdate, entity), valueToEat(50), valueToStarve(100) {}

void HungerComponent::update()
{
    addHunger(valueToAddOnUpdate);
}

void HungerComponent::addHunger(int amount)
{
    value += amount;
    if(value >= valueToEat) eat(1);
    if(value >= valueToStarve) starve();
}

void HungerComponent::eat(int amount)
{
    auto manager = EntityManager::getInstance();
    auto components = entity->getComponents();
    for(int i = 0; i < amount; ++i)
    {
        auto entityToEat = manager->getEntityByName("Grass");
        if(entityToEat == nullptr) return;

        manager->destroyEntity(entityToEat);
        value = std::max(0, value - valueToEat);
    }
}

void HungerComponent::starve()
{
    auto manager = EntityManager::getInstance();
    std::shared_ptr<Entity> parent = std::shared_ptr<Entity>(entity);
    manager->destroyEntity(parent);
}
