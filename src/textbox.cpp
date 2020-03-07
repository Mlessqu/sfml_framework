//
// Created by missq on 07.03.2020.
//

#include "textbox.h"
// Define keys:
#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27
textbox::textbox(int size, sf::Color color, bool sel) {
    text_in_textbox.setCharacterSize(size);
    text_in_textbox.setColor(color);
    is_selected = sel;

    // Check if the textbox is selected upon creation and display it accordingly:
    if(is_selected)
        text_in_textbox.setString("_");
    else
        text_in_textbox.setString("");
}

// Make sure font is passed by reference:
void textbox::setFont(sf::Font &fonts) {
    text_in_textbox.setFont(fonts);
}

void textbox::setPosition(sf::Vector2f point) {
    text_in_textbox.setPosition(point);
}

// Set char limits:
void textbox::set_limit(bool ToF) {
    has_limit = ToF;
}

void textbox::set_limit(bool ToF, int lim) {
    has_limit = ToF;
    limit = lim - 1;
}

// Change selected state:
void textbox::set_selected(bool sel) {
    is_selected = sel;

    // If not selected, remove the '_' at the end:
    if (!sel) {
        std::string t = text.str();
        std::string newT = "";
        for (int i = 0; i < t.length(); i++) {
            newT += t[i];
        }
        text_in_textbox.setString(newT);
    }
}


// Function for event loop:
void textbox::typed_on(sf::Event input) {
    if (is_selected) {
        int charTyped = input.text.unicode;

        // Only allow normal inputs:
        if (charTyped < 128) {
            if (has_limit) {
                // If there's a limit, don't go over it:
                if (text.str().length() <= limit) {
                    input_logic(charTyped);
                }
                    // But allow for char deletions:
                else if (text.str().length() > limit && charTyped == DELETE_KEY) {
                    delete_last();
                }
            }
                // If no limit exists, just run the function:
            else
                {
                input_logic(charTyped);
            }
        }
    }
}

// Delete the last character of the text:
void textbox::delete_last() {
    std::string t = text.str();
    std::string newT = "";
    for (int i = 0; i < t.length() - 1; i++) {
        newT += t[i];
    }
    text.str("");
    text << newT;
    text_in_textbox.setString(text.str() + "_");
}

// Get user input:
void textbox::input_logic(int charTyped) {
    // If the key pressed isn't delete, or the two selection keys, then append the text with the char:
    if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
        text << static_cast<char>(charTyped);
    }
        // If the key is delete, then delete the char:
    else if (charTyped == DELETE_KEY) {
        if (text.str().length() > 0) {
            delete_last();
        }
    }
    // Set the textbox text:
    text_in_textbox.setString(text.str() + "_");
}