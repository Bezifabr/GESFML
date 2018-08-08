#ifndef GESFML_STATE_STACK_H
#define GESFML_STATE_STACK_H

#include <stack>
#include <memory>
#include "StateTransition.h"
#include "StateAccessor.h"

namespace GESFML{

    class StateStack : public StateTransition, public StateAccessor
    {
        std::stack<std::shared_ptr<State>> states;

    public:
        virtual void Push(std::shared_ptr<State> state);
        virtual void Pop();

        virtual void Switch(std::shared_ptr<State> state);

        private:
        virtual std::shared_ptr<State> Peek();

    };
}
#endif // GESFML_STATE_STACK_H
