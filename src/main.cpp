#include "GESFML/Game.h"
#include "IntroState.h"
#include "EntityManager.h"
#include "EntityComponent.h"
#include <memory>

#include <iostream>

using namespace std;

struct CTest : GESFML::EntityComponent
{
    void Update(float elapsedTime) override { cout << entity->GetId() << " Updated" << endl; }
    void Init() override { cout << entity->GetId() << " Initialized" << endl; }
};

int main()
{
    GESFML::Game game;
    game.Initialize(std::shared_ptr<GESFML::State>(new IntroState()));
    game.Start();

    GESFML::EntityContainer container;

    container.Add("Test");

    container.Get(0).lock()->AddComponent<CTest>();

    GESFML::EntityManager manager;
    manager.Proceed(&container);
    manager.Proceed(&container);
    manager.Proceed(&container);

    return 0;
}
