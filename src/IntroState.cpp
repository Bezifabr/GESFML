#include "IntroState.h"
#include "StateTransition.h"
#include "PlayState.h"
#include <iostream>

using namespace std;

void IntroState::OnEnter()
{
    cout << "Intro Entered" << endl;
}

void IntroState::OnLeave()
{
    cout << "Intro Left" << endl;
}

void IntroState::OnHide()
{
    cout << "Intro Hidden" << endl;
}

void IntroState::OnShow()
{
    cout << "Intro Revealed" << endl;
}

void IntroState::Update()
{
    cout << "Intro Updated" << endl;
    transition->Switch(std::shared_ptr<GESFML::State>(new PlayState()));
}
