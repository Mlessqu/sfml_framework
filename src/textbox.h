//
// Created by missq on 07.03.2020.
//

#ifndef SFML_FRAMEWORK_TEXTBOX_H
#define SFML_FRAMEWORK_TEXTBOX_H
#include<iostream>
#include<sstream>
#include<SFML/Graphics.hpp>

class textbox {
public:
    textbox(){}
    textbox(int size, sf::Color kolor, bool sel);
    void setFont(sf::Font &fonts);
    void setPosition(sf::Vector2f temp);
    //set char limit
    void set_limit(bool ToF);
    void set_limit(bool ToF, int lim);
    void set_selected(bool sel);
    std::string get_text() { return text.str();}
    void draw_to(sf::RenderWindow &window){ window.draw(text_in_textbox);}
    void typed_on(sf::Event input);
private:
    sf::Text text_in_textbox;
    std::ostringstream text;
    bool is_selected = false;
    bool has_limit = false;
    int limit = 0;
    void delete_last();
    void input_logic(int char_typed);
};


#endif //SFML_FRAMEWORK_TEXTBOX_H
