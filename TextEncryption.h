//
// Created by robert on 16.04.2024.
//

#ifndef OOP_TEXTENCRYPTION_H
#define OOP_TEXTENCRYPTION_H


#include "Menu.h"
#include <string>
#include <vector>
#include "ElementaryRule.h"
#include "ConwaysGameOfLife.h"
class TextEncryption : public Menu {

private:
    static int option;
    string input;
    string message;
    string encryptedMessage;
    ElementaryRule *rule;
    ConwaysGameOfLife *game;
    vector<CryptMethods *> processes;
public:

    TextEncryption();

    TextEncryption(ElementaryRule *, ConwaysGameOfLife *, vector<CryptMethods *>, string);

    ~TextEncryption();

    static void setOption(int val);

    static int getOption();

    void Encrypt();

    void Decrypt();

    void DisplayScreen(sf::RenderWindow *) override;

    void DisplayContent() const override;

    Menu *TakeInput(sf::RenderWindow *, sf::Event *) override;
};

#endif //OOP_TEXTENCRYPTION_H
