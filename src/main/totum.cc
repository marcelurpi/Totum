#include <iostream>
#include <vector>
#include <map>
#include <sstream>

#include "src/lib/entityManager.h"

void print_entities(const std::vector<std::shared_ptr<Entity>>& entities)
{
    std::cout << entities.size() << " entities" << std::endl;

    std::map<std::string, int> lines;

    int grassCount = 0;
    int sheepCount = 0;

    for(auto& entity : entities)
    {
        if(entity->getName() == "Grass") ++grassCount;
        if(entity->getName() == "Sheep") ++sheepCount;

        std::ostringstream line;
        line << "Entity: " << entity->getName();

        auto components = entity->getComponents();
        if(components.size() > 0) line << " ---";
        for(auto& component : components)
        {
            line << " " << component->getType() << ": " << component->getValue();
        }

        ++lines[line.str()];
    }

    for(auto& line : lines)
    {
        std::cout << line.first;
        if(line.second > 1) std::cout << " (" << line.second << ")";
        std::cout << std::endl;
    }

    std::cout << entities.size() << " entities: ";
    std::cout << grassCount << " grass " << sheepCount << " sheep " << std::endl;
}

int main()
{
    std::cout << "Welcome To Totum! version 0.1" << std::endl;

    auto manager = EntityManager::getInstance();

    EntityType grassType{"Grass", {{"Growth", 10}}};
    EntityType sheepType{"Sheep", {{"Growth", 10}, {"Hunger", 15}}};

    manager->createEntities(grassType, 10);
    manager->createEntities(sheepType, 10);

    auto entities = manager->getAllEntities();

    int roundNum = 0;
    int roundsToSkip = 5;

    while(entities.size() > 0 and entities.size() < 1000000)
    {
        if(roundNum % roundsToSkip == 0)
        {
            std::cout << "Round " << roundNum << std::endl;
            print_entities(entities);

            std::string str;
            std::getline(std::cin, str);
        }

        for(auto& entity : entities)
        {
            entity->update();
        }
        entities = manager->getAllEntities();
        ++roundNum;
    }
    if(entities.size() == 0)
    {
        std::cout << std::endl << "No entities found" << std::endl;
    }
    else if(entities.size() >= 1000000)
    {
        std::cout << std::endl << "Too many entities: " << entities.size() << std::endl;
    }
}
