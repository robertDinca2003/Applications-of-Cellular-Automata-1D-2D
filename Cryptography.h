//
// Created by robert on 03.04.2024.
//

#ifndef OOP_CRYPTOGRAPHY_H
#define OOP_CRYPTOGRAPHY_H

#include "Menu.h"

/// @brief Cryptography - represent a submenu, containing different ways to encrypt a photo or a text
class Cryptography : public Menu {
    void DisplayContent() const override;

    void DisplayScreen(sf::RenderWindow *) override;

    Menu *TakeInput(sf::RenderWindow *, sf::Event *) override;
};


#endif //OOP_CRYPTOGRAPHY_H
