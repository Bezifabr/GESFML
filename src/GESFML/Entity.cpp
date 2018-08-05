#include "Entity.h"

namespace GESFML{
    std::queue<EntityId> Entity::removedIds;

    Entity::Entity(std::string name) : name(name)
    {
        if(!removedIds.empty())
        {
            id = removedIds.front();
            removedIds.pop();
        }
        else id = GetUniqueEntityId();
    }

    Entity::~Entity()
    {
        removedIds.push(id);
    }

    void Entity::Update(float elapsedTime)
    {
        for(auto& comp : components) comp->Update(elapsedTime);
    }

    void Entity::Draw()
    {
        for(auto& comp : components) comp->Draw();
    }
}