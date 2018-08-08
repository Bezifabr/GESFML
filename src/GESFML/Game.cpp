#include "GESFML/Game.h"
#include <iostream>
#include <stdexcept>

using namespace std;

namespace GESFML{

    void Game::Initialize(std::shared_ptr<State> state)
    {
        stateStack.Push(state);
        updater.ConnectWithAccessor(&stateStack);

        window.create(sf::VideoMode(1000,1000), "GESFML");
        window.setFramerateLimit(60);
        window.setKeyRepeatEnabled(false);


    }

    void Game::Start()
    {
        IterateLoop();
    }

    void Game::IterateLoop()
    {

        sf::Time deltaTime = sf::Time::Zero;
        sf::Event event;        
        while(window.isOpen())
        {
            while(window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                    window.close();

                updater.HandleEvent(event);
            } 
            
                updater.Update(deltaTime.asSeconds());
                deltaTime = sf::Time::Zero;
                window.clear();
                updater.Draw(window);
                window.display();
        }
    }
}