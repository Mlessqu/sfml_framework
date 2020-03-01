//
// Created by missq on 01.03.2020.
//

#ifndef SFML_FRAMEWORK_STATE_H
#define SFML_FRAMEWORK_STATE_H
#include <SFML/Graphics.hpp>
class state {
public:
    virtual void pause() = 0;
    virtual void resume() = 0;
    virtual void handle_events(sf::Event &e)= 0;
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow &okno) = 0;
protected:
private:
};


#endif //SFML_FRAMEWORK_STATE_H
