//
// Created by robert on 05.04.2024.
//

#ifndef OOP_CONVOLUTIONMATRIX_H
#define OOP_CONVOLUTIONMATRIX_H

#include <SFML/Graphics.hpp>
#include <cstdlib>

/// @brief ConvolutionMatrix - Is a class which works like a convolution matrix, based on a current matrix, it will generate a new one applying a kernel and activation function
/// @param kernel - Is a matrix which elements represents a constant which will be multiplied
/// @param kernelSize - The size of the kernel
/// @param actFunc - Is an activation matrix
/// @param origin - Is the original matrix which will be processed later
/// @param nextOrigin - Is the result of applying to the original matrix the kernel and activation function
class ConvolutionMatrix {
private:
    float kernel[10][10];
    float kernelSize;
    int actFunc;
    float origin[500][500];
    float nextOrigin[500][500];
public:
    /// @brief Constructor generating a random kernel with a given size
    explicit ConvolutionMatrix(int);

    /// @brief Constructor using a predefined kernel
    ConvolutionMatrix(int,int[10][10]);

//    int getKernelSize() const;

    /// @brief Getter for an element from the kernel
    float getKernelElem(int,int) const;

    /// @brief Setter for the activation function
    void setActFunc(int);

    /// @brief Setter for an element in the kernel
    void setKernelElem(int,int,float);

    /// @brief The activation function
    float activationFunction(int func, float val);

    /// @brief Generate the convoluted matrix
    void CreateNextGeneration();

    /// @brief Display the matrix on the screen
    void DisplayConvolution(sf::RenderWindow*);

    /// @brief  Used for increasing values based of the mouse position on the screen
    void MouseIncrease(float,float,int);

};


#endif //OOP_CONVOLUTIONMATRIX_H
