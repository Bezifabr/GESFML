#include "EntityManager.h"
#include <stdexcept>

namespace GESFML{
    
    void EntityManager::Update(float elapsedTime)
    {        
        for(auto& e : container->GetEntities()) e->Update(elapsedTime);
    }

    void EntityManager::Draw()
    {
        for(auto& e : container->GetEntities()) e->Draw();
    }

    void EntityManager::Refresh()
    {
        for(auto& e : container->GetEntities())
        {
            if(!e->IsAlive())
                container->Remove(e->GetId());
        }
    }

    void EntityManager::ConnectWithContainer(EntityContainer* container)
    {
        this->container = container;
    }
}