//
// Created by User on 25.03.2024.
//
#include "ConwaysGameOfLife.h"
#include <iostream>
using namespace std;

ConwaysGameOfLife::ConwaysGameOfLife() {
    cout << "Constructed Game of Life\n";
    for(int i = 0;  i<502; i++)
        for(int j = 0; j<1102; j++)
            this->matrix[i][j] = this->copyMat[i][j] = 0;
    this->initialNumberCells = rand() % (502*1102);
    for(int x = 0; x < this->initialNumberCells; x++)
    {
        this->matrix[rand()%502][rand()%1102] = 1;
    }
    this->currentGen = 0;
}

ConwaysGameOfLife::ConwaysGameOfLife(int) {
    cout << "Constructed Game of Life\n";
    for(int i = 0;  i<502; i++)
        for(int j = 0; j<1102; j++)
            this->matrix[i][j] = this->copyMat[i][j] = 0;
    for(int x = 0; x < this->initialNumberCells; x++)
    {
        this->matrix[rand()%502][rand()%1102] = 1;
    }
    this->currentGen = 0;
}

ConwaysGameOfLife::ConwaysGameOfLife(int mat[502][1102]) {
    cout << "Constructed Game of Life\n";
    for(int i = 0;  i<502; i++)
        for(int j = 0; j<1102; j++)
        {this->matrix[i][j] =mat[i][j] ;this->copyMat[i][j] = 0;}
    this->currentGen = 0;
}

ConwaysGameOfLife::~ConwaysGameOfLife(){
    cout << "Deconstructed Game of Life\n";
}

int ConwaysGameOfLife::getInitNrCells() const {
    return this->initialNumberCells;
}


void ConwaysGameOfLife::CreateNextGeneration() {
        for(int i = 1; i<=500; i++)
            for(int j = 1; j<=1100; j++)
            {
                this->copyMat[i][j] = this->matrix[i+1][j+1] + this->matrix[i+1][j] + this->matrix[i+1][j-1] + this->matrix[i][j-1] + this->matrix[i][j+1] + this->matrix[i-1][j+1] + this->matrix[i-1][j] + this->matrix[i-1][j-1];
                if(this->copyMat[i][j] == 2 || this->copyMat[i][j] == 3)
                    this->copyMat[i][j] = 1;
                else
                    this->copyMat[i][j] = 0;
            }
        for(int i = 0;  i<502; i++)
            for(int j = 0; j<1102; j++)
                this->matrix[i][j] = this->copyMat[i][j];
        this->currentGen++;
}

void ConwaysGameOfLife::DisplayGameOfLife(sf::RenderWindow *window)
{
    float startX = 0.f;
    float startY = 0.f;
    int height = 502;
    int length = 1102;
    float pixelSize = 1.f;

    sf::RectangleShape pixel(sf::Vector2(pixelSize,pixelSize));

    for(int i = 0; i<height; i++)
        for(int j = 0 ; j<length; j++)
        {
            if(i == 0 || i == 501 || j == 0 || j == 1101)
                pixel.setFillColor(sf::Color::Black);
            else if(this->matrix[i][j] == 1)
                pixel.setFillColor(sf::Color::Blue);
            else
                pixel.setFillColor(sf::Color::White);
            window->draw(pixel);

        }
    window->display();
}