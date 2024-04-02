//
// Created by robert on 02.04.2024.
//

#ifndef OOP_BELOUSOV_H
#define OOP_BELOUSOV_H
#include <SFML/Graphics.hpp>
#include <vector>

/// @brief Belousov-Zhabontisky Reaction - The Belousov class provide a way of simulate such reaction
class Belousov {
private:

    int q;
    int k1;
    int k2;
    int g;
    float currMat[500][500];
    float copyMat[500][500];

public:

    Belousov();

    Belousov(int,int,int,int);

    ~Belousov();

    int getQ();

    int getK1();

    int getK2();

    int getG();

    void CreateNextGeneration();

    void DisplayBelousov(sf::RenderWindow*);

    void IncreaseInfection(float,float);
};


#endif //OOP_BELOUSOV_H
