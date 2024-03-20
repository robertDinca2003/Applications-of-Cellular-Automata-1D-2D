//
// Created by robert on 20.03.2024.
//

#include "Menu.h"

WolframVisualMenu::WolframVisualMenu(int state , int ruleNumber , int maxDepth , int maxLength , ElementaryRule*ruleSet){
    this->state = state;
    this->ruleNumber = ruleNumber;
    this->maxDepth = maxDepth;
    this->maxLength = maxLength;
    this->input = 0;
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


Menu* WolframVisualMenu::TakeInput(){
    cout << "\nCurrent Input: ";
    cin >> input;
    int rNum = this->ruleNumber;
    int mLen = this->maxLength;
    int mDep = this->maxDepth;
    int cState = this->state ;
    if(this->state == 0)
    {
        switch (input) {
            case 1:
                cout << "Insert new rule number: ";
                cin >> rNum;
                break;
            case 2:
                cout << "Insert new maximum length: ";
                cin >> mLen;
                break;
            case 3:
                cout << "Insert new maximum depth: ";
                cin >> mDep;
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
        switch (input) {
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
                int tempInput;
                cout << "\nInput the generation number:";
                cin >> tempInput;
                ruleSet->UpdateCurrGeneration(tempInput);
                break;
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

Menu* Main::TakeInput() {
    string input;
    cin >> input;
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
    return new Main();

}

Menu* Visualization::TakeInput() {
    string input;
    cin >> input;
    if(input == "1"){
        //Wolfram
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
    return new Visualization();


}

Menu* Fractal::TakeInput() {
    string input;
    cin >> input;
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
    return new Fractal();

}

Menu* Cryptography::TakeInput() {
    string input;
    cin >> input;
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
    return new Cryptography();

}