//
// Created by User on 25.03.2024.
//
#include "ConwaysGameOfLife.h"
#include <iostream>

using namespace std;

ConwaysGameOfLife::ConwaysGameOfLife() {
    cout << "Constructed Game of Life\n";
    this->height = 500;
    this->length = 1100;
    for (int i = 0; i < 502; i++)
        for (int j = 0; j < 1102; j++)
            this->matrix[i][j] = this->copyMat[i][j] = 0;
    this->initialNumberCells = rand() % (500 * 1100);
    for (int x = 0; x < this->initialNumberCells; x++) {
        this->matrix[rand() % 502][rand() % 1102] = 1;
    }
    this->currentGen = 0;
}

ConwaysGameOfLife::ConwaysGameOfLife(int initialNumberCells, int height, int length) {
    cout << "Constructed Game of Life\n";
    this->height = height;
    this->length = length;
    this->initialNumberCells = initialNumberCells;
    for (int i = 0; i < this->height + 2; i++)
        for (int j = 0; j < this->length + 2; j++)
            this->matrix[i][j] = this->copyMat[i][j] = 0;
    for (int x = 0; x < this->initialNumberCells; x++) {
        this->matrix[rand() % (this->height + 2)][rand() % (this->length + 2)] = 1;
    }
    this->currentGen = 0;
}

ConwaysGameOfLife::ConwaysGameOfLife(int mat[502][1102]) {
    int initCellNumber = 0;
    cout << "Constructed Game of Life\n";
    for (int i = 0; i < 502; i++)
        for (int j = 0; j < 1102; j++) {
            this->matrix[i][j] = mat[i][j];
            this->copyMat[i][j] = 0;
            initCellNumber += mat[i][j];
        }
    this->initialNumberCells = initCellNumber;
    this->currentGen = 0;
    this->height = 500;
    this->length = 500;
}

ConwaysGameOfLife::ConwaysGameOfLife(const ConwaysGameOfLife &other) {

    this->length = other.length;
    this->height = other.height;
    this->initialNumberCells = other.initialNumberCells;
    this->currentGen = other.currentGen;
    for (int i = 0; i < 502; i++)
        for (int j = 0; j < 1102; j++)
            this->matrix[i][j] = other.matrix[i][j], this->copyMat[i][j] = other.copyMat[i][j];

}

ConwaysGameOfLife &ConwaysGameOfLife::operator=(const ConwaysGameOfLife &other) {
    this->length = other.length;
    this->height = other.height;
    this->initialNumberCells = other.initialNumberCells;
    this->currentGen = other.currentGen;
    for (int i = 0; i < 502; i++)
        for (int j = 0; j < 1102; j++)
            this->matrix[i][j] = other.matrix[i][j], this->copyMat[i][j] = other.copyMat[i][j];
    return *this;
}

ConwaysGameOfLife::~ConwaysGameOfLife() {
    cout << "Deconstructed Game of Life\n";
}

int ConwaysGameOfLife::getInitNrCells() const {
    return this->initialNumberCells;
}

int ConwaysGameOfLife::getHeight() const {
    return this->height;
}

int ConwaysGameOfLife::getLength() const {
    return this->length;
}

void ConwaysGameOfLife::setInitNrCells(int nr) {
    this->initialNumberCells = nr;
}

void ConwaysGameOfLife::CreateNextGeneration() {
    cout << "Generation " << currentGen << " created\n";
    for (int i = 1; i <= this->height; i++)
        for (int j = 1; j <= this->length; j++) {
            this->copyMat[i][j] = this->matrix[i + 1][j + 1] + this->matrix[i + 1][j] + this->matrix[i + 1][j - 1] +
                                  this->matrix[i][j - 1] + this->matrix[i][j + 1] + this->matrix[i - 1][j + 1] +
                                  this->matrix[i - 1][j] + this->matrix[i - 1][j - 1];
            if ((this->matrix[i][j] == 1 && (this->copyMat[i][j] == 2 || this->copyMat[i][j] == 3)) ||
                (this->matrix[i][j] == 0 && this->copyMat[i][j] == 3))
                this->copyMat[i][j] = 1;
            else
                this->copyMat[i][j] = 0;
        }
    for (int i = 0; i < this->height + 2; i++)
        for (int j = 0; j < this->length + 2; j++)
            this->matrix[i][j] = this->copyMat[i][j];
    this->currentGen++;
}

void ConwaysGameOfLife::DisplayGameOfLife(sf::RenderWindow *window) {

    float pixelSize = min(1102 / (this->length + 2), 502 / (this->height + 2));

    float startX = (1200.f - pixelSize * this->length) / 2.f;
    float startY = 85.f;


    sf::RectangleShape pixel(sf::Vector2(pixelSize, pixelSize));

    for (int i = 0; i < this->height + 2; i++)
        for (int j = 0; j < this->length + 2; j++) {
            if (i == 0 || i == this->height + 1 || j == 0 || j == this->length + 1)
                pixel.setFillColor(sf::Color::Black);
            else if (this->matrix[i][j] == 1)
                pixel.setFillColor(sf::Color::Blue);
            else
                pixel.setFillColor(sf::Color::White);
            pixel.setPosition(sf::Vector2(startX + j * pixelSize, startY + i * pixelSize));
            window->draw(pixel);

        }
    window->display();
}

void ConwaysGameOfLife::setWidth(int width) {
    this->length = width;
}

void ConwaysGameOfLife::setHeight(int h) {
    this->height = h;
}

std::string ConwaysGameOfLife::CreateCryptMask() {
    return "";
}
