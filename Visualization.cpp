//
// Created by robert on 03.04.2024.
//
#include "Visualization.h"
#include "MenuFactory.h"

void Visualization::DisplayContent() const {
   std::cout << "<--- Visualizations --->\n";
   std::cout << "1. Wolfram's Elementary rules\n";
   std::cout << "2. Conway's Game of Life\n";
   std::cout << "3. Belousov-Zhabotinsky\n";
   std::cout << "4. Custom 2D Cellular Automaton\n";
   std::cout << "5. Back\n";
}


void Visualization::DisplayScreen(sf::RenderWindow *window) {
    std::vector<std::string> content(6);

    content[0] = "<--- Visualization --->\n\n";
    content[1] = "1. Wolfram's Elementary Rules\n";
    content[2] = "2. Conway's Game of Life\n";
    content[3] = "3. Belousov-Zhabotinsky\n";
    content[4] = "4. Custom 2D automaton\n";
    content[5] = "5. Back";
    std::string display;


    for (int i = 0; i < 6; i++)
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


Menu *Visualization::TakeInput(sf::RenderWindow *window, sf::Event *event) {
    std::string input;
    ReadFromKeyBoard(&input, window, event, this, 100);
   std::cout << "I am here\n";
    //while(event->type != sf::Event::KeyPressed && event->type != sf::Event::Closed)window->pollEvent(*event);
   std::cout << "I got out\n";
    //if(event->type == sf::Event::Closed)return nullptr;
    //if(event->type == sf::Event::KeyPressed)
    // {input = to_string(char(event->key.code-26));
    //    std::cout << event->key.code <<'\n';}
   std::cout << input << " entered\n";
    if (input == "1") {
        //Wolfram
       std::cout << "I AM HERE NIGGA\n";
        return MenuFactory::createMenuInstance(111);;
    }
    if (input == "2") {
        //Conways
        return MenuFactory::createMenuInstance(112);;
    }
    if (input == "3") {
        //Belousov
        return MenuFactory::createMenuInstance(113);;
    }
    if (input == "4") {
        //Custom
        return MenuFactory::createMenuInstance(114);;
    }
    if (input == "5") {
        //Back
        return MenuFactory::createMenuInstance(1);;
    }
    if (input == "exit")
        return MenuFactory::createMenuInstance(0);;

    return MenuFactory::createMenuInstance(11);;

}