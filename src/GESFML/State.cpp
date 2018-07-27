#include "GESFML/State.h"
#include <stdexcept>

namespace GESFML{
    
    void State::ConnectWithStateTransition(StateTransition* transition)
    {
        if(!transition)
            std::runtime_error("State couldn't connect with StateTransition pointer cause it is empty");
        this->transition = transition;
    }

}