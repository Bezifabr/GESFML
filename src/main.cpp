#include "GESFML/Game.h"
#include "IntroState.h"
#include <memory>

using namespace std;

int main()
{
    GESFML::Game game;
    game.Initialize(std::shared_ptr<GESFML::State>(new IntroState()));
    game.Start();

    return 0;
}
