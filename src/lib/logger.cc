#include <iostream>
#include <map>
#include <sstream>
#include "logger.h"

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

Logger::Logger(int roundsToSkip) : roundNum(0), roundsToSkip(roundsToSkip) {}

void Logger::print_starting_line(const std::string& version)
{
    std::cout << "Welcome To Totum! version " << version << std::endl;
}

bool Logger::print_round(const std::vector<std::shared_ptr<Entity>>& entities)
{
    if(entities.size() == 0)
    {
        std::cout << std::endl << "No entities found" << std::endl;
        return false;
    }
    if(entities.size() >= 1e6)
    {
        std::cout << std::endl << "Too many entities: " << entities.size() << std::endl;
        return false;
    }
    if(roundNum % roundsToSkip == 0)
    {
        std::cout << "Round " << roundNum << std::endl;
        print_entities(entities);

        std::string str;
        std::getline(std::cin, str);
    }
    ++roundNum;
    return true;
}
