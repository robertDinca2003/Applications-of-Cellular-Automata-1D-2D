//
// Created by robert on 03.04.2024.
//

#include "NewMain.h"
#include "MenuFactory.h"


void Main::DisplayContent() const {
   std::cout << "<--- Applications of Cellular Automata --->\n\n";
   std::cout << "1. Visualizations\n";
   std::cout << "2. Cryptography\n";
   std::cout << "3. Fractals\n";
   std::cout << "4. Exit\n";
}


void Main::DisplayScreen(sf::RenderWindow *window) {
    std::vector<std::string> content(5);

    content[0] = "<--- Applications of Cellular Automata --->\n\n";
    content[1] = "1. Visualization\n";
    content[2] = "2. Cryptography\n";
    content[3] = "3. Fractals\n";
    content[4] = "4. Exit";

    std::string display;
    for (int i = 0; i < 5; i++)
        display += content[i];

    sf::Font font;
    font.loadFromFile("myfont.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString(display);
    text.setCharacterSize(24);
    text.setPosition(100.f, 50.f);
    text.setFillColor(sf::Color::Blue);
    text.setLineSpacing(1.5f);

    window->clear(sf::Color::White);
    window->draw(text);
    window->display();
}


Menu *Main::TakeInput(sf::RenderWindow *window, sf::Event *event) {
    std::string input;
    ReadFromKeyBoard(&input, window, event, this, 100);
   std::cout << "I am here\n";
//    while(event->type != sf::Event::KeyPressed && event->type != sf::Event::Closed)window->pollEvent(*event);
   std::cout << "I got out\n";
//    if(event->type == sf::Event::Closed)return nullptr;
//    if(event->type == sf::Event::KeyPressed)
//    {input = to_string(char(event->key.code-26));
//       std::cout << event->key.code <<'\n';}
//    else input = "-1";
    if (input == "1") {
        return MenuFactory::createMenuInstance(11);
    }
    if (input == "2") {
        return MenuFactory::createMenuInstance(12);
    }
    if (input == "3") {
        return MenuFactory::createMenuInstance(13);
    }
    if (input == "4") {
        return MenuFactory::createMenuInstance(0);;
    }
    if (input == "exit")
        return MenuFactory::createMenuInstance(0);;

    return MenuFactory::createMenuInstance(1);;

}
