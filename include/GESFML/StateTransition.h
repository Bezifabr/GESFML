#ifndef GESFML_STATE_TRANSITION_H
#define GESFML_STATE_TRANSITION_H

#include "State.h"
#include <memory>

namespace GESFML{

    class StateTransition
    {
    public:
        virtual void Pop() = 0;
        virtual void Push(std::shared_ptr<State> state) = 0;
        virtual void Switch(std::shared_ptr<State> state) = 0;
    };
}
#endif // GESFML_STATE_TRANSITION_H