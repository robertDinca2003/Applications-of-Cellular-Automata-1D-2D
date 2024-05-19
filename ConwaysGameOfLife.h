//
// Created by User on 25.03.2024.
//

#ifndef OOP_CONWAYSGAMEOFLIFE_H
#define OOP_CONWAYSGAMEOFLIFE_H

#include<SFML/Graphics.hpp>
#include "CryptMethods.h"
#include <string>
#include <vector>

/// @brief ConwayGameOfLife - Is a class which simulates a 2D cellular automaton, based on the rules of Conway.
/// @param matrix - Is a matrix used for storing the current generation
/// @param copyMat - Is a copy of the current generation, which help to generate the next generation
/// @param initialNumberCells - Represent the number of cells in the first generation
/// @param currentGen - Represent the number of current generation
/// @param height - Represent the height of the matrix
/// @param length - Represent the width of the matrix
class ConwaysGameOfLife: public CryptMethods {
private:
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> copyMat;
    int initialNumberCells;
    int currentGen;

    int height;
    int length;

public:
    /// @brief Contructor with all param being generated random
    ConwaysGameOfLife();

    /// @brief Constructor with given param
    ConwaysGameOfLife(int, int, int);

    /// @brief Constructor using a predefined initial matrix
    explicit ConwaysGameOfLife(int mat[502][1102]);

    /// @brief Copy Constructor
    ConwaysGameOfLife(const ConwaysGameOfLife &other);

    /// @brief Operator =
    ConwaysGameOfLife &operator=(const ConwaysGameOfLife &other);

    /// @brief Deconstruct
    ~ConwaysGameOfLife();

    /// @brief Getter for initialNumberCells
    int getInitNrCells() const;

    /// @brief Getter for height
    int getHeight() const;

    /// @brief Getter for length
    int getLength() const;

    int getElement(int,int) const;

    /// @brief Setter for width
    void setWidth(int);

    /// @brief Setter for height
    void setHeight(int);

    /// @brief Setter for initialNumberCells
    void setInitNrCells(int);

    /// @brief Generate the next generation
    void CreateNextGeneration();

    /// @brief Display the current generation on screen
    void DisplayGameOfLife(sf::RenderWindow *);

    /// @brief Used to create an encryption code
    std::string CreateCryptMask() override;
};


#endif //OOP_CONWAYSGAMEOFLIFE_H
