//
// Created by robert on 03.04.2024.
//

#include "BelousovVisualMenu.h"
#include "chrono"

BelousovVisualMenu::BelousovVisualMenu() {
    this->state = 0;
    Belousov *temp = new Belousov();
    this->game = temp;
    this->input = "";
}

BelousovVisualMenu::BelousovVisualMenu(int state, int q, int k1, int k2, int g) {
    this->state = state;
    Belousov *temp = new Belousov(q, k1, k2, g);
    this->game = temp;
    this->input = "";
}


void BelousovVisualMenu::DisplayContent() const {
    if (this->state == 0) {
        cout << "<--- Belousov-Zhabotinsky Visualization --->\n";
        cout << "1. Q: " << this->game->getQ() << "\n";
        cout << "2. K1: " << this->game->getK1() << "\n";
        cout << "3. K2: " << this->game->getK2() << "\n";
        cout << "4. G: " << this->game->getG() << "\n";
        cout << "5. Back\n";
    }
    if (this->state == 1) {
        cout << "<--- Belousov-Zhabotinsky Visualization --->\n";
        cout << "1. Back\n";
        cout << "2. Pause\n";
    }
}


void BelousovVisualMenu::DisplayScreen(sf::RenderWindow *window) {
    vector<string> content(10);
    content[0] = "<--- Belousov-Zhabotinsky Visualization --->\n";
    content[1] = "1. Q: " + to_string(this->game->getQ());
    content[2] = "\n2. K1: " + to_string(this->game->getK1());
    content[3] = "\n3. K2: " + to_string(this->game->getK2());
    content[4] = "\n4. G: " + to_string(this->game->getG());
    content[5] = "\n5. Generate";
    content[6] = "\n6. Back\n";
    content[7] = "<--- Belousov-Zhabotinsky Visualization --->\n";
    content[8] = "1. Back\n";
    content[9] = "2. Pause";

    sf::Text text;
    sf::Font font;
    font.loadFromFile("myfont.ttf");

    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Blue);
    text.setPosition(20, 50);

    string display = "";
    if (this->state == 0)
        for (int i = 0; i <= 6; i++)
            display += content[i];
    else
        for (int i = 7; i <= 9; i++)
            display += content[i];

    text.setString(display);

    window->clear(sf::Color::White);
    window->draw(text);
    if(this->state == 0)
    window->display();
}

Menu *BelousovVisualMenu::TakeInput(sf::RenderWindow *window, sf::Event *event) {
    string temp;
    int newQ = this->game->getQ();
    int newK1 = this->game->getK1();
    int newK2 = this->game->getK2();
    int newG = this->game->getG();
    cout << newQ << ' ' << newK1 << ' ' << newK2 << ' ' << newG << '\n';
    cout << "I am here\n";
    if (this->state == 0) {
        ReadFromKeyBoard(&input, window, event, this, 100);
        if (input == "1") {
            cout << "Insert new Q: \n";
            try{
                ReadFromKeyBoard(&temp, window, event, this, 255);
                if (temp == "exit")return nullptr;
                if(stoi(temp) <= newG)
                    throw runtime_error("Q can not be lower than G!\n");
                newQ = stoi(temp);
                if (newQ == 0) newQ++;

            }
            catch(const exception& e){
                cout << "Exception " << e.what() << endl;
            }

        }
        if (input == "2") {
            cout << "Insert new K1:\n";
            ReadFromKeyBoard(&temp, window, event, this, 8);
            if (temp == "exit")return nullptr;
            newK1 = stoi(temp);
            if (newK1 == 0)newK1++;
        }
        if (input == "3") {
            cout << "Insert new K2: \n";
            ReadFromKeyBoard(&temp, window, event, this, 8);
            if (temp == "exit")return nullptr;
            newK2 = stoi(temp);
            if (newK2 == 0)newK2++;
        }
        if (input == "4") {
            cout << "Insert new G: \n";
            try{
                ReadFromKeyBoard(&temp, window, event, this, 100);
                if (temp == "exit")return nullptr;
                if(stoi(temp) >= newQ){
                    throw runtime_error("G can not be larger than Q\n");
                }
                newG = stoi(temp);
                if (newG == 0)newG++;

            }catch (const exception &e){
                cout << "Exception " << e.what() << endl;
            }

        }
        if (input == "5") {
            this->state = 1;
        }
        if (input == "6") {
            delete this->game;
            return new Visualization();
        }
        if (input == "exit")
            return nullptr;
    } else if (this->state == 1) {
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
                        this->game->IncreaseInfection(xPos - 301.f, yPos - 71.f);
                    //cout << xPos << ' ' << yPos << '\n';


                }
                //cout << event->type <<'\n';
            }
            if (elapsedTime > keyPressDelay && !pause) {
                this->game->CreateNextGeneration();
                this->DisplayScreen(window);
                this->game->DisplayBelousov(window);
                lastKeyPressTime = now;
            }


            //cout << "itereation" << '\n';

        }
        delete this->game;
        return new BelousovVisualMenu(0, newQ, newK1, newK2, newG);
    }


    delete this->game;
    cout << newQ << ' ' << newK1 << ' ' << newK2 << ' ' << newG << '\n';
    return new BelousovVisualMenu(this->state, newQ, newK1, newK2, newG);
}

