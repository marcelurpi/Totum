#include "src/lib/entityManager.h"
#include "src/lib/logger.h"

int main()
{
    Logger logger(5);

    logger.print_starting_line("0.1");

    auto manager = EntityManager::getInstance();

    EntityType grassType{"Grass", {{"Growth", 10}}};
    EntityType sheepType{"Sheep", {{"Growth", 10}, {"Hunger", 15}}};

    manager->createEntities(grassType, 10);
    manager->createEntities(sheepType, 10);

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
