#include "PlayState.h"
#include <iostream>
#include "Components/SpriteComponent.h"
#include "Components/ClickableComponent.h"

using namespace std;

void PlayState::OnEnter()
{
    container.Add("Test");
    auto sprite = container.Get(0).lock();
    sprite->AddComponent<GESFML::SpriteComponent>("test.png");

    sprite->AddComponent<GESFML::ClickableComponent>(sprite->GetComponent<GESFML::SpriteComponent>().sprite.getGlobalBounds());

    cout << "Play State Entered" << endl;
}

void PlayState::OnLeave()
{
    cout << "Play State Left" << endl;
}

void PlayState::OnUpdate()
{
    auto sprite = container.Get(0).lock();
    if(sprite->GetComponent<GESFML::ClickableComponent>().IsReleased())
        cout << "Released" << endl;
    if(sprite->GetComponent<GESFML::ClickableComponent>().IsPressed())
        cout << "Pressed" << endl;
}

void PlayState::OnHandleEvent()
{
    auto sprite = container.Get(0).lock();
    sprite->GetComponent<GESFML::ClickableComponent>().CheckIfIsClicked(event, sf::Mouse::getPosition((*renderWindow)));
}

void PlayState::OnDraw()
{
    
}