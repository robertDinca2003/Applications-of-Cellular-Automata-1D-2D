//
// Created by robert on 16.05.2024.
//

#ifndef OOP_IMAGEENCRYPTION_H
#define OOP_IMAGEENCRYPTION_H
#include <utility>
#include <memory>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "Menu.h"
#include "ElementaryRule.h"
#include "ImageEncryptionStrategy.h"





class ImageEncryption: public Menu{

private:

    int option;
    int mode;
    std::string input;

public:

    ImageEncryption();

    ImageEncryption(int,int);

    void DisplayScreen(sf::RenderWindow *) override;

    void DisplayContent() const override;

    Menu *TakeInput(sf::RenderWindow *, sf::Event *) override;

};

#endif //OOP_IMAGEENCRYPTION_H
