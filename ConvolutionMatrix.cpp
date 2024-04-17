//
// Created by robert on 05.04.2024.
//

#include "ConvolutionMatrix.h"
#include <cmath>
#include <SFML/Graphics.hpp>
#include <iostream>

float ConvolutionMatrix::activationFunction(int func, float val) {

    if(func == 1)
        return val;
    if(func == 2)
        return abs(val);
    if(func == 3)
        return sin(val);
    if(func == 4)
        return val * val ;

    return val;
}


ConvolutionMatrix::ConvolutionMatrix(int kSize) {
    this->kernelSize = kSize;
    this->actFunc = 1;
    for(int i = 0 ; i < kSize; i++)
        for(int j = 0; j< kSize; j++)
            this->kernel[i][j] = (rand()%100+1)/10.f -5.f;
    for(int i = 0 ;i < 500 ; i++)
        for(int j = 0 ; j< 500; j++)
            this->origin[i][j] = this->nextOrigin[i][j] = (rand()%20000+1)/10000.f-1;
    this->origin[250][250] = 1;
}

ConvolutionMatrix::ConvolutionMatrix(int kSize, int kernel[10][10]) {
    this->kernelSize = kSize;
    this->actFunc = 1;
    for(int i = 0; i<kSize; i++)
        for(int j = 0 ;j< kSize; j++)
            this->kernel[i][j] = kernel[i][j];
    for(int i = 0 ;i < 500 ; i++)
        for(int j = 0 ; j< 500; j++)
            this->origin[i][j] = this->nextOrigin[i][j] = 0;
}

void ConvolutionMatrix::setActFunc(int val) {
    this->actFunc = val;
}

float ConvolutionMatrix::getKernelElem(int i, int j) const{
        return this->kernel[i][j];
}

//int ConvolutionMatrix::getKernelSize() const {
//    return this->kernelSize;
//}

void ConvolutionMatrix::setKernelElem(int x, int y, float val)
{
    this->kernel[x][y] = val;
}

void ConvolutionMatrix::CreateNextGeneration() {

    float convSum;
    int kSize=this->kernelSize;
    for(int i = 0; i<500;i++)
        for(int j = 0; j<500;j++)
        {

            convSum = 0.f;
            for(int x = -kSize/2 ; x<=kSize/2; x++)
                for(int y=-kSize/2; y<=kSize/2; y++)
                {
                 convSum += this->origin[(int)fmax(i+x,0)][(int)fmax(j+y,0)] * this->kernel[x+kSize/2][y+kSize/2] ;
                }
            this->nextOrigin[i][j] = fmin(fmax(this->activationFunction(this->actFunc,convSum),-1000000),1000000);
        }
    for(int i = 0; i<500; i++)
        for(int j =0 ; j<500;j++)
            this->origin[i][j] = this->nextOrigin[i][j];
}

void ConvolutionMatrix::DisplayConvolution(sf::RenderWindow *window) {

    float pixelSize = 1.f;

    sf::RectangleShape pixel(sf::Vector2(pixelSize,pixelSize));
    float startX = 300.f;
    float startY = 90.f;

    for(int i = -1 ; i <= 500; i++)
        for(int j = -1; j <= 500; j++)
        {
            pixel.setPosition(sf::Vector2(startX+j,startY+i));
            if(i == -1 || i == 500 || j == -1 || j == 500)
            {
                pixel.setFillColor(sf::Color::Red);
            }
            else{
                if(this->actFunc != 3)
                {
                    if(this->origin[i][j] < 255)
                        pixel.setFillColor(sf::Color(this->origin[i][j],this->origin[i][j],this->origin[i][j]));
                    else
                        pixel.setFillColor(sf::Color::White);
                }
                else
                {
                    pixel.setFillColor(sf::Color((this->origin[i][j]+1)*125,(this->origin[i][j]+1)*125,(this->origin[i][j]+1)*125));
                }

            }
            window->draw(pixel);
        }
    window->display();
}

void ConvolutionMatrix::MouseIncrease(float x, float y, int value) {
    int xPos = static_cast<int>(x);
    int yPos = static_cast<int>(y);
    this->origin[xPos][yPos] = value;
//    std::cout << xPos << ' ' << yPos << ' ' << this->origin[xPos][yPos]<< ' ' << this->origin[250][250] <<'\n';
}