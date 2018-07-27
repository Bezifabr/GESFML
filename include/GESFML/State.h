#ifndef GESFML_STATE_H
#define GESFML_STATE_H

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

        virtual void Update() = 0;

    protected:
        StateTransition* transition = nullptr;
    };
}

#endif // GESFML_STATE_H
