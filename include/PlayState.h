#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "GESFML/State.h"

class PlayState : public GESFML::State
{
public:

    virtual void OnEnter();
    virtual void OnLeave();

    virtual void OnUpdate();
    virtual void OnHandleEvent();
    virtual void OnDraw();
};

#endif // PLAY_STATE_H
