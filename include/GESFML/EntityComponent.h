#ifndef GESFML_ENTITY_COMPONENT_H
#define GESFML_ENTITY_COMPONENT_H

#include <cstdio>
#include <type_traits>

namespace GESFML{

    using ComponentID = std::size_t;
    class Entity;

    struct EntityComponent
    {
        Entity* entity;

        virtual void Init() {}
        virtual void Update(float elapsedTime) {}
        virtual void Draw() {}

        virtual ~EntityComponent() {}
    };
    

    inline ComponentID GetUniqueComponentId() noexcept
    {
        static ComponentID lastId{0u};
        return lastId++;
    }

    template <typename T>
    inline ComponentID GetComponentTypeId() noexcept
    {
        static_assert(std::is_base_of<EntityComponent, T>::value,
            "T must inherit from EntityComponent");

        static ComponentID typeId{GetUniqueComponentId()};
        return typeId;
    }

}

#endif // GESFML_COMPONENT_H