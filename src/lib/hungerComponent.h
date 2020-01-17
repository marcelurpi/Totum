#ifndef LIB_HUNGER_COMPONENT_H_
#define LIB_HUNGER_COMPONENT_H_

#include "component.h"

class Entity;

class HungerComponent : public Component
{
private:
    int valueToEat;
    int valueToStarve;
public:
    HungerComponent(int valueToAddOnUpdate, std::shared_ptr<Entity> entity);
    void update();
    void addHunger(int amount);
    void eat(int amount);
    void starve();
};

#endif
