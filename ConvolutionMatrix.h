//
// Created by robert on 05.04.2024.
//

#ifndef OOP_CONVOLUTIONMATRIX_H
#define OOP_CONVOLUTIONMATRIX_H

#include <SFML/Graphics.hpp>
#include <cstdlib>

class ConvolutionMatrix {
private:
    float kernel[10][10];
    float kernelSize;
    int origin[500][500];
    float nextOrigin[500][500];
public:
    ConvolutionMatrix(int);

    ConvolutionMatrix(int,int[10][10]);

    int getKernelSize() const;

    int getKernelElem(int,int) const;

    void setKernelElem(int,int,float);

    void CreateNextGeneration();

    void DisplayConvolution(sf::RenderWindow*);

    void MouseIncrease(float,float,int);

};


#endif //OOP_CONVOLUTIONMATRIX_H
