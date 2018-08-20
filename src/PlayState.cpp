#include "PlayState.h"
#include <iostream>
#include "Components/SpriteComponent.h"
#include "Components/ClickableComponent.h"
#include "Components/CollisionComponent.h"
#include "Components/TextComponent.h"


using namespace std;

void PlayState::OnEnter()
{
    font.loadFromFile("font.ttf");

    container.Create("Test");
    auto sprite = container.Get(0).lock();
    sprite->AddComponent<GESFML::SpriteComponent>("test.png");
    sprite->AddComponent<GESFML::TextComponent>("Test", &font, sf::Vector2f(200,200), 50, sf::Color::Red);
    
    sprite->AddComponent<GESFML::ClickableComponent>(sprite->GetComponent<GESFML::SpriteComponent>().sprite.getGlobalBounds());
    sprite->AddComponent<GESFML::CollisionComponent>(sprite->GetComponent<GESFML::SpriteComponent>().sprite.getGlobalBounds());

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

    sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition((*renderWindow)).x, sf::Mouse::getPosition((*renderWindow)).y);

  //  if(sprite->GetComponent<GESFML::CollisionComponent>().DetectCollision(mousePos))
      //  cout << "Collision!" << endl;

}

void PlayState::OnHandleEvent()
{
    auto sprite = container.Get(0).lock();
    sprite->GetComponent<GESFML::ClickableComponent>().CheckIfIsClicked(event, sf::Mouse::getPosition((*renderWindow)));
}

void PlayState::OnDraw()
{
    
}