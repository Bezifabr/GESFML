#ifndef GESFML_ENTITY_MANAGER_H
#define GESFML_ENTITY_MANAGER_H

#include <vector>
#include <unordered_map>
#include <memory>
#include "Entity.h"


namespace GESFML{
    typedef std::vector<std::shared_ptr<Entity>> EntityVector;
    typedef EntityVector::size_type EntityVectorIndex;

    class EntityManager{
            EntityVector entities;
            std::unordered_map<unsigned long int, EntityVectorIndex> entityLookup;
        public:
            unsigned long int Instantiate(std::string name);
            std::weak_ptr<Entity> GetEntity(unsigned long int id);
            void RemoveEntity(unsigned long int id);
    };
}

#endif // GESFML_ENTITY_MANAGER_H