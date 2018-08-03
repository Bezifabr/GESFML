#include "Entity.h"

namespace GESFML{

    unsigned long int Entity::idCount = 0;
    std::queue<unsigned long int> Entity::removedIdQueue;

    Entity::Entity(std::string name) : name(name)
    {
        if (!removedIdQueue.empty())
        {
            id = removedIdQueue.front();
            removedIdQueue.pop();
        }
        else id = idCount++;
    }

    Entity::~Entity()
    {
        removedIdQueue.push(id);
    }

    unsigned long int Entity::GetId() const
    {
        return id;
    }

    std::string Entity::GetName() const
    {
        return name;
    }

}