#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "GESFML/State.h"
#include <SFML/Graphics/Texture.hpp>

class PlayState : public GESFML::State
{
    sf::Texture texture;
public:

    virtual void OnEnter();
    virtual void OnLeave();

    virtual void OnUpdate();
    virtual void OnHandleEvent();
    virtual void OnDraw();
};

#endif // PLAY_STATE_H
