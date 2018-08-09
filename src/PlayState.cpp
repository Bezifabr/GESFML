#include "PlayState.h"
#include <iostream>
#include "Components/SpriteComponent.h"

using namespace std;

void PlayState::OnEnter()
{
    container.Add("Test");
    auto sprite = container.Get(0).lock();
    sprite->AddComponent<GESFML::SpriteComponent>();

    texture.loadFromFile("test.png");

    sprite->GetComponent<GESFML::SpriteComponent>().sprite.setTexture(texture);


    cout << "Play State Entered" << endl;
}

void PlayState::OnLeave()
{
    cout << "Play State Left" << endl;
}

void PlayState::OnUpdate()
{
    cout << "Play State Updated" << endl;
}

void PlayState::OnHandleEvent()
{

}

void PlayState::OnDraw()
{
    
}