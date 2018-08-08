#include "GESFML/StateUpdater.h"

namespace GESFML{

    void StateUpdater::Update(float elapsedTime)
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
        accessor->Peek()->HandleEvent();
    }

    void StateUpdater::Draw(sf::RenderTarget& target)
    {
        accessor->Peek()->Draw();
    }
}