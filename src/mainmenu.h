//
// Created by missq on 01.03.2020.
//

#ifndef SFML_FRAMEWORK_MAINMENU_H
#define SFML_FRAMEWORK_MAINMENU_H

#include"state.h"
#include <SFML/Graphics.hpp>
#include<iostream>//for debugs
class state;
extern sf::RenderWindow okno;
class mainmenu : public state{
public:
    virtual void pause();
    virtual void resume();
    virtual void handle_events(sf::Event &e);
    virtual void update();
    virtual void draw(sf::RenderWindow &window);
    mainmenu();
private:
    sf::CircleShape testowe_kolo;
    sf::RectangleShape testowy_kwadrat;
};


#endif //SFML_FRAMEWORK_MAINMENU_H
