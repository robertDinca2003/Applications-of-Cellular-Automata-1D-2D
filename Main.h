//
// Created by robert on 03.04.2024.
//

#ifndef OOP_MAIN_H
#define OOP_MAIN_H

#include "Menu.h"
#include "Visualization.h"
#include "Fractals.h"
#include "Cryptography.h"

/// @brief Main - represent the main menu of the application
class Main : public Menu {
public:
    void DisplayContent() const override;

    void DisplayScreen(sf::RenderWindow *) override;

    Menu *TakeInput(sf::RenderWindow *, sf::Event *) override;

};


#endif //OOP_MAIN_H
