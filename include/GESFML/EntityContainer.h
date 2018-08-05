#ifndef GESFML_ENTITY_CONTAINER_H
#define GESFML_ENTITY_CONTAINER_H

#include "Entity.h"
#include <memory>
#include <vector>
#include <unordered_map>

namespace GESFML{
    using EntityVector = std::vector<std::shared_ptr<Entity>>;
    using EntityVectorIndex = EntityVector::size_type;

    class EntityContainer
    {
        EntityVector entities;
        std::unordered_map<EntityId, EntityVectorIndex> entityLookup;
    public:
        EntityId Add(std::string name);
        std::weak_ptr<Entity> Get(EntityId id);
        void Remove(EntityId id);

        const EntityVector & GetEntities() const { return entities; }
    };
}
#endif // GESFML_ENTITY_CONTAINER_H