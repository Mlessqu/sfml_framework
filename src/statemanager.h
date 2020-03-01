//
// Created by missq on 29.02.2020.
//
/*mleko*/
/*"The real main function class", siungleton that will manage what state should be currently active, drawn, listened to etc. */

#ifndef SFML_FRAMEWORK_STATEMANAGER_H
#define SFML_FRAMEWORK_STATEMANAGER_H
#include "state.h"
#include<vector>
#include <SFML/Graphics.hpp>
extern sf::RenderWindow okno;

class statemanager {
public:
    void replace_state(state* to_what);
    void push_state(state* what_to_add);
    void pop_state();
    void handle_events(sf::Event &e);
    void update();
    void draw(sf::RenderWindow &okno);
    //singleton function
    static statemanager* getInstance();
private:
    state* active_state;
    static statemanager* singleton;
    std::vector<state*> states;
    statemanager(){}
};


#endif //SFML_FRAMEWORK_STATEMANAGER_H
