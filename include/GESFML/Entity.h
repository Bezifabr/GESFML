#ifndef GESFML_ENTITY_H
#define GESFML_ENTITY_H

#include <string>
#include <queue>

namespace GESFML{
        
    class Entity
    {
        unsigned long int id;
        static unsigned long int idCount;
        static std::queue<unsigned long int> removedIdQueue;


        std::string name;
    public:
        Entity(std::string name);
        ~Entity();

        unsigned long int GetId() const;
        std::string GetName() const;
    };
}
#endif // GESFML_ENTITY_H