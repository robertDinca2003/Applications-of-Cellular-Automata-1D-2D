//
// Created by robert on 03.04.2024.
//

#include "Fractals.h"
#include "MenuFactory.h"


void Fractals::DisplayContent() const {
    std::cout << "<--- Fractals --->\n";
    std::cout << "1. Wolfram's Elementary Rules\n";
    std::cout << "2. More Fractals\n";
    std::cout << "3. Back\n";
}


void Fractals::DisplayScreen(sf::RenderWindow *window) {
    std::vector<std::string> content(4);
    content[0] = "<--- Fractals --->\n";
    content[1] = "1. Wolfram's Elementary Rules\n";
    content[2] = "2. More Fractals\n";
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


Menu *Fractals::TakeInput(sf::RenderWindow *window, sf::Event *event) {
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
        //Wolfram
        return MenuFactory::createMenuInstance(131);
    }
    if (input == "2") {
        //More
        return MenuFactory::createMenuInstance(132);
    }
    if (input == "3") {
        //Back
        return MenuFactory::createMenuInstance(1);
    }
    if (input == "exit")
        return nullptr;

    return MenuFactory::createMenuInstance(13);

}
