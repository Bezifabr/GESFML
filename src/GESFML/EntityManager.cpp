#include "EntityManager.h"

namespace GESFML{

    unsigned long int EntityManager::Instantiate(std::string name)
    {
        std::shared_ptr<Entity> ptr = std::make_shared<Entity>(name);
        entityLookup.insert({ptr->GetId(), entities.size() });
        entities.push_back(ptr);
        return ptr->GetId();
    }

    std::weak_ptr<Entity> EntityManager::GetEntity(unsigned long int id)
    {
        auto it = entityLookup.find(id);
        if (it != entityLookup.end())
            return std::weak_ptr<Entity>(entities[it->second]);
        else
            return std::weak_ptr<Entity>();
    }

    void EntityManager::RemoveEntity(unsigned long int id)
    {
        auto it = entityLookup.find(id);
        if (it != entityLookup.end())
        {
            EntityVectorIndex i = it->second;
            unsigned long int back = entities.back()->GetId();

            std::swap(entities[i], entities.back());
            entities.pop_back();

            entityLookup[back] = i;
            entityLookup.erase(id);
        }
    }

}