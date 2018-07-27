#ifndef GESFML_GAME_H
#define GESFML_GAME_H

#include "GESFML/StateStack.h"
#include "GESFML/StateUpdater.h"

namespace GESFML{
    
    class Game
    {
        StateStack stateStack;
        StateUpdater updater;
    public:
        void Initialize(std::shared_ptr<GESFML::State> state);
        void Start();
    private:
        void IterateLoop();
    };
}
#endif // GESFML_GAME_H