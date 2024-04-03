//
// Created by robert on 20.03.2024.
//

#ifndef OOP_MENU_H
#define OOP_MENU_H

#include <iostream>
#include <vector>
#include <string>
#include "ElementaryRule.h"
#include "ConwaysGameOfLife.h"
#include "Belousov.h"
#include <SFML/Graphics.hpp>

using namespace std;

/// @brief Menu is a class which is used for the navigation menu of the program
class Menu {
private:
public:
    /// @brief DisplayContent - used for displaying the current menu
    virtual void DisplayContent() const = 0;

    virtual void DisplayScreen(sf::RenderWindow *) = 0;

    /// @brief TakeInput - used for taking the user input and process it
    virtual Menu *TakeInput(sf::RenderWindow *, sf::Event *) = 0;

    /// @brief ReadFromKeyBoard - is a extern function of the class, used to read an input from the keyboard
    friend void ReadFromKeyBoard(string *, sf::RenderWindow *, sf::Event *, Menu *, int);

    Menu() {
        cout << "Constructed Menu\n";
    };

    /// @brief Deconstruct
    virtual ~Menu() { cout << "Deconstructed Menu\n"; }

    /// @brief operator<<
    friend ostream &operator<<(ostream &os, const Menu &menu) {

        menu.DisplayContent();
        return os;
    }
};


#endif //OOP_MENU_H
