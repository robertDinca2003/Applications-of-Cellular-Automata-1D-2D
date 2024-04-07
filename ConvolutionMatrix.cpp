//
// Created by robert on 05.04.2024.
//

#include "ConvolutionMatrix.h"
#include <cmath>
#include <SFML/Graphics.hpp>
ConvolutionMatrix::ConvolutionMatrix(int kSize) {
    this->kernelSize = kSize;

    for(int i = 0 ; i < kSize; i++)
        for(int j = 0; j< kSize; j++)
            this->kernel[i][j] = (rand()%100+1)/100.f;
    for(int i = 0 ;i < 500 ; i++)
        for(int j = 0 ; j< 500; j++)
            this->origin[i][j] = this->nextOrigin[i][j] = 0;
}

ConvolutionMatrix::ConvolutionMatrix(int kSize, int kernel[10][10]) {
    this->kernelSize = kSize;
    for(int i = 0; i<kSize; i++)
        for(int j = 0 ;j< kSize; j++)
            this->kernel[i][j] = kernel[i][j];
    for(int i = 0 ;i < 500 ; i++)
        for(int j = 0 ; j< 500; j++)
            this->origin[i][j] = this->nextOrigin[i][j] = 0;
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
            this->nextOrigin[i][j] = convSum;
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
                pixel.setFillColor(sf::Color(255*this->origin[i][j],255*this->origin[i][j],255*this->origin[i][j]));
            }
            window->draw(pixel);
        }
    window->display();
}

void ConvolutionMatrix::MouseIncrease(float x, float y, int value) {
    int xPos = static_cast<int>(x);
    int yPos = static_cast<int>(y);
    this->origin[xPos][yPos] = value;

}