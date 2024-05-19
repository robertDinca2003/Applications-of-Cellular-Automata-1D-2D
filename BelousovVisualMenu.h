//
// Created by robert on 03.04.2024.
//

#ifndef OOP_BELOUSOVVISUALMENU_H
#define OOP_BELOUSOVVISUALMENU_H

#include "Menu.h"
#include "Visualization.h"
#include "Belousov.h"

/// @brief BelousovVisualMenu - represent a submenu which let the user to change the values of a Belousov
class BelousovVisualMenu : public Menu {
private:
    int state;
    std::string input;
    Belousov *game;
public:

    explicit BelousovVisualMenu();

    explicit BelousovVisualMenu(int, int, int, int, int);

    void DisplayScreen(sf::RenderWindow *) override;

    void DisplayContent() const override;

    Menu *TakeInput(sf::RenderWindow *, sf::Event *) override;
};


#endif //OOP_BELOUSOVVISUALMENU_H
