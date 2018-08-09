#ifndef GESFML_SPRITE_COMPONENT_H
#define GESFML_SPRITE_COMPONENT_H

#include "Component.h"
#include <SFML/Graphics/Sprite.hpp>

namespace GESFML{
    struct SpriteComponent : public Component
    {
        sf::Sprite sprite;
        virtual void Draw(sf::RenderTarget& target) override;
    };
}

#endif //  GESFML_SPRITE_COMPONENT_H
