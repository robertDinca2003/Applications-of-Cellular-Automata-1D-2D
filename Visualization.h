//
// Created by robert on 03.04.2024.
//

#ifndef OOP_VISUALIZATION_H
#define OOP_VISUALIZATION_H

#include "Menu.h"
#include "NewMain.h"
#include "WolframVisualMenu.h"
#include "ConwaysVisualMenu.h"
#include "BelousovVisualMenu.h"
#include "Custom2DMenu.h"

/// @brief Visualization - represent a submenu in which are presented different ways to visualize automata
class Visualization : public Menu {
    void DisplayContent() const override;

    void DisplayScreen(sf::RenderWindow *) override;

    Menu *TakeInput(sf::RenderWindow *, sf::Event *) override;
};


#endif //OOP_VISUALIZATION_H
