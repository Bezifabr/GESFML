#include "GESFML/State.h"
#include <stdexcept>

namespace GESFML{
    
    void State::ConnectWithStateTransition(StateTransition* transition)
    {
        if(!transition)
            std::runtime_error("State couldn't connect with StateTransition pointer cause it is empty");
        this->transition = transition;
    }

    void State::Update(sf::Time elapsedTime)
    {
        this->elapsedTime = elapsedTime;
        
        for(auto& e : container.GetEntities())
        {
            if(!e->IsAlive())
                container.Remove(e->GetId());
        }
        
        for(auto& e : container.GetEntities()) e->Update(elapsedTime);

        OnUpdate();
    }

    void State::HandleEvent(sf::Event event)
    {
        this->event = event;
        
        OnHandleEvent();
    }

    void State::Draw()
    {
        for(auto& e : container.GetEntities()) e->Draw();

        OnDraw();
    }

}