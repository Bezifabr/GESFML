#include "Components/CollisionComponent.h"

namespace GESFML{
        
    CollisionComponent::CollisionComponent(sf::FloatRect collisionArea, bool collisionOn)
        : collisionArea(collisionArea), collisionOn(collisionOn)
    {

    }

    bool CollisionComponent::DetectCollision(const sf::FloatRect& rect)
    {
        return collisionArea.intersects(rect);
    }

    bool CollisionComponent::DetectCollision(const sf::Vector2f point)
    {
        return collisionArea.contains(point);
    }

	void CollisionComponent::UpdateCollisionArea(sf::FloatRect collisionArea)
	{
		this->collisionArea = collisionArea;
	}

}