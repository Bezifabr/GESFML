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

    void Entity::Update(sf::Time elapsedTime)
    {
        for(auto& comp : components) comp->Update(elapsedTime);
    }

    void Entity::Draw(sf::RenderTarget& target)
    {
        for(auto& comp : components) comp->Draw(target);
    }
}