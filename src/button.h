//
// Created by missq on 02.03.2020.
//

#ifndef SFML_FRAMEWORK_BUTTON_H
#define SFML_FRAMEWORK_BUTTON_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include<functional>
class button {
public:
    button(){}
    button(sf::Vector2f,sf::Text temp);
    button(sf::Vector2f,sf::Text temp, std::function<void()> ftemp);

    std::function<void()> callback;
    //this is how you callback
    //przycisk.callback = [&]{menu.update();};
};


#endif //SFML_FRAMEWORK_BUTTON_H
