#include "Components/SpriteComponent.h"

namespace GESFML{


    void SpriteComponent::Draw(sf::RenderTarget& target)
    {
        target.draw(sprite);
    }

}