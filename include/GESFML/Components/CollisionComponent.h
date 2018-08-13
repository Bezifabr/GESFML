#ifndef GESFML_COLLISION_COMPONENT_H
#define GESFML_COLLISION_COMPONENT_H

#include "Component.h"

namespace GESFML{

    class CollisionComponent : public Component
    {
		sf::FloatRect collisionArea;

		bool collisionOn;
	public:
		CollisionComponent(sf::FloatRect collisionArea, bool collisionOn = true);
		bool DetectCollision(const sf::FloatRect& rect);
        bool DetectCollision(const sf::Vector2f point);
    };

}

#endif // GESFML_COLLISION_COMPONENT_H