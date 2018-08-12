#ifndef GESFML_SPRITE_COMPONENT_H
#define GESFML_SPRITE_COMPONENT_H

#include "Component.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace GESFML{
    struct SpriteComponent : public Component
    {
        SpriteComponent(const std::string& textureSource);

        sf::Texture texture;
        sf::Sprite sprite;
        virtual void Draw(sf::RenderTarget* target) override;
    };
}

#endif //  GESFML_SPRITE_COMPONENT_H
