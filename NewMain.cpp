//
// Created by robert on 03.04.2024.
//

#include "NewMain.h"


void Main::DisplayContent() const {
    cout << "<--- Applications of Cellular Automata --->\n\n";
    cout << "1. Visualizations\n";
    cout << "2. Cryptography\n";
    cout << "3. Fractals\n";
    cout << "4. Exit\n";
}


void Main::DisplayScreen(sf::RenderWindow *window) {
    vector<string> content(5);

    content[0] = "<--- Applications of Cellular Automata --->\n\n";
    content[1] = "1. Visualization\n";
    content[2] = "2. Cryptography\n";
    content[3] = "3. Fractals\n";
    content[4] = "4. Exit";

    string display;
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
    string input;
    ReadFromKeyBoard(&input, window, event, this, 100);
    cout << "I am here\n";
//    while(event->type != sf::Event::KeyPressed && event->type != sf::Event::Closed)window->pollEvent(*event);
    cout << "I got out\n";
//    if(event->type == sf::Event::Closed)return nullptr;
//    if(event->type == sf::Event::KeyPressed)
//    {input = to_string(char(event->key.code-26));
//        cout << event->key.code <<'\n';}
//    else input = "-1";
    if (input == "1") {
        return new Visualization();
    }
    if (input == "2") {
        return new Cryptography;
    }
    if (input == "3") {
        return new Fractal();
    }
    if (input == "4") {
        return nullptr;
    }
    if (input == "exit")
        return nullptr;

    return new Main();

}
