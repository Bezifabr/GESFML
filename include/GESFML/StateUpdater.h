#ifndef GESFML_STATE_UPDATER_H
#define GESFML_STATE_UPDATER_H

#include "StateAccessor.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace GESFML{

    class StateUpdater
    {
        StateAccessor* accessor = nullptr;
    public:
        void ConnectWithAccessor(StateAccessor* accessor);
        void Update(float elapsedTime);
        void HandleEvent(sf::Event event);
        void Draw(sf::RenderTarget& renderTarget);
    };
}

#endif // GESFML_STATE_UPDATER_H