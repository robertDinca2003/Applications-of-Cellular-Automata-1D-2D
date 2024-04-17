//
// Created by robert on 03.04.2024.
//

#include "Cryptography.h"
#include "NewMain.h"
#include "TextEncryption.h"


void Cryptography::DisplayContent() const {
    std::cout << "<--- Cryptography --->\n";
    std::cout << "1. Image Encryption\n";
    std::cout << "2. Text Encryption\n";
    std::cout << "3. Back\n";
}


void Cryptography::DisplayScreen(sf::RenderWindow *window) {

    std::vector<std::string> content(4);

    content[0] = "<--- Cryptography --->\n\n";
    content[1] = "1. Image Encryption\n";
    content[2] = "2. Text Encryption\n";
    content[3] = "3. Back\n";


    std::string display;
    for (int i = 0; i < 4; i++)
        display += content[i];

    sf::Font font;
    font.loadFromFile("myfont.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString(display);
    text.setCharacterSize(24);
    text.setPosition(300.f, 50.f);
    text.setFillColor(sf::Color::Blue);
    text.setLineSpacing(1.5f);

    window->clear(sf::Color::White);
    window->draw(text);
    window->display();
}


Menu *Cryptography::TakeInput(sf::RenderWindow *window, sf::Event *event) {
    std::string input;
    std::cout << "I am here\n";
    ReadFromKeyBoard(&input, window, event, this, 100);
    //    while(event->type != sf::Event::KeyPressed && event->type != sf::Event::Closed)window->pollEvent(*event);
//   std::cout << "I got out\n";
//    if(event->type == sf::Event::Closed)return nullptr;
//    if(event->type == sf::Event::KeyPressed)
//    {input = to_string(char(event->key.code-26));
//       std::cout << event->key.code <<'\n';}
    if (input == "1") {
        //Image
        return new Cryptography();
    }
    if (input == "2") {
        //Text
        return new TextEncryption();
    }
    if (input == "3") {
        //Back
        return new Main();
    }
    if (input == "exit")
        return nullptr;

    return new Cryptography();

}