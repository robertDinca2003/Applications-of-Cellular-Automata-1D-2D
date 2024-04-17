//
// Created by robert on 05.04.2024.
//

#ifndef OOP_CUSTOM2DMENU_H
#define OOP_CUSTOM2DMENU_H

#include "Menu.h"
#include "Visualization.h"
#include "ConvolutionMatrix.h"


class Custom2DMenu: public Menu {
private:
    int state;
    int function;
    string input;
    ConvolutionMatrix* game;

public:

    Custom2DMenu();

    Custom2DMenu(int,ConvolutionMatrix*,int);

    float activationFunction(int func, float val);

    void DisplayContent() const override;

    void DisplayScreen(sf::RenderWindow *) override;

    Menu *TakeInput(sf::RenderWindow *, sf::Event *) override;

};


#endif //OOP_CUSTOM2DMENU_H
