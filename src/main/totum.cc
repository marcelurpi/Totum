#include "src/lib/entityManager.h"
#include "src/lib/logger.h"

int main()
{
    Logger logger(1);

    logger.print_starting_line("0.1");

    auto manager = EntityManager::getInstance();

    EntityType grassType("Grass");
    grassType.addComponent<GrowthComponent>(20);

    EntityType sheepType("Sheep");
    sheepType.addComponent<GrowthComponent>(15);
    sheepType.addComponent<HungerComponent>(20);

    manager->createEntities(grassType, 4);
    manager->createEntity(sheepType);

    while(true)
    {
        auto entities = manager->getAllEntities();

        bool continueRunning = logger.print_round(entities);
        if(not continueRunning) return 0;

        for(auto& entity : entities)
        {
            entity->update();
        }
    }
}
