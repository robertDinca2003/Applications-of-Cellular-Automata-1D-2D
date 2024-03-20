#include <iostream>
#include <array>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

#include <Helper.h>

//////////////////////////////////////////////////////////////////////
/// NOTE: this include is needed for environment-specific fixes     //
/// You can remove this include and the call from main              //
/// if you have tested on all environments, and it works without it //
#include "env_fixes.h"                                              //
//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////


int main() {
    ////////////////////////////////////////////////////////////////////////
    /// NOTE: this function call is needed for environment-specific fixes //
    init_threads();                                                       //
    ////////////////////////////////////////////////////////////////////////

    sf::RenderWindow window(sf::VideoMode(1200,600),"SFML Window");
    window.setFramerateLimit(60);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(500,200);
        window.draw(shape);
        window.display();
    }


    ///////////////////////////////////////////////////////////////////////////
    Helper helper;
    helper.help();
    ///////////////////////////////////////////////////////////////////////////

    return 0;
}
