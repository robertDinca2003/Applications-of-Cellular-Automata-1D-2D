//
// Created by robert on 03.04.2024.
//

#include "WolframVisualMenu.h"


void DisplayBufferContent(ElementaryRule *ruleSet, sf::RenderWindow *window) {

    int height = ruleSet->getMaxDepth();
    int length = ruleSet->getMaxLength();
    int currHeight = ruleSet->getCurrGenNumber();
    float pixelSize = std::min(1100.f / length, 435.f / height);
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


WolframVisualMenu::WolframVisualMenu(int state, int ruleNumber, int maxDepth, int maxLength, ElementaryRule *ruleSet) {
    this->state = state;
    this->ruleNumber = ruleNumber;
    this->maxDepth = maxDepth;
    this->maxLength = maxLength;
    this->input = "0";
    this->ruleSet = ruleSet;
}


void WolframVisualMenu::DisplayContent() const {
    if (this->state == 0) {
       std::cout << "<--- Wolfram's Rules Visualization --->\n";
       std::cout << "Select (1, 2, 3) to change\nCurrent Settings:\n";
       std::cout << "1. Current Rule:" << this->ruleNumber << "\n";
       std::cout << "2. Maximum Length:" << this->maxLength << "\n";
       std::cout << "3. Maximum Depth:" << this->maxDepth << "\n";
       std::cout << "\n4. Generate!\n";
       std::cout << "5. Go Back\n";
    }
    if (this->state == 1) {
       std::cout << "<-- Wolfram's Rule " << this->ruleNumber << " -->\n";
       std::cout << "1. Next Generation\n";
       std::cout << "2. Previous Generation\n";
       std::cout << "3. Go to a generation by number\n";
       std::cout << "4. Complete all generation\n";
       std::cout << "5. Back\n";

       std::cout << this->ruleSet->getCurrGenNumber() << '\n';
        //ruleSet->DisplayCurrentGeneration();
       std::cout << '\n';
        //ruleSet->DisplayUpToCurrentGeneration();
    }
}


void WolframVisualMenu::DisplayScreen(sf::RenderWindow *window) {
    std::vector<std::string> content(14);
    content[0] = "<--- Wolfram's Rules Visualization --->\n";
    content[1] = "Select (1 , 2 ,3) to change \nCurrent settings\n";
    content[2] = "1. Current Rule: " + std::to_string(this->ruleNumber);
    content[3] = "\n2. Maximum Length: " + std::to_string(this->maxLength);
    content[4] = "\n3. Maximum Depth: " + std::to_string(this->maxDepth);
    content[5] = "\n4. Generate";
    content[6] = "\n5. Back\n";
    content[7] = "<--- Wolfram's Rules " + std::to_string(this->ruleNumber) + " --->\n";
    content[8] = "1. Next Generation\n";
    content[9] = "2. Previous Generation\n";
    content[10] = "3. Go To A Generation\n   By Number\n";
    content[11] = "4. Complete All Generation\n";
    content[12] = "5. Back\n";
    content[13] = "";

    std::string display;
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


Menu *WolframVisualMenu::TakeInput(sf::RenderWindow *window, sf::Event *event) {
   std::cout << "\nCurrent Input: ";
   std::cout << "I am here\n";
//    while(event->type != sf::Event::KeyPressed && event->type != sf::Event::Closed)window->pollEvent(*event);
//   std::cout << "I got out\n";
//    if(event->type == sf::Event::Closed)return nullptr;
//    if(event->type == sf::Event::KeyPressed)input = event->key.code-26;
    ReadFromKeyBoard(&input, window, event, this, 10);

    int rNum = this->ruleNumber;
    int mLen = this->maxLength;
    int mDep = this->maxDepth;
    int cState = this->state;
    if (this->state == 0) {
        std::string temp;
        //int temp = 0;
        //1bool ok;
        sf::Text text;
        sf::Font font;
        font.loadFromFile("myfont.ttf");
        text.setFont(font);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Blue);
        text.setPosition(25, 550);


        std::string inputMes = "Insert:";
        text.setString(inputMes);
        this->DisplayScreen(window);
        window->draw(text);

        if (input != "exit") {
            switch (stoi(input)) {
                case 1:
                   std::cout << "Insert new rule number: ";
                    ReadFromKeyBoard(&temp, window, event, this, 255);
                   std::cout << temp << '\n';
                    if (temp == "exit")return nullptr;
                    rNum = stoi(temp);
                    break;
                case 2:
                   std::cout << "Insert new maximum length: ";
                    ReadFromKeyBoard(&temp, window, event, this, 1100);
                    if (temp == "exit")return nullptr;
                    mLen = stoi(temp);
                    break;
                case 3:
                   std::cout << "Insert new maximum depth: ";
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
                   std::cout << ruleSet->getCurrGenNumber() << '\n';
                   std::cout << "Next Generation\n";
                    break;
                case 2:
                    if (ruleSet->getCurrGenNumber() > 0)
                        ruleSet->UpdateCurrGeneration(ruleSet->getCurrGenNumber() - 1);
                    break;
                case 3: {
                    std::string tempInput;
                   std::cout << "\nInput the generation number:";
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

