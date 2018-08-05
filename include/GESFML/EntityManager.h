#ifndef GESFML_ENTITY_MANAGER_H
#define GESFML_ENTITY_MANAGER_H

#include "EntityContainer.h"

namespace GESFML{
    class EntityManager
    {
        EntityContainer* container;
    public:
        void Proceed(EntityContainer* container);
        
    private:
        void Update(float elapsedTime);
        void Draw();
        void Refresh();


    };
}

#endif // GESFML_ENTITY_MANAGER_H