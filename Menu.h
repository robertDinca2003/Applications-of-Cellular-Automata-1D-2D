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

/// @brief Main - represent the main menu of the application
class Main : public Menu {
public:
    void DisplayContent() const override;

    void DisplayScreen(sf::RenderWindow *) override;

    Menu *TakeInput(sf::RenderWindow *, sf::Event *) override;

};

/// @brief Visualization - represent a submenu in which are presented different ways to visualize automata
class Visualization : public Menu {
    void DisplayContent() const override;

    void DisplayScreen(sf::RenderWindow *) override;

    Menu *TakeInput(sf::RenderWindow *, sf::Event *) override;
};

/// @brief Cryptography - represent a submenu, containing different ways to encrypt a photo or a text
class Cryptography : public Menu {
    void DisplayContent() const override;

    void DisplayScreen(sf::RenderWindow *) override;

    Menu *TakeInput(sf::RenderWindow *, sf::Event *) override;
};

/// @brief Fractal - represent a submenu, containing different types of fractals
class Fractal : public Menu {
    void DisplayContent() const override;

    void DisplayScreen(sf::RenderWindow *) override;

    Menu *TakeInput(sf::RenderWindow *, sf::Event *) override;
};

/// @brief WolframVisualMenu - is a menu to preset the settings of a elementary rule which will be generated
class WolframVisualMenu : public Menu {
private:
    int state;
    string input;
    int ruleNumber;
    int maxDepth;
    int maxLength;
    ElementaryRule *ruleSet;
public:
    explicit WolframVisualMenu(int state = 0, int ruleNumber = 255, int maxDepth = 30, int maxLength = 50,
                               ElementaryRule *ruleSet = new ElementaryRule(255, 30, 50));

    void DisplayScreen(sf::RenderWindow *) override;

    void DisplayContent() const override;

    friend void ReadFromKeyBoard(string *, sf::RenderWindow *, sf::Event *, Menu *, int);

    Menu *TakeInput(sf::RenderWindow *, sf::Event *) override;
};

/// @brief ConwaysVisualMenu - is a submenu used to make a the settings to generate a Conways' game of life
class ConwaysVisualMenu : public Menu {
private:
    int state;
    string input;
    ConwaysGameOfLife *game;
    bool preset;
public:
    explicit ConwaysVisualMenu();

    explicit ConwaysVisualMenu(int, bool, ConwaysGameOfLife *);

    void DisplayScreen(sf::RenderWindow *) override;

    void DisplayContent() const override;

    Menu *TakeInput(sf::RenderWindow *, sf::Event *) override;
};

class BelousovVisualMenu : public Menu{
private:
    int state;
    string input;
    Belousov *game;
public:

    explicit BelousovVisualMenu();

    explicit BelousovVisualMenu(int,int,int,int,int);

    void DisplayScreen(sf::RenderWindow *) override;

    void DisplayContent() const override;

    Menu *TakeInput(sf::RenderWindow*, sf::Event*) override;
};

#endif //OOP_MENU_H
