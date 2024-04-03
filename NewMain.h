//
// Created by robert on 03.04.2024.
//

#ifndef OOP_NEWMAIN_H
#define OOP_NEWMAIN_H

#include "Menu.h"
#include "Visualization.h"
#include "Fractals.h"
#include "Cryptography.h"

/// @brief Main - represent the main menu of the application
class Main : public Menu {
public:

    Main() = default;

    void DisplayContent() const override;

    void DisplayScreen(sf::RenderWindow *) override;

    Menu *TakeInput(sf::RenderWindow *, sf::Event *) override;

};


#endif //OOP_NEWMAIN_H
