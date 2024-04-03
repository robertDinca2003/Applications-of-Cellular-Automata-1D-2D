//
// Created by robert on 20.03.2024.
//
#include <chrono>
#include "MyTools.cpp"
#include "Menu.h"


void ReadFromKeyBoard(string *input, sf::RenderWindow *window, sf::Event *event, Menu *men, int maxim) {
    int temp = 0;
    bool ok = false;
    string inputMes;

    sf::Text text;
    sf::Font font;
    font.loadFromFile("myfont.ttf");
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Blue);
    text.setPosition(25, 550);
    text.setString("Insert: ");
    men->DisplayScreen(window);
    window->draw(text);
    window->display();


    while (event->type == sf::Event::TextEntered && int(event->text.unicode) == 13)window->pollEvent(*event);


    while (!(event->type == sf::Event::TextEntered && int(event->text.unicode) == 13 && temp != 0) &&
           event->type != sf::Event::Closed) {

        if (window->pollEvent(*event) && event->type == sf::Event::TextEntered && ok) {
            //cout << event->key.code <<'\n';
            if (int(event->text.unicode) >= 48 && int(event->text.unicode) < 58) {
                temp = temp * 10 + static_cast<int>(event->text.unicode) - 48;
                if (temp > maxim) temp = maxim;
                cout << temp << '\n';
                inputMes = "Insert: " + to_string(temp);
                text.setString(inputMes);

                sf::RectangleShape clearRect(sf::Vector2f(250.f, 45.f));
                clearRect.setPosition(20.f, 540.f);
                clearRect.setFillColor(sf::Color::White);
                window->draw(clearRect);

                window->draw(text);
                window->display();
            }
            if (event->text.unicode == 8) {

                temp = temp / 10;

                cout << temp << '\n';
                inputMes = "Insert: " + to_string(temp);
                text.setString(inputMes);
                sf::RectangleShape clearRect(sf::Vector2f(250.f, 45.f));
                clearRect.setPosition(20.f, 540.f);
                clearRect.setFillColor(sf::Color::White);
                window->draw(clearRect);
                window->draw(text);
                window->display();

            }


        }


        ok = true;


    }
    if (event->type == sf::Event::Closed)
        *input = "exit";
    else {
        cout << "Inputed Value is " << temp << '\n';
        *input = to_string(temp);
    }
}


