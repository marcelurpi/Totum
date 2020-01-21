#ifndef LIB_LOGGER_H_
#define LIB_LOGGER_H_

#include <vector>
#include <memory>
#include "entity.h"

class Logger
{
private:
    int roundNum;
    int roundsToSkip;
    std::vector<std::shared_ptr<Entity>> entities;
public:
    Logger(int roundsToSkip);
    void print_starting_line(const std::string& version);
    bool print_round(const std::vector<std::shared_ptr<Entity>>& entities);
};

#endif
