#ifndef GESFML_STATE_H
#define GESFML_STATE_H

#include "EntityContainer.h"

namespace GESFML{
    
    class StateTransition;

    class State
    {
    public:
        void ConnectWithStateTransition(StateTransition* transition);
        virtual void OnEnter() = 0;
        virtual void OnLeave() = 0;
        virtual void OnShow() {}
        virtual void OnHide() {}

        void Update(float elapsedTime);
        void HandleEvent();
        void Draw();


    protected:
        StateTransition* transition = nullptr;
        EntityContainer container;

        virtual void OnUpdate() = 0;
        virtual void OnHandleEvent() = 0;
        virtual void OnDraw() = 0;
    };
}

#endif // GESFML_STATE_H
