#include "GESFML/StateStack.h"
#include "State.h"
#include <stdexcept>
#include <iostream>

using namespace std;

namespace GESFML{

    void StateStack::ConnectWithRenderWindow(sf::RenderWindow* window)
    {
        this->renderWindow = window;
    }

    void StateStack::Push(std::shared_ptr<State> state)
    {
        std::shared_ptr<State> topState = Peek();

        if(topState)
            topState->OnHide();

        states.push(state);

        Peek()->ConnectWithStateTransition(this);
        Peek()->ConnectWithRenderWindow(renderWindow);
        Peek()->OnEnter();
    }

    void StateStack::Pop()
    {
        if(this->states.empty()) {
        throw std::runtime_error("Attempted to pop from an empty game state stack");
        }

        states.top()->OnLeave();
        states.pop();
    }

    std::shared_ptr<State> StateStack::Peek()
    {
        if(!states.empty())
            return states.top();
        else
            return nullptr;
    }

    void StateStack::Switch(std::shared_ptr<State> state)
    {
        std::shared_ptr<State> currentState = Peek();

        if(currentState)
            Pop();

        Push(state);
    }
}