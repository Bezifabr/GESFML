#include "GESFML/State.h"
#include <stdexcept>

namespace GESFML{
    
    void State::ConnectWithStateTransition(StateTransition* transition)
    {
        if(!transition)
            std::runtime_error("State couldn't connect with StateTransition pointer cause it is empty");
        this->transition = transition;
    }

    void State::ConnectWithRenderWindow(sf::RenderWindow* renderWindow)
    {
        if(!renderWindow)
            std::runtime_error("State couldn't connect with RenderWindow pointer cause it is empty");
        this->renderWindow = renderWindow;
    }

    void State::Refresh()
    {
        for(auto& e : container.GetEntities())
        {
            e->Refresh();

            if(!e->IsAlive())
                container.Remove(e->GetId());
        } 
    }

    void State::Update(sf::Time elapsedTime)
    {
        this->elapsedTime = elapsedTime;
          
        for(auto& e : container.GetEntities())
            e->Update(elapsedTime);

        OnUpdate();
    }

    void State::HandleEvent(sf::Event event)
    {
        this->event = event;
        
        for(auto& e : container.GetEntities()) e->HandleEvent(event);

        OnHandleEvent();
    }

    void State::Draw()
    {
        for(auto& e : container.GetEntities()) e->Draw(renderWindow);

        OnDraw();
    }

}