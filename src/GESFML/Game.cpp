#include "GESFML/Game.h"
#include <iostream>
#include <stdexcept>
#include "Config.h"

using namespace std;

namespace GESFML{

    void Game::Initialize(std::shared_ptr<State> state)
    {
        stateStack.ConnectWithRenderWindow(&window);
        stateStack.Push(state);
        updater.ConnectWithAccessor(&stateStack);

        window.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), WINDOW_TITLE);
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
            
                updater.Update(deltaTime);
                deltaTime = sf::Time::Zero;
                window.clear();
                updater.Draw();
                window.display();
        }

        stateStack.Pop();
    }
}