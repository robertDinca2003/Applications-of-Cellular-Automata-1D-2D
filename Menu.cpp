//
// Created by robert on 20.03.2024.
//
#include <chrono>
#include "MyTools.cpp"
#include "Menu.h"


void DisplayBufferContent(ElementaryRule *ruleSet, sf::RenderWindow *window) {

    int height = ruleSet->getMaxDepth();
    int length = ruleSet->getMaxLength();
    int currHeight = ruleSet->getCurrGenNumber();
    float pixelSize = min(1100.f / length, 435.f / height);
    float startX = (1180 - pixelSize * length) / 2.f;
    float startY = 100.f;

    sf::RectangleShape pixel(sf::Vector2f(pixelSize, pixelSize));

    for (int i = 0; i < height; i++)
        for (int j = 0; j < length; j++) {
            pixel.setPosition(startX + j * pixelSize, startY + i * pixelSize);
            if (ruleSet->getElement(i, j) == 1 && i <= currHeight)
                pixel.setFillColor(sf::Color::Blue);
            else
                pixel.setFillColor(sf::Color::White);
            window->draw(pixel);
        }
    window->display();
}

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

WolframVisualMenu::WolframVisualMenu(int state, int ruleNumber, int maxDepth, int maxLength, ElementaryRule *ruleSet) {
    this->state = state;
    this->ruleNumber = ruleNumber;
    this->maxDepth = maxDepth;
    this->maxLength = maxLength;
    this->input = "0";
    this->ruleSet = ruleSet;
}

ConwaysVisualMenu::ConwaysVisualMenu(int state, bool preset, ConwaysGameOfLife *game) {
    this->state = state;
    this->game = game;
    this->input = "";
    this->preset = preset;
}

ConwaysVisualMenu::ConwaysVisualMenu() {
    this->state = 0;
    ConwaysGameOfLife *temp = new ConwaysGameOfLife();
    this->game = temp;
    this->input = "";
    this->preset = false;
}

BelousovVisualMenu::BelousovVisualMenu() {
    this->state = 0;
    Belousov *temp = new Belousov();
    this->game = temp;
    this->input = "";
}

BelousovVisualMenu::BelousovVisualMenu(int state,int q, int k1, int k2, int g) {
    this->state = state;
    Belousov* temp = new Belousov(q,k1,k2,g);
    this->game = temp;
    this->input = "";
}

void Main::DisplayContent() const {
    cout << "<--- Applications of Cellular Automata --->\n\n";
    cout << "1. Visualizations\n";
    cout << "2. Cryptography\n";
    cout << "3. Fractals\n";
    cout << "4. Exit\n";
}

void Visualization::DisplayContent() const {
    cout << "<--- Visualizations --->\n";
    cout << "1. Wolfram's Elementary rules\n";
    cout << "2. Conway's Game of Life\n";
    cout << "3. Belousov-Zhabotinsky\n";
    cout << "4. Custom 2D Cellular Automaton\n";
    cout << "5. Back\n";
}

void Cryptography::DisplayContent() const {
    cout << "<--- Cryptography --->\n";
    cout << "1. Image Encryption\n";
    cout << "2. Text Encryption\n";
    cout << "3. Back\n";
}


void Fractal::DisplayContent() const {
    cout << "<--- Fractals --->\n";
    cout << "1. Wolfram's Elementary Rules\n";
    cout << "2. More Fractals\n";
    cout << "3. Back\n";
}


void WolframVisualMenu::DisplayContent() const {
    if (this->state == 0) {
        cout << "<--- Wolfram's Rules Visualization --->\n";
        cout << "Select (1, 2, 3) to change\nCurrent Settings:\n";
        cout << "1. Current Rule:" << this->ruleNumber << "\n";
        cout << "2. Maximum Length:" << this->maxLength << "\n";
        cout << "3. Maximum Depth:" << this->maxDepth << "\n";
        cout << "\n4. Generate!\n";
        cout << "5. Go Back\n";
    }
    if (this->state == 1) {
        cout << "<-- Wolfram's Rule " << this->ruleNumber << " -->\n";
        cout << "1. Next Generation\n";
        cout << "2. Previous Generation\n";
        cout << "3. Go to a generation by number\n";
        cout << "4. Complete all generation\n";
        cout << "5. Back\n";

        cout << this->ruleSet->getCurrGenNumber() << '\n';
        //ruleSet->DisplayCurrentGeneration();
        cout << '\n';
        //ruleSet->DisplayUpToCurrentGeneration();
    }
}

void ConwaysVisualMenu::DisplayContent() const {
    if (this->state == 0) {
        cout << "<--- Game of Life Visualization --->\n";
        cout << "1. Number of initial cells: " << this->game->getInitNrCells() << "\n";
        cout << "2. Use Preset\n";
        cout << "3. Generate\n";
        cout << "4. Back\n";
    }
    if (this->state == 1) {
        cout << "<--- Game of Life Visualization --->\n";
        cout << "1. Stop\n 2. Back\n";
    }
}

void BelousovVisualMenu::DisplayContent() const {
    if(this->state == 0){
        cout << "<--- Belousov-Zhabotinsky Visualization --->\n";
        cout << "1. Q: " << this->game->getQ() << "\n";
        cout << "2. K1: " << this->game->getK1() << "\n" ;
        cout << "3. K2: " << this->game->getK2() << "\n";
        cout << "4. G: " << this->game->getG() << "\n";
        cout << "5. Back\n";
    }
    if(this->state == 1){
        cout << "<--- Belousov-Zhabotinsky Visualization --->\n";
        cout << "1. Back\n";
        cout << "2. Pause\n";
    }
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

void Visualization::DisplayScreen(sf::RenderWindow *window) {
    vector<string> content(6);

    content[0] = "<--- Visualization --->\n\n";
    content[1] = "1. Wolfram's Elementary Rules\n";
    content[2] = "2. Conway's Game of Life\n";
    content[3] = "3. Belousov-Zhabotinsky\n";
    content[4] = "4. Custom 2D automaton\n";
    content[5] = "5. Back";
    string display;


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

void Cryptography::DisplayScreen(sf::RenderWindow *window) {

    vector<string> content(4);

    content[0] = "<--- Cryptography --->\n\n";
    content[1] = "1. Image Encryption\n";
    content[2] = "2. Text Encryption\n";
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

void WolframVisualMenu::DisplayScreen(sf::RenderWindow *window) {
    vector<string> content(14);
    content[0] = "<--- Wolfram's Rules Visualization --->\n";
    content[1] = "Select (1 , 2 ,3) to change \nCurrent settings\n";
    content[2] = "1. Current Rule: " + to_string(this->ruleNumber);
    content[3] = "\n2. Maximum Length: " + to_string(this->maxLength);
    content[4] = "\n3. Maximum Depth: " + to_string(this->maxDepth);
    content[5] = "\n4. Generate";
    content[6] = "\n5. Back\n";
    content[7] = "<--- Wolfram's Rules " + to_string(this->ruleNumber) + " --->\n";
    content[8] = "1. Next Generation\n";
    content[9] = "2. Previous Generation\n";
    content[10] = "3. Go To A Generation\n   By Number\n";
    content[11] = "4. Complete All Generation\n";
    content[12] = "5. Back\n";
    content[13] = "";

    string display;
    for (int i = 0; i < 7; i++) {
        display += content[i + this->state * 7];
    }
    sf::Font font;
    font.loadFromFile("myfont.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString(display);
    if (this->state == 0) {
        text.setCharacterSize(24);
        text.setPosition(150.f, 50.f);

    } else {
        text.setCharacterSize(8);
        text.setPosition(30.f, 10.f);

    }
    text.setFillColor(sf::Color::Blue);
    text.setLineSpacing(1.5f);

    window->clear(sf::Color::White);
    window->draw(text);
    if (this->state == 1)
        DisplayBufferContent(this->ruleSet, window);
    else
        window->display();

}

void ConwaysVisualMenu::DisplayScreen(sf::RenderWindow *window) {
    vector<string> content(10);
    content[0] = "<--- Game of Life Visualization --->\n";
    content[1] = "1. Number of initial cells: " + to_string(this->game->getInitNrCells());
    content[2] = "\n2. Height: " + to_string(this->game->getHeight());
    content[3] = "\n3. Width: " + to_string(this->game->getLength());
    content[4] = "\n4. Use Preset\n";
    content[5] = "5. Generate\n";
    content[6] = "6. Back\n";
    content[7] = "<--- Game of Life Visualization --->\n";
    content[8] = "     1. Stop            ";
    content[9] = "2. Back\n";

    sf::Text text;
    sf::Font font;
    font.loadFromFile("myfont.ttf");

    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Blue);

    window->clear(sf::Color::White);
    string display = "";
    if (this->state == 0)
        for (int i = 0; i < 7; i++)
            display += content[i];
    else
        for (int i = 7; i < 10; i++)
            display += content[i];
    text.setString(display);
    if (this->state == 0)
        text.setPosition(150.f, 100.f);
    else
        text.setPosition(150.f, 10.f);
    text.setLineSpacing(1.5f);
    window->draw(text);
    window->display();

    if (this->state == 0) {
        text.setCharacterSize(24);
        text.setPosition(150.f, 50.f);

    } else {
        text.setCharacterSize(8);
        text.setPosition(30.f, 10.f);

    }
    text.setFillColor(sf::Color::Blue);
    text.setLineSpacing(1.5f);

    window->clear(sf::Color::White);
    window->draw(text);
}

void BelousovVisualMenu::DisplayScreen(sf::RenderWindow *window)
{
    vector<string>content(10);
    content[0] = "<--- Belousov-Zhabotinsky Visualization --->\n";
    content[1] = "1. Q: "+ to_string(this->game->getQ());
    content[2] = "\n2. K1: "+ to_string(this->game->getK1());
    content[3] = "\n3. K2: "+ to_string(this->game->getK2());
    content[4] = "\n4. G: "+ to_string(this->game->getG());
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
    text.setPosition(20,50);

    string display = "";
    if(this->state == 0)
        for(int i =0 ;i<=6; i++)
            display+=content[i];
    else
        for(int i = 7; i<=9; i++)
            display+=content[i];

    text.setString(display);

    window->clear(sf::Color::White);
    window->draw(text);
    window->display();
}

Menu *WolframVisualMenu::TakeInput(sf::RenderWindow *window, sf::Event *event) {
    cout << "\nCurrent Input: ";
    cout << "I am here\n";
//    while(event->type != sf::Event::KeyPressed && event->type != sf::Event::Closed)window->pollEvent(*event);
//    cout << "I got out\n";
//    if(event->type == sf::Event::Closed)return nullptr;
//    if(event->type == sf::Event::KeyPressed)input = event->key.code-26;
    ReadFromKeyBoard(&input, window, event, this, 10);

    int rNum = this->ruleNumber;
    int mLen = this->maxLength;
    int mDep = this->maxDepth;
    int cState = this->state;
    if (this->state == 0) {
        string temp;
        //int temp = 0;
        //1bool ok;
        sf::Text text;
        sf::Font font;
        font.loadFromFile("myfont.ttf");
        text.setFont(font);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Blue);
        text.setPosition(25, 550);


        string inputMes = "Insert:";
        text.setString(inputMes);
        this->DisplayScreen(window);
        window->draw(text);

        if (input != "exit") {
            switch (stoi(input)) {
                case 1:
                    cout << "Insert new rule number: ";
                    ReadFromKeyBoard(&temp, window, event, this, 255);
                    cout << temp << '\n';
                    if (temp == "exit")return nullptr;
                    rNum = stoi(temp);
                    break;
                case 2:
                    cout << "Insert new maximum length: ";
                    ReadFromKeyBoard(&temp, window, event, this, 1100);
                    if (temp == "exit")return nullptr;
                    mLen = stoi(temp);
                    break;
                case 3:
                    cout << "Insert new maximum depth: ";
                    //window->pollEvent(*event);
                    ReadFromKeyBoard(&temp, window, event, this, 435);

                    if (temp == "exit")return nullptr;
                    mDep = stoi(temp);
                    if (mDep == 0)
                        mDep = 1;
                    break;
                case 4:
                    cState = 1;
                    //runWolframVisualization(rNum,mLen,mDep);
                    break;
                case 5:
                    delete this->ruleSet;
                    return new Visualization();
            }
        } else {
            return nullptr;
        }

        delete this->ruleSet;
        return new WolframVisualMenu(cState, rNum, mDep, mLen, new ElementaryRule(rNum, mLen, mDep));
    }
    if (this->state == 1) {
        if (input != "exit") {
            switch (stoi(input)) {
                case 1:
                    ruleSet->CreateNextGen();
                    cout << ruleSet->getCurrGenNumber() << '\n';
                    cout << "Next Generation\n";
                    break;
                case 2:
                    if (ruleSet->getCurrGenNumber() > 0)
                        ruleSet->UpdateCurrGeneration(ruleSet->getCurrGenNumber() - 1);
                    break;
                case 3: {
                    string tempInput;
                    cout << "\nInput the generation number:";
                    ReadFromKeyBoard(&tempInput, window, event, this, this->ruleSet->getMaxDepth());
                    ruleSet->UpdateCurrGeneration(stoi(tempInput));
                    break;
                }
                case 4:
                    ruleSet->GenerateToMaxDepth();
                    break;
                case 5:

                    cState = 0;
                    break;
                default:
                    break;
            }
        } else {
            return nullptr;
        }


        return new WolframVisualMenu(cState, rNum, mDep, mLen, this->ruleSet);
    }
    delete this->ruleSet;
    return new WolframVisualMenu();
}

Menu *ConwaysVisualMenu::TakeInput(sf::RenderWindow *window, sf::Event *event) {
    cout << "Current input: ";
    if (this->state == 0)
        ReadFromKeyBoard(&input, window, event, this, 10);

    string temp;
    int newInitialCells = this->game->getInitNrCells();
    int newHeight = this->game->getHeight();
    int newLength = this->game->getLength();


    if (this->state == 0) {
        if (input != "exit") {
            if (input == "1") {
                cout << "Insert new initial cells number\n";
                ReadFromKeyBoard(&temp, window, event, this, this->game->getHeight() * this->game->getLength() - 1);
                if (temp == "exit")return nullptr;
                newInitialCells = stoi(temp);
                if (newInitialCells > newLength * newHeight)
                    newInitialCells = newLength * newHeight - 1;
                this->game->setInitNrCells(newInitialCells);
            } else if (input == "2") {
                cout << "Insert new height\n";
                ReadFromKeyBoard(&temp, window, event, this, 500);
                if (temp == "exit")return nullptr;
                newHeight = stoi(temp);
                if (newInitialCells > newLength * newHeight)
                    newInitialCells = newLength * newHeight - 1, this->game->setInitNrCells(newInitialCells);
            } else if (input == "3") {
                cout << "Insert new width\n";
                ReadFromKeyBoard(&temp, window, event, this, 1100);
                if (temp == "exit")return nullptr;
                newLength = stoi(temp);
                if (newInitialCells > newLength * newHeight)
                    newInitialCells = newLength * newHeight - 1, this->game->setInitNrCells(newInitialCells);
            } else if (input == "4") {
                preset = !preset;
            } else if (input == "5") {
                this->state = 1;
            } else if (input == "6") {
                delete this->game;
                return new Visualization();
            }


        } else
            return nullptr;

        delete this->game;
        if (!this->preset) {
            return new ConwaysVisualMenu(this->state, this->preset,
                                         new ConwaysGameOfLife(newInitialCells, newHeight, newLength));
        } else {
            int mat[502][1102];
            return new ConwaysVisualMenu(this->state, this->preset, new ConwaysGameOfLife(mat));
        }
    } else if (this->state == 1) {
        auto lastKeyPressTime = std::chrono::steady_clock::now();
        const auto keyPressDelay = std::chrono::milliseconds(200);
        while ((event->type != sf::Event::KeyPressed || (event->key.code != 27 && event->key.code != 28)) &&
               event->type != sf::Event::Closed) {
            auto now = std::chrono::steady_clock::now();
            auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastKeyPressTime);

            if (event->type != sf::Event::Closed && elapsedTime > keyPressDelay) {
                //cout << "I am here conway\n";

                game->DisplayGameOfLife(window);
                game->CreateNextGeneration();
                lastKeyPressTime = now;


            }
            // cout << event->type <<' ' << sf::Event::Closed << ' ' << sf::Event::Resized<<'\n';
            while (window->pollEvent(*event))
                if (event->type == sf::Event::Closed) {
                    delete this->game;
                    return nullptr;
                } else if (event->key.code == 28)
                    break;
                else if (event->key.code == 27) {
                    bool getOut = false;
                    while (window->isOpen()) {
                        while (window->pollEvent(*event))
                            if (event->type == sf::Event::KeyPressed && event->key.code == 28) {
                                getOut = true;
                            } else if (event->type == sf::Event::Closed) {
                                delete this->game;
                                return nullptr;
                            }
                        if (getOut)
                            break;
                    }
                    delete this->game;
                    return new ConwaysVisualMenu();
                }

        }
        cout << "i am out\n";
        if (event->type == sf::Event::Closed) {
            delete this->game;
            return nullptr;
        }


    }
    delete this->game;
    return new ConwaysVisualMenu();
}
Menu* BelousovVisualMenu::TakeInput(sf::RenderWindow *window, sf::Event *event) {
    string temp;
    int newQ = this->game->getQ();
    int newK1 = this->game->getK1();
    int newK2 = this->game->getK2();
    int newG = this->game->getG();
    cout << newQ << ' ' << newK1 << ' ' << newK2 << ' ' << newG << '\n';
    cout << "I am here\n";
    if(this->state == 0)
    {
        ReadFromKeyBoard(&input, window, event, this, 100);
        if(input == "1")
        {
            cout << "Insert new Q: \n";
            ReadFromKeyBoard(&temp, window, event, this, 255);
            if (temp == "exit")return nullptr;
            newQ = stoi(temp);
            if(newQ == 0) newQ++;
        }
        if(input == "2")
        {
            cout << "Insert new K1:\n";
            ReadFromKeyBoard(&temp, window, event, this, 8);
            if (temp == "exit")return nullptr;
            newK1 = stoi(temp);
            if(newK1 == 0)newK1++;
        }
        if(input == "3")
        {
            cout << "Insert new K2: \n";
            ReadFromKeyBoard(&temp, window, event, this, 8);
            if (temp == "exit")return nullptr;
            newK2 = stoi(temp);
            if(newK2 == 0)newK2++;
        }
        if(input == "4")
        {
            cout << "Insert new G: \n";
            ReadFromKeyBoard(&temp, window, event, this, 100);
            if (temp == "exit")return nullptr;
            newG = stoi(temp);
            if(newG == 0)newG++;
        }
        if(input == "5")
        {
            this->state = 1;
        }
        if(input == "6")
        {
            delete this->game;
            return new Visualization();
        }
        if(input == "exit")
            return nullptr;
    }
    else if(this->state == 1)
    {
        int ok = 1;
        bool pause = 0;
        auto lastKeyPressTime = std::chrono::steady_clock::now();
        const auto keyPressDelay = std::chrono::milliseconds(200);

        while(window->isOpen() && ok)
        {
            auto now = std::chrono::steady_clock::now();
            auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastKeyPressTime);

            while(window->pollEvent(*event))
            {
                if(event->type == sf::Event::Closed)
                {
                    delete this->game;
                    return nullptr;
                }
                if(event->type == sf::Event::KeyPressed && event->key.code == 27)
                {
                    ok = 0;
                    break;
                }
                if(event->type == sf::Event::KeyPressed && event->key.code == 28)
                {
                    pause = !pause;
                }
                if(event->type == sf::Event::MouseMoved)
                {
                    float xPos = event->mouseMove.x;
                    float yPos = event->mouseMove.y;
                    if(yPos >=71.f && yPos <=571.f && xPos >=301.f && xPos <= 801.f )
                        this->game->IncreaseInfection(xPos-301.f,yPos-71.f);
                    cout << xPos << ' ' << yPos << '\n';


                }
                //cout << event->type <<'\n';
            }
            if(elapsedTime > keyPressDelay && !pause)
            {
                this->game->CreateNextGeneration();
                //this->DisplayScreen(window);
                this->game->DisplayBelousov(window);
                lastKeyPressTime = now;
            }


            //cout << "itereation" << '\n';

        }
        delete this->game;
        return new BelousovVisualMenu(0,newQ,newK1,newK2,newG);
    }


    delete this->game;
    cout << newQ << ' ' << newK1 << ' ' << newK2 << ' ' << newG << '\n';
    return new BelousovVisualMenu(this->state,newQ,newK1,newK2,newG);
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

Menu *Visualization::TakeInput(sf::RenderWindow *window, sf::Event *event) {
    string input;
    ReadFromKeyBoard(&input, window, event, this, 100);
    cout << "I am here\n";
    //while(event->type != sf::Event::KeyPressed && event->type != sf::Event::Closed)window->pollEvent(*event);
    cout << "I got out\n";
    //if(event->type == sf::Event::Closed)return nullptr;
    //if(event->type == sf::Event::KeyPressed)
    // {input = to_string(char(event->key.code-26));
    //     cout << event->key.code <<'\n';}
    cout << input << " entered\n";
    if (input == "1") {
        //Wolfram
        cout << "I AM HERE NIGGA\n";
        return new WolframVisualMenu();
    }
    if (input == "2") {
        //Conways
        return new ConwaysVisualMenu();
    }
    if (input == "3") {
        //Belousov
        return new BelousovVisualMenu();
    }
    if (input == "4") {
        //Custom
        return new Visualization();
    }
    if (input == "5") {
        //Back
        return new Main();
    }
    if (input == "exit")
        return nullptr;

    return new Visualization();

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

Menu *Cryptography::TakeInput(sf::RenderWindow *window, sf::Event *event) {
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
        //Image
        return new Cryptography();
    }
    if (input == "2") {
        //Text
        return new Cryptography();
    }
    if (input == "3") {
        //Back
        return new Main();
    }
    if (input == "exit")
        return nullptr;

    return new Cryptography();

}