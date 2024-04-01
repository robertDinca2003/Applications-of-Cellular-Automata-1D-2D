//
// Created by User on 25.03.2024.
//

#ifndef OOP_CONWAYSGAMEOFLIFE_H
#define OOP_CONWAYSGAMEOFLIFE_H

#include<SFML/Graphics.hpp>

class ConwaysGameOfLife {
private:
    int matrix[502][1102];
    int copyMat[502][1102];
    int initialNumberCells;
    int currentGen;

    int height;
    int length;

public:
    ConwaysGameOfLife();

    ConwaysGameOfLife(int, int, int);

    explicit ConwaysGameOfLife(int mat[502][1102]);

    //ConwaysGameOfLife(const ConwaysGameOfLife &other);

    ConwaysGameOfLife &operator=(const ConwaysGameOfLife &other);

    ~ConwaysGameOfLife();

    int getInitNrCells() const;

    int getHeight() const;

    int getLength() const;

    void setInitNrCells(int);

    void CreateNextGeneration();

    void DisplayGameOfLife(sf::RenderWindow *);
};


#endif //OOP_CONWAYSGAMEOFLIFE_H
