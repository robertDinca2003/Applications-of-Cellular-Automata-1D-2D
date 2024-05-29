//
// Created by robert on 16.05.2024.
//

#include "ImageEncryption.h"
#include "MenuFactory.h"
#include "StrategyBlackWhite.h"
#include "StrategyColor.h"
#include "ImageEncryptionStrategy.h"
#include "ImageEncryptionContext.h"

ImageEncryption::ImageEncryption() {
    this->input = "";
    this->option = 0;
}

ImageEncryption::ImageEncryption(int opt, int mod) {
    this->input = "";
    this->option = opt;
    this->mode = mod;
}

void ImageEncryption::DisplayScreen(sf::RenderWindow *window) {
    std::string content[7];
    content[0] = "<--- Image Encryption --->\n";
    content[1] = "1. Select encryption mode: \n";
    if (this->option)
        content[1] += "Color Image\n";
    else
        content[1] += "Black & White Encryption\n";
    content[2] = "2. Set Image\n";
    content[3] = "3. Select Operation: \n";
    if (this->mode)
        content[3] += " Decrypt\n";
    else
        content[3] += " Encrypt\n";
    content[4] = "4. Process\n";
    content[5] = "5. Back\n";
    content[6] = "Images must be 500 x 500px\n";

    sf::Text text;
    sf::Font font;
    font.loadFromFile("myfont.ttf");

    text.setFont(font);
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::Blue);
    text.setPosition(20, 50);
    text.setLineSpacing(1.5);

    std::string display = "";
    for (int i = 0; i < 7; i++)
        display += content[i];
    text.setString(display);

    window->clear(sf::Color::White);
    window->draw(text);

    sf::Texture texture;
    if (this->option == 0 && this->mode == 0)
        texture.loadFromFile("bwInputEn.jpg");
    if (this->option == 1 && this->mode == 0)
        texture.loadFromFile("colorInputEn.jpg");
    if (this->option == 0 && this->mode == 1)
        texture.loadFromFile("bwInputDe.jpg");
    if (this->option == 1 && this->mode == 1)
        texture.loadFromFile("colorOutput2De.png");

    // Create a sprite and set its texture
    sf::Sprite sprite;
    sprite.setTexture(texture);

    // Set the position of the sprite
    sprite.setPosition(650.f, 50.f);

    window->draw(sprite);


    window->display();
}

void ImageEncryption::DisplayContent() const {
    std::cout << "<--- Image Encryption --->\n";
    std::cout << "1. Select encryption mode: ";
    if (this->option)
        std::cout << "Color Image\n";
    else
        std::cout << "Black & White Encryption\n";
    std::cout << "2. Set Image\n";
    std::cout << "3. Select Operation: ";
    if (this->mode)
        std::cout << "Decrypt\n";
    else
        std::cout << "Encrypt\n";
    std::cout << "4. Process\n";
    std::cout << "5. Back\n";
    std::cout << "Images must be 500 x 500px\n";
}

Menu *ImageEncryption::TakeInput(sf::RenderWindow *window, sf::Event *event) {

    ReadFromKeyBoard(&input, window, event, this, 100);
    if (this->input == "exit") {
        return MenuFactory::createMenuInstance(0);
    }
    if (this->input == "1") {
        this->option = 1 - this->option;
    } else if (this->input == "2") {
        this->DisplayScreen(window);
    } else if (this->input == "3") {
        this->mode = 1 - this->mode;
    } else if (this->input == "4") {
        ImageEncryptionContext cont;
        if (this->option) {
            cont.set_strategy(std::make_unique<StrategyColor>());

        } else {
//            StrategyBlackWhite strat;
            cont.set_strategy(std::make_unique<StrategyBlackWhite>());
        }

        cont.useStrategy(this->mode);
        cont.LogsFromEncryption();
    } else if (this->input == "5") {
        return MenuFactory::createMenuInstance(12);
    }

    return new ImageEncryption(this->option, this->mode);
}



