#include "src/lib/entityManager.h"
#include "src/lib/logger.h"

int main()
{
    Logger logger(1);

    logger.print_starting_line("0.1");

    auto manager = EntityManager::getInstance();

    EntityType grassType{"Grass", {}};

    auto entity = manager->createEntity(grassType);
    entity->addComponent<GrowthComponent>(20);

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
