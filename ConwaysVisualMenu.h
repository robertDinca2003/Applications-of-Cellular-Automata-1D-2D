//
// Created by robert on 03.04.2024.
//

#ifndef OOP_CONWAYSVISUALMENU_H
#define OOP_CONWAYSVISUALMENU_H

#include "Menu.h"
#include "Visualization.h"
#include "ConwaysGameOfLife.h"


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


#endif //OOP_CONWAYSVISUALMENU_H
