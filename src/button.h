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
    std::function<void()> callback;

};


#endif //SFML_FRAMEWORK_BUTTON_H
