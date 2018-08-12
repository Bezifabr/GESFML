#include "GESFML/StateUpdater.h"

namespace GESFML{

    void StateUpdater::Update(sf::Time elapsedTime)
    {
        accessor->Peek()->Update(elapsedTime);
    }

    void StateUpdater::ConnectWithAccessor(StateAccessor* accessor)
    {
        if(!accessor)
        throw std::runtime_error("StateUpdater couldn't connect with StateAccessor pointer cause it is empty");
        this->accessor = accessor;
    }

    void StateUpdater::HandleEvent(sf::Event event)
    {
        accessor->Peek()->HandleEvent(event);
    }

    void StateUpdater::Draw()
    {
        accessor->Peek()->Draw();
    }
}