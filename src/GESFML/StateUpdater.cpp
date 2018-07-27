#include "GESFML/StateUpdater.h"

namespace GESFML{

    void StateUpdater::Update()
    {
        accessor->Peek()->Update();
    }

    void StateUpdater::ConnectWithAccessor(StateAccessor* accessor)
    {
        if(!accessor)
        throw std::runtime_error("StateUpdater couldn't connect with StateAccessor pointer cause it is empty");
        this->accessor = accessor;
    }
}