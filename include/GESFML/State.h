#ifndef GESFML_STATE_H
#define GESFML_STATE_H

#include "EntityContainer.h"
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace GESFML{
    
    class StateTransition;

    class State
    {
    public:
        void ConnectWithStateTransition(StateTransition* transition);
        void ConnectWithRenderWindow(sf::RenderWindow* renderWindow);
        virtual void OnEnter() = 0;
        virtual void OnLeave() = 0;
        virtual void OnShow() {}
        virtual void OnHide() {}

        void Refresh();
        void Update(sf::Time elapsedTime);
        void HandleEvent(sf::Event event);
        void Draw();


    protected:
        StateTransition* transition = nullptr;
        EntityContainer container;

        sf::Event event;
        sf::Time elapsedTime;
        sf::RenderWindow* renderWindow;

        virtual void OnUpdate() = 0;
        virtual void OnHandleEvent() = 0;
        virtual void OnDraw() = 0;
    };
}

#endif // GESFML_STATE_H
