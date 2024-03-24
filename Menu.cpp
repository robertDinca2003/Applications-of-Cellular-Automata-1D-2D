//
// Created by robert on 20.03.2024.
//
#include <chrono>
#include "MyTools.cpp"
#include "Menu.h"


void ReadFromKeyBoard(string *input, sf::RenderWindow *window, sf::Event *event, Menu* men){
    int temp = 0;
    bool ok = false;
    string inputMes;

    sf::Text text;
    sf::Font font;
    font.loadFromFile("myfont.ttf");
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Blue);
    text.setPosition(25,550);
    text.setString("Insert: ");
    men->DisplayScreen(window);
    window->draw(text);
    window->display();


    while(event->type == sf::Event::TextEntered && int(event->text.unicode) == 13)window->pollEvent(*event);


    while(!(event->type == sf::Event::TextEntered && int(event->text.unicode) == 13 && temp != 0) && event->type != sf::Event::Closed)
    {

            if(window->pollEvent(*event) && event->type == sf::Event::TextEntered && ok)
            {
                //cout << event->key.code <<'\n';
                if(int(event->text.unicode) >=48 && int(event->text.unicode) <58)
                {   temp = temp * 10 + static_cast<int>(event->text.unicode) - 48;
                    if(temp > 5000) temp = 5000;
                    cout << temp << '\n';
                    inputMes= "Insert: "+ to_string(temp);
                    text.setString(inputMes);

                    sf::RectangleShape clearRect(sf::Vector2f(250.f, 45.f));
                    clearRect.setPosition(20.f, 540.f);
                    clearRect.setFillColor(sf::Color::White);
                    window->draw(clearRect);

                    window->draw(text);
                    window->display();
                }
                if(event->text.unicode == 8)
                {

                    temp = temp / 10;

                    cout << temp << '\n';
                    inputMes= "Insert: "+ to_string(temp);
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
    if(event->type == sf::Event::Closed)
        *input = "exit";
    else
    {cout << "Inputed Value is " << temp <<'\n';
        *input = to_string(temp);}
}

WolframVisualMenu::WolframVisualMenu(int state , int ruleNumber , int maxDepth , int maxLength , ElementaryRule*ruleSet){
    this->state = state;
    this->ruleNumber = ruleNumber;
    this->maxDepth = maxDepth;
    this->maxLength = maxLength;
    this->input = "0";
    this->ruleSet = ruleSet;
}

void Main::DisplayContent() const{
        cout << "<--- Applications of Cellular Automata --->\n\n";
        cout << "1. Visualizations\n";
        cout << "2. Cryptography\n";
        cout << "3. Fractals\n";
        cout << "4. Exit\n";
    }
void Visualization::DisplayContent() const{
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


void WolframVisualMenu::DisplayContent() const{
    if(this->state == 0)
    {
        cout << "<--- Wolfram's Rules Visualization --->\n";
        cout << "Select (1, 2, 3) to change\nCurrent Settings:\n";
        cout << "1. Current Rule:"<<this->ruleNumber<<"\n";
        cout << "2. Maximum Length:"<<this->maxLength<<"\n";
        cout << "3. Maximum Depth:"<<this->maxDepth<<"\n";
        cout << "\n4. Generate!\n";
        cout << "5. Go Back\n";
    }
    if(this->state == 1)
    {
        cout << "<-- Wolfram's Rule " << this->ruleNumber << " -->\n";
        cout << "1. Next Generation\n";
        cout << "2. Previous Generation\n";
        cout << "3. Go to a generation by number\n";
        cout << "4. Complete all generation\n";
        cout << "5. Back\n";

        cout << this->ruleSet->getCurrGenNumber()<<'\n';
        ruleSet->DisplayCurrentGeneration();
        cout << '\n';
        ruleSet->DisplayUpToCurrentGeneration();
    }
}

void Main::DisplayScreen(sf::RenderWindow* window) {
    vector<string> content(5);

    content[0]="<--- Applications of Cellular Automata --->\n\n";
    content[1]="1. Visualization\n";
    content[2]="2. Cryptography\n";
    content[3] ="3. Fractals\n";
    content[4] = "4. Exit";

    string display;
    for(int i = 0; i<5; i++)
        display += content[i];

    sf::Font font;
    font.loadFromFile("myfont.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString(display);
    text.setCharacterSize(24);
    text.setPosition(100.f,50.f);
    text.setFillColor(sf::Color::Blue);
    text.setLineSpacing(1.5f);

    window->clear(sf::Color::White);
    window->draw(text);
    window->display();
}

void Visualization::DisplayScreen(sf::RenderWindow* window) {
    vector<string> content(6);

    content[0]="<--- Visualization --->\n\n";
    content[1]="1. Wolfram's Elementary Rules\n";
    content[2]="2. Conway's Game of Life\n";
    content[3] ="3. Belousov-Zhabotinsky\n";
    content[4] = "4. Custom 2D automaton\n";
    content[5] = "5. Back";
    string display;



    for(int i = 0; i<6; i++)
        display += content[i];

    sf::Font font;
    font.loadFromFile("myfont.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString(display);
    text.setCharacterSize(24);
    text.setPosition(300.f,50.f);
    text.setFillColor(sf::Color::Blue);
    text.setLineSpacing(1.5f);

    window->clear(sf::Color::White);
    window->draw(text);
    window->display();
}

void Cryptography::DisplayScreen(sf::RenderWindow* window) {

    vector<string> content(4);

    content[0]="<--- Cryptography --->\n\n";
    content[1]="1. Image Encryption\n";
    content[2]="2. Text Encryption\n";
    content[3] ="3. Back\n";




    string display;
    for(int i = 0; i<4; i++)
        display += content[i];

    sf::Font font;
    font.loadFromFile("myfont.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString(display);
    text.setCharacterSize(24);
    text.setPosition(300.f,50.f);
    text.setFillColor(sf::Color::Blue);
    text.setLineSpacing(1.5f);

    window->clear(sf::Color::White);
    window->draw(text);
    window->display();
}

void Fractal::DisplayScreen(sf::RenderWindow* window) {
    vector<string> content(4);
    content[0] = "<--- Fractals --->\n";
    content[1] = "1. Wolfram's Elementary Rules\n";
    content[2] = "2. More Fractals\n";
    content[3] = "3. Back\n";

    string display;
    for(int i = 0; i<4; i++)
        display += content[i];

    sf::Font font;
    font.loadFromFile("myfont.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString(display);
    text.setCharacterSize(24);
    text.setPosition(300.f,50.f);
    text.setFillColor(sf::Color::Blue);
    text.setLineSpacing(1.5f);

    window->clear(sf::Color::White);

    window->draw(text);
    window->display();

}
void WolframVisualMenu::DisplayScreen(sf::RenderWindow* window) {
    vector<string> content(14);
    content[0] = "<--- Wolfram's Rules Visualization --->\n";
    content[1] = "Select (1 , 2 ,3) to change \nCurrent settings\n";
    content[2] = "1. Current Rule: " + to_string(this->ruleNumber);
    content[3] = "\n2. Maximum Length: "+ to_string(this->maxLength);
    content[4] = "\n3. Maximum Depth: "+ to_string(this->maxDepth);
    content[5] = "\n4. Generate";
    content[6] = "\n5. Back\n";
    content[7] = "<--- Wolfram's Rules " + to_string(this->ruleNumber) + " --->\n";
    content[8] ="1. Next Generation\n";
    content[9] = "2. Previous Generation\n";
    content[10] = "3. Go To A Generation\n   By Number\n";
    content[11] = "4. Complete All Generation\n";
    content[12] = "5. Back\n";
    content[13] = "";

    string display;
    for(int i = 0; i<7; i++)
    {
        display += content[i+this->state*7];
    }
    sf::Font font;
    font.loadFromFile("myfont.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString(display);
    if(this->state == 0)
    {
        text.setCharacterSize(24);
        text.setPosition(150.f,50.f);

    }
    else
    {
        text.setCharacterSize(8);
        text.setPosition(30.f,10.f);

    }
    text.setFillColor(sf::Color::Blue);
    text.setLineSpacing(1.5f);

    window->clear(sf::Color::White);
    window->draw(text);
    window->display();
}

Menu* WolframVisualMenu::TakeInput(sf::RenderWindow* window,sf::Event* event){
    cout << "\nCurrent Input: ";
    cout << "I am here\n";
//    while(event->type != sf::Event::KeyPressed && event->type != sf::Event::Closed)window->pollEvent(*event);
//    cout << "I got out\n";
//    if(event->type == sf::Event::Closed)return nullptr;
//    if(event->type == sf::Event::KeyPressed)input = event->key.code-26;
    ReadFromKeyBoard(&input,window,event,this);

    int rNum = this->ruleNumber;
    int mLen = this->maxLength;
    int mDep = this->maxDepth;
    int cState = this->state ;
    if(this->state == 0)
    {
        string temp;
        //int temp = 0;
        //1bool ok;
        sf::Text text;
        sf::Font font;
        font.loadFromFile("myfont.ttf");
        text.setFont(font);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Blue);
        text.setPosition(25,550);


        string inputMes= "Insert:";
        text.setString(inputMes);
        this->DisplayScreen(window);
        window->draw(text);


        switch (stoi(input)) {
            case 1:
                cout << "Insert new rule number: ";
                ReadFromKeyBoard(&temp,window,event,this);
                cout << temp<<'\n';
                if(temp == "exit")return nullptr;
                rNum = stoi(temp);
                break;
            case 2:
                cout << "Insert new maximum length: ";
                ReadFromKeyBoard(&temp,window,event,this);
                if(temp == "exit")return nullptr;
                mLen = stoi(temp);
                break;
            case 3:
                cout << "Insert new maximum depth: ";
                //window->pollEvent(*event);
                ReadFromKeyBoard(&temp,window,event,this);

                if(temp == "exit")return nullptr;
                mDep = stoi(temp);
                if(mDep >5000)
                    mDep = 5000;
                if(mDep == 0)
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
        delete this->ruleSet;
        return new WolframVisualMenu(cState,rNum,mDep,mLen, new ElementaryRule(rNum,mLen,mDep));
    }
    if(this->state == 1)
    {
        switch (stoi(input)) {
            case 1:
                ruleSet->CreateNextGen();
                cout << ruleSet->getCurrGenNumber()<< '\n';
                cout << "Next Generation\n";
                break;
            case 2:
                if(ruleSet->getCurrGenNumber() > 0)
                    ruleSet->UpdateCurrGeneration(ruleSet->getCurrGenNumber()-1);
                break;
            case 3:
            {string tempInput;
                cout << "\nInput the generation number:";
                ReadFromKeyBoard(&tempInput,window,event,this);
                ruleSet->UpdateCurrGeneration(stoi(tempInput));
                break;}
            case 4:
                ruleSet->GenerateToMaxDepth();
                break;
            case 5:

                cState = 0;
                break;
            default:
                break;
        }

        return new WolframVisualMenu(cState,rNum,mDep,mLen, this->ruleSet);
    }
    delete this->ruleSet;
    return new WolframVisualMenu();
}

Menu* Main::TakeInput(sf::RenderWindow* window,sf::Event* event) {
    string input;
    ReadFromKeyBoard(&input,window,event,this);
    cout << "I am here\n";
//    while(event->type != sf::Event::KeyPressed && event->type != sf::Event::Closed)window->pollEvent(*event);
    cout << "I got out\n";
//    if(event->type == sf::Event::Closed)return nullptr;
//    if(event->type == sf::Event::KeyPressed)
//    {input = to_string(char(event->key.code-26));
//        cout << event->key.code <<'\n';}
//    else input = "-1";
    if(input == "1"){
        return new Visualization();
    }
    if(input == "2"){
        return new Cryptography;
    }
    if(input == "3"){
        return new Fractal();
    }
    if(input == "4"){
        return nullptr;
    }
    if(input == "exit")
        return nullptr;

    return new Main();

}

Menu* Visualization::TakeInput(sf::RenderWindow* window,sf::Event* event) {
    string input;
    ReadFromKeyBoard(&input,window,event,this);
    cout << "I am here\n";
    //while(event->type != sf::Event::KeyPressed && event->type != sf::Event::Closed)window->pollEvent(*event);
    cout << "I got out\n";
    //if(event->type == sf::Event::Closed)return nullptr;
    //if(event->type == sf::Event::KeyPressed)
   // {input = to_string(char(event->key.code-26));
   //     cout << event->key.code <<'\n';}
   cout << input << " entered\n";
    if(input == "1"){
        //Wolfram
        cout << "I AM HERE NIGGA\n";
        return new WolframVisualMenu();
    }
    if(input == "2"){
        //Conways
        return new Visualization();
    }
    if(input == "3"){
        //Belousov
        return new Visualization();
    }
    if(input == "4"){
        //Custom
        return new Visualization();
    }
    if(input == "5"){
        //Back
        return new Main();
    }
    if(input == "exit")
        return nullptr;

    return new Visualization();

}

Menu* Fractal::TakeInput(sf::RenderWindow* window,sf::Event* event) {
    string input;
    cout << "I am here\n";
    ReadFromKeyBoard(&input,window,event,this);
//    while(event->type != sf::Event::KeyPressed && event->type != sf::Event::Closed)window->pollEvent(*event);
//    cout << "I got out\n";
//    if(event->type == sf::Event::Closed)return nullptr;
//    if(event->type == sf::Event::KeyPressed)
//    {input = to_string(char(event->key.code-26));
//        cout << event->key.code <<'\n';}
    if(input == "1"){
        //Wolfram
        return new Fractal();
    }
    if(input == "2"){
        //More
        return new Fractal();
    }
    if(input == "3"){
        //Back
        return new Main();
    }
    if(input == "exit")
        return nullptr;

    return new Fractal();

}

Menu* Cryptography::TakeInput(sf::RenderWindow* window,sf::Event* event) {
    string input;
    cout << "I am here\n";
    ReadFromKeyBoard(&input,window,event,this);
    //    while(event->type != sf::Event::KeyPressed && event->type != sf::Event::Closed)window->pollEvent(*event);
//    cout << "I got out\n";
//    if(event->type == sf::Event::Closed)return nullptr;
//    if(event->type == sf::Event::KeyPressed)
//    {input = to_string(char(event->key.code-26));
//        cout << event->key.code <<'\n';}
    if(input == "1"){
        //Image
        return new Cryptography();
    }
    if(input == "2"){
        //Text
        return new Cryptography();
    }
    if(input == "3"){
        //Back
        return new Main();
    }
    if(input == "exit")
        return nullptr;

    return new Cryptography();

}