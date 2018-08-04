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

        bool alive = true;
    public:
        Entity(std::string name);
        ~Entity();

        unsigned long int GetId() const;
        std::string GetName() const;

        bool IsAlive() const { return alive; }
        void Destroy() { alive = false; }

        
    };
}
#endif // GESFML_ENTITY_H