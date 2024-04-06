//
// Created by robert on 03.04.2024.
//

#include "ConwaysVisualMenu.h"
#include "chrono"

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