//
// Created by missq on 29.02.2020.
//

#include "statemanager.h"
#include<iostream>

void statemanager::replace_state(state* to_what)
{
    states.pop_back();
    states.push_back(to_what);
    active_state = to_what;
}
void statemanager::push_state(state* what_to_add)
{
    states.push_back(what_to_add);
    active_state = what_to_add;
}
void statemanager::pop_state()
{
    states.pop_back();
    if(!states.empty())
    {
        active_state = states.back();
    }

}
void statemanager::handle_events(sf::Event &e)
{
    //if (e.type == sf::Event::Closed)
    //okno.close();
    active_state->handle_events(e);
}
void statemanager::update()
{
    active_state->update();
}
void statemanager::draw(sf::RenderWindow &okno)
{
    active_state->draw(okno);
}
statemanager* statemanager::singleton = nullptr;
statemanager* statemanager::getInstance()
{
    if(singleton==nullptr)
    {
        singleton = new statemanager();
        return singleton;
    }else return singleton;

}