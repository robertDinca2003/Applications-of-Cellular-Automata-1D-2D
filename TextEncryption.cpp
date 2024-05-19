//
// Created by robert on 16.04.2024.
//

#include <fstream>
#include "TextEncryption.h"
#include "Cryptography.h"
#include "MenuFactory.h"
#include "AlgEncryptText.h"

int TextEncryption::option = -1;

void TextEncryption::setOption(int val) {
    TextEncryption::option = val;
}

int TextEncryption::getOption() {
    return TextEncryption::option;
}

TextEncryption::TextEncryption(): rule(new ElementaryRule(30)), game(new ConwaysGameOfLife()) {

    //this->option = -1;
    this->message = "Message";
    this->input = "";
    this->encryptedMessage = this->message;
//    ElementaryRule temp =  ElementaryRule(30) ;
//    this->rule = &temp;
//    ConwaysGameOfLife temp2(200,100,100);
//    this->game = &temp2;
//    this->processes.push_back(this->rule);
//    this->processes.push_back(this->game);
//    std::cout<<this->rule->CreateCryptMask()<< ' ' << this->game->CreateCryptMask() << '\n';
}



TextEncryption::TextEncryption(ElementaryRule *rule, ConwaysGameOfLife *game, std::vector<CryptMethods*>processes, const std::string message) {
    this->rule = rule;
    this->game = game;
    for(auto proc : processes)
        this->processes.push_back(proc);
    this->message = message;
    //this->option = opt;
}



void TextEncryption::Encrypt(int opt = 0) {
    if(option == -1)
        return;
    std::vector<std::string> keys;
    std::cout << "is in encrypt\n";
    std::string name;
    if(opt == 0)
        name = "encryptionRules.txt";
    else
        name = "decryptionRules.txt";
    std::ofstream fout(name);
    for(size_t i = 0; i < this->processes.size(); i++)
    {

        if(dynamic_cast<ElementaryRule*>(this->processes[i]))
        {
            if(option == -1 || option == 1) continue;
            std::cout << "i am elementary\n";
            ElementaryRule * temp = dynamic_cast<ElementaryRule*>(this->processes[i]);
            fout << "Elementary Rule: " <<  temp->getRuleNumber() << " " << temp->getMaxLength() << " " << temp->getMaxDepth() << "\n";
            keys.push_back(dynamic_cast<ElementaryRule*>(this->processes[i])->CreateCryptMask());
        }
        else
        {
            if(option == -1 || option == 0)
                continue;
            std::cout << "i am conway\n";
            ConwaysGameOfLife * temp = dynamic_cast<ConwaysGameOfLife*>(this->processes[i]);
            fout << "Conway game of life: " <<  temp->getHeight() << " " << temp->getLength() << "\n";
            for(int x = 0 ; x < temp->getHeight(); x++)
            {
                for(int y = 0 ; y< temp->getLength(); y++)
                {
                    fout << temp->getElement(x,y) << " ";
                }
                fout << "\n";
            }
            keys.push_back(dynamic_cast<ConwaysGameOfLife*>(this->processes[i])->CreateCryptMask());
        }
    }
    for(auto key : keys)
    {
        std::cout << "this key: " << key << '\n';
        AlgEncryptText<std::string> encryptionAlgorithm(key,this->message);
        encryptionAlgorithm.doTextEncryption();
        this->message = encryptionAlgorithm.getOutput();

    }
    std::ofstream f("encryptedMessage.txt");
    f << this->message;
}

void TextEncryption::Decrypt() {

    this->Encrypt();

}


void TextEncryption::DisplayScreen(sf::RenderWindow *window) {
    std::string content[9];
    content[0] = "<--- Text Encryption --->\n";
    content[1] = "1. Set Message: " + this->message + "\n";
    content[2] = "2. Use Wolfram Rule:\n   3. Rule - " + std::to_string(this->rule->getRuleNumber()) + "  4. Max Width - "+ std::to_string(this->rule->getMaxLength()) + "\n   5. Max Depth Number - " + std::to_string(this->rule->getMaxDepth());
    content[3] = "\n6. Add Elementary Rule\n7. Use Conway's Game of Life:\n   8. Width - " + std::to_string(this->game->getLength()) + "  9. Height - " +
            std::to_string(this->game->getHeight()) + "\n";
    content[4] = "10. Add Conways' game\n11. Use Both\n12. Encrypt\n";
    content[5] = "13. Decrypt\n";
    content[6] = "Processed Message using";
    if(this->getOption() == -1)
        content[6] += " None\n";
    if(this->getOption() == 0)
        content[6] += " only Elem Rule\n";
    if(this->getOption() == 1)
        content[6] += " only Conway\n";
    if(this->getOption() == 2)
        content[6] += " Both\n";
    content[7] = this->encryptedMessage;
    content[8] = "\n14. Back\n";

    sf::Text text;
    sf::Font font;
    font.loadFromFile("myfont.ttf");

    text.setFont(font);
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::Blue);
    text.setPosition(20, 50);
    text.setLineSpacing(1.5);

    std::string display = "";
    for(int i = 0; i< 9; i++)
        display += content[i];
    text.setString(display);

    window->clear(sf::Color::White);
    window->draw(text);

    std::string displayProcesses[10];
    displayProcesses[0] = "<--- Processes Applied --->\n";
    std::string contentProcess= displayProcesses[0];
    for(int i = 0 ; i<(int)this->processes.size(); i++){
        displayProcesses[i+1] = "";
        if(dynamic_cast<ElementaryRule*>(this->processes[i]) != nullptr)
        {
            ElementaryRule* temp = dynamic_cast<ElementaryRule*>(this->processes[i]);
            displayProcesses[i+1] = "Elem Rule: "+ std::to_string(temp->getRuleNumber()) + " " + std::to_string(temp->getMaxLength()) + " " +
                    std::to_string(temp->getMaxDepth()) + " \n";
        }
        else if(dynamic_cast<ConwaysGameOfLife*>(this->processes[i]) != nullptr)
        {
            ConwaysGameOfLife* temp = dynamic_cast<ConwaysGameOfLife*>(this->processes[i]);
            displayProcesses[i+1] = "Conways Game: " + std::to_string(temp->getHeight()) + " " + std::to_string(temp->getLength())+'\n';
        }
        contentProcess += displayProcesses[i+1];
    }

    text.setPosition(sf::Vector2(700.f,50.f));
    text.setString(contentProcess);
    window->draw(text);

    window->display();
}

void TextEncryption::DisplayContent() const {
   std::cout << "<--- Text Encryption --->\n";
   std::cout << "1. Set Message: " << this->message << '\n';
   std::cout << "2. Use Wolfram Rule: Rule - " <<this->rule->getRuleNumber()<<"Max Width: - " << this->rule->getMaxLength() << "Generation Max Depth"<< this->rule->getMaxDepth() <<"\n";
   std::cout << "3. Use Conways's Game of Life:\n"<< "   Width: "<<this->game->getLength() << "Height: " << this->game->getHeight() <<"\n";
   std::cout << "4. Encrypt";
   std::cout << "5. Decrypt";
   std::cout << "Processed Message:\n";
   std::cout << this->encryptedMessage;
   std::cout << "\n6. Back\n";
}

Menu *TextEncryption::TakeInput(sf::RenderWindow *window, sf::Event *event) {
    ReadFromKeyBoard(&input, window, event, this, 100);
    if(this->input == "exit")
    {
        delete this->rule;
        delete this->game;
        return nullptr;
    }
    else if(this->input == "1")
    {
        std::ifstream fin("messageInput.txt");
        fin >> this->message;
    }
    else if(this->input == "2"){
        this->setOption(0);
    }
    else if(this->input == "3"){
        ReadFromKeyBoard(&input, window, event, this, 255);
        if(this->input == "exit")
        {
            delete this->rule;
            delete this->game;
            return nullptr;
        }
        this->rule->setRuleNumber(stoi(input));
    }
    else if(this->input == "4"){
        ReadFromKeyBoard(&input, window, event, this, 150);
        if(this->input == "exit")
        {
            delete this->rule;
            delete this->game;
            return nullptr;
        }
        this->rule->setMaxLength(stoi(input));
    }
    else if(this->input=="5"){
        ReadFromKeyBoard(&input, window, event, this, 150);
        if(this->input == "exit")
        {
            delete this->rule;
            delete this->game;
            return nullptr;
        }
        this->rule->setMaxDepth(stoi(input));
    }
    else if(this->input=="6"){
        ElementaryRule* newRule = new ElementaryRule(*this->rule);
        this->processes.push_back(newRule);
    }
    else if(this->input == "7")
    {
        this->setOption(1);
    }
    else if(this->input=="8"){

        ReadFromKeyBoard(&input, window, event, this, 100);
        if(this->input == "exit")
        {
            delete this->rule;
            delete this->game;
            return nullptr;
        }
        this->game->setWidth(stoi(input));
    }
    else if(this->input=="9"){
        ReadFromKeyBoard(&input, window, event, this, 100);
        if(this->input == "exit")
        {
            delete this->rule;
            delete this->game;
            return nullptr;
        }
        this->game->setHeight(stoi(input));
    }
    else if(this->input=="10"){
        try{
            ConwaysGameOfLife* newGame = new ConwaysGameOfLife();
            *newGame = *this->game;
            this->processes.push_back(newGame);
            std::cout << "Just added conway\n";
        }
        catch (const std::exception &e){
           std::cout << "Exception: " << e.what() << '\n';
        }

    }
    else if(this->input=="11"){
        this->setOption(2);
    }
    else if(this->input=="12"){
        this->Encrypt();
    }
    else if(this->input=="13"){
        this->Decrypt();
    }
    else if(this->input == "14"){
        delete this->rule;
        delete this->game;
        for(size_t i = 0 ; i<this->processes.size(); i++)
            delete this->processes[i];
        return MenuFactory::createMenuInstance(12);
    }

    return new TextEncryption(this->rule,this->game,this->processes, this->message);
}

TextEncryption::~TextEncryption() {
//    if(this->game != nullptr)
//    delete this->game;
//    if(this->rule != nullptr)
//    delete this->rule;


}

TextEncryption::TextEncryption(const TextEncryption &other) {
    this->input = other.input;
    this->rule->operator=( *other.rule);
    this->game->operator=(* other.game);
    this->message =other.message;
    this->encryptedMessage = other.encryptedMessage;
    this->option = other.option;
    for(size_t i = 0 ; i< other.processes.size(); i++)
        this->processes.push_back(other.processes[i]);
}

TextEncryption &TextEncryption::operator=(const TextEncryption &other) {
    this->input = other.input;
    this->rule->operator=(*other.rule) ;
    this->game = other.game;
    this->message =other.message;
    this->encryptedMessage = other.encryptedMessage;
    this->option = other.option;
    for(size_t i = 0 ; i< other.processes.size(); i++)
        this->processes.push_back(other.processes[i]);

    return *this;
}



