#ifndef GESFML_STATE_ACCESSOR_H
#define GESFML_STATE_ACCESSOR_H

#include <memory>
#include "State.h"

namespace GESFML{
    
    class StateAccessor
    {
    public:
        virtual std::shared_ptr<State> Peek() = 0;
    };
}
#endif // GESFML_STATE_ACCESSOR_H