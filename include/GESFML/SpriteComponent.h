#ifndef GESFML_SPRITE_COMPONENT_H
#define GESFML_SPRITE_COMPONENT_H

#include "EntityComponent.h"
#include <SFML/Graphics/Sprite.hpp>

namespace GESFML{
    struct SpriteComponent : public EntityComponent
    {
        sf::Sprite sprite;
        virtual void Draw(sf::RenderTarget& target) override;
    };
}

#endif //  GESFML_SPRITE_COMPONENT_H