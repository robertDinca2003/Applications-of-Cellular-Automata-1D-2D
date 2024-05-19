//
// Created by robert on 02.04.2024.
//

#ifndef OOP_BELOUSOV_H
#define OOP_BELOUSOV_H

#include <SFML/Graphics.hpp>
#include <vector>

/// @brief Belousov-Zhabontisky Reaction - The Belousov class provide a way of visualize such chemical reaction
/// @param q - Generating rule, The cells will have a value between 0-q. When a cell get to a value of q, it will set to 0
/// @param k1 - Constant, used for calculation of next generation
/// @param k2 - Constant, used for the calculation of next generation
/// @param g - Constant, after every generation every cell will increase it's value with g
/// @parram currMat - Is a matrix which stores the current state of the Belousov
/// @param copyMat - Is a matrix which stores a copy of the Belousov
class Belousov {
private:

    int q;
    int k1;
    int k2;
    int g;
    float currMat[500][500];
    float copyMat[500][500];

public:

    /// @brief Constructor, every param will get a random value
    Belousov();

    /// @brief Constructor, with given params (q, k1, k2, g)
    Belousov(int, int, int, int);

    /// @brief Deconstruct
    ~Belousov();

    /// @brief Getter for Q
    int getQ();

    /// @brief Getter for K1
    int getK1();

    /// @brief Getter for K2
    int getK2();

    /// @brief Getter for G
    int getG();

    /// @brief Used for generate the next generation
    void CreateNextGeneration();

    /// @brief Used for displaying the Belousov
    void DisplayBelousov(sf::RenderWindow *);


    /// @brief Used for increasing the infection based on the mouse position
    void IncreaseInfection(float, float);
};


#endif //OOP_BELOUSOV_H
