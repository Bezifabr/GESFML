#include "GESFML/Game.h"
#include <iostream>
#include <stdexcept>

using namespace std;

namespace GESFML{

    void Game::Initialize(std::shared_ptr<State> state)
    {
        stateStack.Push(state);
        updater.ConnectWithAccessor(&stateStack);
    }

    void Game::Start()
    {
        IterateLoop();
    }

    void Game::IterateLoop()
    {
        updater.Update();
        updater.Update();
        updater.Update();
        updater.Update();
        updater.Update();
    }
}