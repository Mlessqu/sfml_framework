#include"statemanager.h"
#include"state.h"
#include "mainmenu.h"
#include <SFML/Graphics.hpp>
void init();
void cleanup();
sf::RenderWindow okno;
const int wysokosc = 600;
const int szerokosc = 800;
statemanager* stan;
mainmenu menu;
int main()
{
    init();
    while (okno.isOpen())
    {
        sf::Event event;
        while (okno.pollEvent(event))
        {
            stan->handle_events(event);
            stan->draw(okno);
            //if (event.type == sf::Event::Closed)
                //okno.close();
        }

    }
    cleanup();
    return 0;
}

void init()
{
    okno.create(sf::VideoMode(szerokosc,wysokosc),"mleczny framework!"); //sfml window creation
    stan = statemanager::getInstance(); //making that first and only statemanager instance
    stan->push_state(&menu);
}
void cleanup()
{
    delete stan;
}