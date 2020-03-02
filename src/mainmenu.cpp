//
// Created by missq on 01.03.2020.
//

#include "mainmenu.h"
mainmenu::mainmenu()
{
    testowy_kwadrat.setSize(sf::Vector2f(100, 50));
    testowy_kwadrat.setOutlineColor(sf::Color::Red);
    testowy_kwadrat.setOutlineThickness(5);
    testowy_kwadrat.setPosition(10, 20);
    testowe_kolo.setPosition(30,50);
    testowe_kolo.setFillColor(sf::Color::Black);
    testowe_kolo.setRadius(20);
}
void mainmenu::pause() {}
void mainmenu::resume() {}
void mainmenu::handle_events(sf::Event &e)
{
    if (e.type == sf::Event::Closed)
        okno.close();
    if (e.type == sf::Event::KeyPressed)
    {
        if (e.key.code == sf::Keyboard::Escape)
        {
            std::cout << "the escape key was pressed" << std::endl;
            okno.close();
        }
    }
}

void mainmenu::update()
{
    std::cout << "I just got callbacked! YAY";
}
void mainmenu::draw(sf::RenderWindow &window)
{
    window.clear(sf::Color::Blue);
    window.draw(testowy_kwadrat);
    window.draw(testowe_kolo);
}