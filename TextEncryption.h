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
    std::string input;
    std::string message;
    std::string encryptedMessage;
    ElementaryRule *rule;
    ConwaysGameOfLife *game;
    std::vector<CryptMethods *> processes;
public:

    TextEncryption();

    TextEncryption(const TextEncryption&);

    TextEncryption &operator=(const TextEncryption &);

    TextEncryption(ElementaryRule *, ConwaysGameOfLife *, std::vector<CryptMethods *>, std::string);

    ~TextEncryption();

    static void setOption(int val);

    static int getOption();

    void Encrypt(int );

    void Decrypt();

    void DisplayScreen(sf::RenderWindow *) override;

    void DisplayContent() const override;

    Menu *TakeInput(sf::RenderWindow *, sf::Event *) override;
};

#endif //OOP_TEXTENCRYPTION_H
