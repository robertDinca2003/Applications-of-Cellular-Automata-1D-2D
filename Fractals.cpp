//
// Created by robert on 03.04.2024.
//

#include "Fractals.h"


void Fractal::DisplayContent() const {
    cout << "<--- Fractals --->\n";
    cout << "1. Wolfram's Elementary Rules\n";
    cout << "2. More Fractals\n";
    cout << "3. Back\n";
}


void Fractal::DisplayScreen(sf::RenderWindow *window) {
    vector<string> content(4);
    content[0] = "<--- Fractals --->\n";
    content[1] = "1. Wolfram's Elementary Rules\n";
    content[2] = "2. More Fractals\n";
    content[3] = "3. Back\n";

    string display;
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


Menu *Fractal::TakeInput(sf::RenderWindow *window, sf::Event *event) {
    string input;
    cout << "I am here\n";
    ReadFromKeyBoard(&input, window, event, this, 100);
//    while(event->type != sf::Event::KeyPressed && event->type != sf::Event::Closed)window->pollEvent(*event);
//    cout << "I got out\n";
//    if(event->type == sf::Event::Closed)return nullptr;
//    if(event->type == sf::Event::KeyPressed)
//    {input = to_string(char(event->key.code-26));
//        cout << event->key.code <<'\n';}
    if (input == "1") {
        //Wolfram
        return new Fractal();
    }
    if (input == "2") {
        //More
        return new Fractal();
    }
    if (input == "3") {
        //Back
        return new Main();
    }
    if (input == "exit")
        return nullptr;

    return new Fractal();

}
