#ifndef GESFML_STATE_UPDATER_H
#define GESFML_STATE_UPDATER_H

#include "StateAccessor.h"

namespace GESFML{

    class StateUpdater
    {
        StateAccessor* accessor = nullptr;
    public:
        void ConnectWithAccessor(StateAccessor* accessor);
        void Update();
    };
}

#endif // GESFML_STATE_UPDATER_H