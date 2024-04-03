//
// Created by robert on 03.04.2024.
//

#ifndef OOP_VISUALIZATION_H
#define OOP_VISUALIZATION_H

#include "Menu.h"
#include "Main.h"
#include "WolframVisualMenu.h"
#include "ConwaysVisualMenu.h"
#include "BelousovVisualMenu.h"

/// @brief Visualization - represent a submenu in which are presented different ways to visualize automata
class Visualization : public Menu {
    void DisplayContent() const override;

    void DisplayScreen(sf::RenderWindow *) override;

    Menu *TakeInput(sf::RenderWindow *, sf::Event *) override;
};


#endif //OOP_VISUALIZATION_H
