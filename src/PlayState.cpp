#include "PlayState.h"
#include <iostream>

using namespace std;

void PlayState::OnEnter()
{
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