#ifndef GESFML_STATE_UPDATER_H
#define GESFML_STATE_UPDATER_H

#include "StateAccessor.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Time.hpp>

namespace GESFML{

    class StateUpdater
    {
        StateAccessor* accessor = nullptr;
    public:
        void ConnectWithAccessor(StateAccessor* accessor);
        void Update(sf::Time elapsedTime);
        void HandleEvent(sf::Event event);
        void Draw(sf::RenderTarget& renderTarget);
    };
}

#endif // GESFML_STATE_UPDATER_H