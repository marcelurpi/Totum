#ifndef LIB_GROWTH_COMPONENT_H_
#define LIB_GROWTH_COMPONENT_H_

#include "component.h"

class Entity;

class GrowthComponent : public Component
{
private:
    int valueToSpread;
public:
    GrowthComponent(int valueToAddOnUpdate);
    void update();
    std::shared_ptr<Component> clone();
    void addGrowth(int amount);
    void spread(int times) const;
};

#endif
