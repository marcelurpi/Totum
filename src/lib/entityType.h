#ifndef LIB_ENTITY_TYPE_H_
#define LIB_ENTITY_TYPE_H_

#include <string>
#include <vector>

class EntityType
{
private:
    std::string name;
    std::vector<std::pair<std::string, int>> components;
public:
    EntityType() = default;
    EntityType(const std::string& name, std::vector<std::pair<std::string, int>> components);
    std::vector<std::pair<std::string, int>> getComponents() const;
    std::string getName() const;
};

#endif
