#ifndef GESFML_ENTITY_MANAGER_H
#define GESFML_ENTITY_MANAGER_H

#include "EntityContainer.h"

namespace GESFML{
    class EntityManager
    {
        EntityContainer* container;
    public:

        void Update(float elapsedTime);
        void Draw();
        void Refresh();

        void ConnectWithContainer(EntityContainer* container);

    };
}

#endif // GESFML_ENTITY_MANAGER_H