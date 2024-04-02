//
// Created by robert on 02.04.2024.
//

#include "Belousov.h"
#include <iostream>
#include <cmath>

Belousov::Belousov() {
    this->q = rand() % 255 + 1;
    this->k1 = rand() % 8 + 1;
    this->k2 = rand() % 8 + 1;
    this->g = rand() % 100 + 1;
    for(int i = 0 ; i <500; i++)
     for(int j = 0 ; j < 500 ; j++)
         this->currMat[i][j] = this->copyMat[i][j] = 1;
    this->currMat[250][250] = 10;
}

Belousov::Belousov(int q, int k1, int k2, int g) {
    this->q = q;
    this->k1 = k1;
    this->k2 = k2;
    this->g = g;
    for(int i = 0 ; i <500; i++)
        for(int j = 0 ; j < 500 ; j++)
            this->currMat[i][j] = this->copyMat[i][j] = 1;
    this->currMat[250][250] = q/2;
}

Belousov::~Belousov() {
    std::cout << "Destructed Belousov\n";
}

int Belousov::getQ() {
    return this->q;
}

int Belousov::getK1() {
    return this->k1;
}

int Belousov::getK2() {
    return this->k2;
}

int Belousov::getG() {
    return this->g;
}

void Belousov::CreateNextGeneration() {
    for(int i = 0; i<500; i++)
        for(int j = 0; j<500; j++)
        {
            float a = 0.f;
            float b = 0.f ;
            float c = 0.f;
            float S = 0.f;
            for(int i1 = -1; i1<=1; i1++)
                for(int j1 = -1; j1 <=1; j1++)
                {
                    S += this->currMat[(i+i1+500)%500][(j+j1+500)%500];
                    if(this->currMat[(i+i1+500)%500][(j+j1+500)%500] == 1)
                        c++;
                    else if(this->currMat[(i+i1+500)%500][(j+j1+500)%500] == this->q)
                        b++;
                    else
                        a++;
                }
            if(this->currMat[i][j] >= this->q)
                this->copyMat[i][j] = 1.f;
            else if(this->currMat[i][j] == 1.f)
            {
                this->copyMat[i][j] = a/this->k1 + b/this->k2 + 1;
                if(this->copyMat[i][j] > this->q)
                    this->copyMat[i][j] = this->q;
            }
            else{
                this->copyMat[i][j] = S/(9-c) + g;
            }
        }

    for(int i = 0; i < 500 ; i++)
        for(int j = 0 ; j< 500; j++)
            this->currMat[i][j] = this->copyMat[i][j];
}

void Belousov::DisplayBelousov(sf::RenderWindow *window) {
    float pixelSize = 1.f;
    int len = 500;

    float startX = (1100-len * pixelSize)/2.f;
    float startY = 90.f;

    sf::RectangleShape pixel(sf::Vector2(pixelSize,pixelSize));

    for(int i = -1; i<=len; i++)
        for(int j = -1; j<=len; j++)
        {
            if (i == -1 || i == len || j == -1 || j == len) {
                pixel.setFillColor(sf::Color::Black);
            }
            else
            {
                float col = this->currMat[i][j];

                pixel.setFillColor(sf::Color(col, col, col));
            }


            pixel.setPosition(startX+pixelSize*j, startY+pixelSize*i);
            window->draw(pixel);
        }

    window->display();
}

void Belousov::IncreaseInfection(float xPos, float yPos) {
    int x = static_cast<int>(xPos);
    int y = static_cast<int>(yPos);
    this->currMat[y][x] = this->currMat[y][x] + 10;
    if(this->currMat[y][x] > this->q)
        this->currMat[y][x] = this->q;
}



