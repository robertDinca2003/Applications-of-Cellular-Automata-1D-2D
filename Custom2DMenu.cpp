//
// Created by robert on 05.04.2024.
//

#include "Custom2DMenu.h"
#include <cmath>

void Custom2DMenu::DisplayContent() const {
    if(this->state == 0)
    {
        cout << "Custom 2D Automaton Visualization\n";
        cout << "1. Change Convolution Matrix\n";
        cout << "2. Change function\n";
        cout << "3. Generate\n";
        cout << "4. Back\n";
        for(int i = 0; i < 3; i++)
            {
                for(int j =0 ; j<3 ; j++)
                    cout << this->game->getKernelElem(i,j) << ' ';
                cout << '\n';
            }

    }
    if(this->state == 1)
    {
        cout << "Custom 2D Automaton Visualization\n";
        cout << "1. Back\n";
        cout << "2. Pause\n";
    }
}

void Custom2DMenu::DisplayScreen(sf::RenderWindow *window) {
        window->clear(sf::Color::White);
        vector<string> content(8);
        content[0] = "Custom 2D Automaton Visualization\n";
        content[1] = "1. Change Convolution Matrix\n";
        content[2] = "2. Change Function" + to_string(this->function) +"\n";
        content[3] = "3. Generate\n";
        content[4] = "4. Back\n";
        content[5] = "Custom 2D Automaton Visualization\n";
        content[6] = "1. Back\n";
        content[7] = "2. Pause\n";

        sf::Text text;
        sf::Font font;
        font.loadFromFile("myfont.ttf");
        text.setFillColor(sf::Color::Blue);
        text.setPosition(50,30);
        text.setLineSpacing(1.5);
        text.setFont(font);
        text.setCharacterSize(18);
        string display = "";

        if(this->state == 0)
            for(int i = 0; i<=4; i++)
                display+=content[i];
        else if (this->state == 1)
            for(int i = 5; i<= 6; i++)
                display+=content[i];

        text.setString(display);
        window->draw(text);

        sf::RectangleShape square(sf::Vector2(100.f,100.f));

        square.setOutlineColor(sf::Color::Blue);
        square.setOutlineThickness(2.5f);

        for(int i = 0 ; i< 3; i++)
            for(int j = 0; j< 3; j++)
            {
                square.setPosition(sf::Vector2(400.f+j*100.f , 200.f + i * 100.f));
                window->draw(square);
            }

        window->display();
}

Menu *Custom2DMenu::TakeInput(sf::RenderWindow *window, sf::Event *event) {
    if(this->state == 0)
    {
        ReadFromKeyBoard(&input, window, event, this, 10);
        if(input == "1")
        {
            for(int i = 0 ; i < 3 ; i++)
                for(int j = 0; j<3; j++)
                {
                    ReadFromKeyBoard(&input, window, event, this, 10);
                    if(input == "exit")
                    {
                        delete this->game;
                        return nullptr;
                    }

                    this->game->setKernelElem(i,j,fmax(stoi(input)/100.f,0.01));
                }
        }
        else if(input == "2")
        {
            ReadFromKeyBoard(&input, window, event, this, 10);
            if(input == "exit")
            {
                delete this->game;
                return nullptr;
            }
            this->function = stoi(input);
        }
        else if(input == "3")
        {
            this->state = 1;
        }
        else if(input == "4")
        {
            delete this->game;
            return new Visualization();
        }
        else if(input == "exit")
        {
            delete this->game;
            return nullptr;
        }

        return new Custom2DMenu(this->state,this->game,this->function);
    }
    if(this->state == 1)
    {

    }
}

Custom2DMenu::Custom2DMenu() {
    ConvolutionMatrix* temp = new ConvolutionMatrix(3);
    this->game  = temp;
    this->state = 0 ;
    this->input = "";
    this->function = 0;
}

Custom2DMenu::Custom2DMenu(int state,ConvolutionMatrix* game, int function) {
    this->game = game;
    this->function = function;
    this->state = state;
    this->input = "";

}
