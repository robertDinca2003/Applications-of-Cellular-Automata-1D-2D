//
// Created by robert on 03.04.2024.
//

#ifndef OOP_WOLFRAMVISUALMENU_H
#define OOP_WOLFRAMVISUALMENU_H

#include "Menu.h"
#include "Visualization.h"

/// @brief WolframVisualMenu - is a menu to preset the settings of a elementary rule which will be generated
class WolframVisualMenu : public Menu {
private:
    int state;
    string input;
    int ruleNumber;
    int maxDepth;
    int maxLength;
    ElementaryRule *ruleSet;
public:
    explicit WolframVisualMenu(int state = 0, int ruleNumber = 255, int maxDepth = 30, int maxLength = 50,
                               ElementaryRule *ruleSet = new ElementaryRule(255, 30, 50));

    void DisplayScreen(sf::RenderWindow *) override;

    void DisplayContent() const override;

    friend void ReadFromKeyBoard(string *, sf::RenderWindow *, sf::Event *, Menu *, int);

    Menu *TakeInput(sf::RenderWindow *, sf::Event *) override;
};


#endif //OOP_WOLFRAMVISUALMENU_H
