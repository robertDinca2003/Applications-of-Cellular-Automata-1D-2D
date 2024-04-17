//
// Created by robert on 05.04.2024.
//

#include "Custom2DMenu.h"
#include <cmath>
#include <chrono>





void Custom2DMenu::DisplayContent() const {
    if(this->state == 0)
    {
        cout << "Custom 2D Automaton Visualization\n";
        cout << "1. New Random Convolution Matrix\n";
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
        content[1] = "1. New Random Convolution Matrix\n";
        content[2] = "2. Change Function " + to_string(this->function) ;
        content[3] = "3. Generate\n";
        content[4] = "4. Back\n";
        content[5] = "Custom 2D Automaton Visualization\n";
        content[6] = "1. Back\n";
        content[7] = "2. Pause\n";

        if(this->function == 1) content[2] += ":  f(x) = x\n";
        else if(this->function == 2) content[2] += ":  f(x) = abs(x)\n";
        else if(this->function == 3) content[2] += ":  f(x) = sin(x)\n";
        else if(this->function == 4) content[2] += ":  f(x) = x^2\n";

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
            for(int i = 5; i<= 7; i++)
                display+=content[i];

        text.setString(display);
        window->draw(text);

        sf::RectangleShape square(sf::Vector2(100.f,100.f));

        square.setOutlineColor(sf::Color::Blue);
        square.setOutlineThickness(2.5f);
        if(this->state == 0)
        for(int i = 0 ; i< 3; i++)
            for(int j = 0; j< 3; j++)
            {
                square.setPosition(sf::Vector2(400.f+j*100.f , 200.f + i * 100.f));
                window->draw(square);
                text.setString(to_string(static_cast<int>(this->game->getKernelElem(i,j)*100)/100.f));
                text.setPosition(sf::Vector2(405.f+j*100.f, 240.f + i * 100.f));
                window->draw(text);
            }
    if(this->state == 0)
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
                    this->game->setKernelElem(i,j,(rand()%1000)/100.f-5.f);
                }
        }
        else if(input == "2")
        {
            ReadFromKeyBoard(&input, window, event, this, 4);
            if(input == "exit")
            {
                delete this->game;
                return nullptr;
            }
            this->function = stoi(input);
            this->game->setActFunc(this->function);
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
        int ok = 1;
        bool pause = 0;
        auto lastKeyPressTime = std::chrono::steady_clock::now();
        const auto keyPressDelay = std::chrono::milliseconds(200);

        while (window->isOpen() && ok) {
            auto now = std::chrono::steady_clock::now();
            auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastKeyPressTime);

            while (window->pollEvent(*event)) {
                if (event->type == sf::Event::Closed) {
                    delete this->game;
                    return nullptr;
                }
                if (event->type == sf::Event::KeyPressed && event->key.code == 27) {
                    ok = 0;
                    break;
                }
                if (event->type == sf::Event::KeyPressed && event->key.code == 28) {
                    pause = !pause;
                }
                if (event->type == sf::Event::MouseMoved) {
                    float xPos = event->mouseMove.x;
                    float yPos = event->mouseMove.y;
                    if (yPos >= 71.f && yPos <= 571.f && xPos >= 301.f && xPos <= 801.f)
                        this->game->MouseIncrease(yPos - 71.f, xPos - 301.f, 1);
                    //cout << xPos << ' ' << yPos << '\n';


                }
                //cout << event->type <<'\n';
            }
            if (elapsedTime > keyPressDelay && !pause) {
                this->game->CreateNextGeneration();
                this->DisplayScreen(window);
                this->game->DisplayConvolution(window);
                lastKeyPressTime = now;
            }


            //cout << "itereation" << '\n';

        }
        return new Custom2DMenu(0,new ConvolutionMatrix(3),this->function);
    }

    return this;
}

Custom2DMenu::Custom2DMenu() {
    ConvolutionMatrix* temp = new ConvolutionMatrix(3);
    this->game  = temp;
    this->state = 0 ;
    this->input = "";
    this->function = 1;
}

Custom2DMenu::Custom2DMenu(int state,ConvolutionMatrix* game, int function) {
    this->game = game;
    this->game->setActFunc(function);
    this->function = function;
    this->state = state;
    this->input = "";

}

