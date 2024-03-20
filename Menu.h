//
// Created by robert on 20.03.2024.
//

#ifndef OOP_MENU_H
#define OOP_MENU_H

#include <iostream>
#include <vector>
#include <string>
#include "ElementaryRule.h"

using namespace std;

class Menu{
private:
public:
    virtual void DisplayContent() const = 0;
    virtual Menu* TakeInput() = 0 ;
    Menu(){
        cout << "Constructed Menu\n";
    };
    virtual ~Menu(){cout << "Deconstructed Menu\n";}

    friend ostream &operator<<(ostream &os, const Menu &menu) {

        menu.DisplayContent();

        return os;
    }
};

class Main: public Menu{
public:
    void DisplayContent() const override;
    Menu* TakeInput() override;

};
class Visualization: public Menu{
    void DisplayContent() const override;
    Menu* TakeInput() override;
};
class Cryptography: public Menu{
    void DisplayContent() const override;
    Menu* TakeInput() override;
};
class Fractal: public Menu{
    void DisplayContent() const override;
    Menu* TakeInput() override;
};

class WolframVisualMenu: public Menu{
private:
    int state;
    int input;
    int ruleNumber;
    int maxDepth;
    int maxLength;
    ElementaryRule* ruleSet;
public:
    explicit WolframVisualMenu(int state = 0, int ruleNumber = 255, int maxDepth = 30, int maxLength = 50, ElementaryRule*ruleSet = new ElementaryRule(255,30,50));
    void DisplayContent() const override;
    Menu* TakeInput() override;
};

#endif //OOP_MENU_H
