#include <iostream>
#include <array>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

#include <Helper.h>

//#include "ElementaryRule.h"


//////////////////////////////////////////////////////////////////////
/// NOTE: this include is needed for environment-specific fixes     //
/// You can remove this include and the call from main              //
/// if you have tested on all environments, and it works without it //
//#include "env_fixes.h"                                              //
//////////////////////////////////////////////////////////////////////
#include "Menu.h"
#include "NewMain.h"


//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
void runGame(Menu *current, sf::RenderWindow *window, sf::Event *event) {

    while (window->isOpen())
        while (window->pollEvent(*event)) {
            if (event->type == sf::Event::Closed)
                window->close();
            if (current == nullptr) {
                window->close();
                return;
            } else {


                cout << *current;
                current->DisplayScreen(window);
                current->DisplayContent();
                cout << "\n\nI want to take input !! \n\n";
                Menu *next = current->TakeInput(window, event);
                cout << "\n\n Input took \n\n";
                delete current;
                runGame(next, window, event);
            }
        }


}

int main() {
    ////////////////////////////////////////////////////////////////////////
    /// NOTE: this function call is needed for environment-specific fixes //
    //init_threads();                                                       //
    ////////////////////////////////////////////////////////////////////////




    ElementaryRule rule30(30);
    rule30.DisplayCurrentGeneration();
    rule30.CreateNextGen();
    rule30.DisplayCurrentGeneration();
    rule30.CreateNextGen();
    rule30.DisplayCurrentGeneration();
    rule30.MultipleGeneration(15);
    rule30.UpdateCurrGeneration(10);
    rule30.DisplayCurrentGeneration();
    rule30.DisplayUpToCurrentGeneration();
    rule30.MultipleGeneration(25);
    rule30.DisplayUpToCurrentGeneration();
    rule30.DisplayAll();
    cout << '\n' << rule30.getCurrGenNumber() << ' ' << rule30.getRuleNumber() << '\n';
    for (int x: rule30.getCurrGeneration())
        cout << x << ' ';
    cout << '\n';
    for (int x: rule30.getStartGen())
        cout << x << ' ';
    cout << '\n';
    cout << rule30 << '\n';
    rule30.setMaxDepth(50);
    rule30.setMaxLength(100);
    cout << rule30 << '\n';
    ElementaryRule copyRule = rule30;
    cout << copyRule << '\n';

    sf::RenderWindow window(sf::VideoMode(1200, 600), "SFML Window");
    window.setFramerateLimit(60);
    sf::Event event;
    sf::Font font;
    if (!font.loadFromFile("myfont.ttf"))
        return EXIT_FAILURE;

    sf::Text text;
    text.setFont(font);
    text.setString("Cellular Automata");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Blue);
    text.setPosition(400.f, 250.f);

    window.clear(sf::Color::White);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(500, 200);
    window.draw(shape);
    window.draw(text);
    window.display();

    runGame(new Main(), &window, &event);





    ///////////////////////////////////////////////////////////////////////////
    Helper helper;
    helper.help();
    ///////////////////////////////////////////////////////////////////////////

    return 0;
}
