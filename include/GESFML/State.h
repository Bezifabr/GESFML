#ifndef GESFML_STATE_H
#define GESFML_STATE_H

#include "EntityContainer.h"
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

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

        void Update(sf::Time elapsedTime);
        void HandleEvent(sf::Event event);
        void Draw(sf::RenderTarget& target);


    protected:
        StateTransition* transition = nullptr;
        EntityContainer container;

        sf::Event event;
        sf::Time elapsedTime;
        sf::RenderTarget* renderTarget;

        virtual void OnUpdate() = 0;
        virtual void OnHandleEvent() = 0;
        virtual void OnDraw() = 0;
    };
}

#endif // GESFML_STATE_H
