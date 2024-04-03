//
// Created by robert on 03.04.2024.
//

#ifndef OOP_FRACTALS_H
#define OOP_FRACTALS_H

#include "Menu.h"
#include "NewMain.h"

/// @brief Fractal - represent a submenu, containing different types of fractals
class Fractal : public Menu {
    void DisplayContent() const override;

    void DisplayScreen(sf::RenderWindow *) override;

    Menu *TakeInput(sf::RenderWindow *, sf::Event *) override;
};


#endif //OOP_FRACTALS_H
