//
// Created by robert on 20.03.2024.
//

#ifndef OOP_ELEMENTARYRULE_H
#define OOP_ELEMENTARYRULE_H

#include <vector>
#include <iostream>
#include <string>
#include "CryptMethods.h"


/// @brief An elementary rule is an 1D automaton, that means a generation is represent by a vector(1D array). Every elementary rule has it's own rule set for creating the next generation. The number of every rule represent the rule set written in a shorter way by the binary representation of the number
/// @param ruleNumber The identifier for every rule
/// @param maxLength The maximum length of a generation
/// @param maxDepth The maximum number of generations which can be created
/// @param nrCurrGen The current generation number
/// @param maxGenerated In term of generation numbers, the biggest of them which was generated (<= maxDepth)
/// @param ruleCode It is a vector containing the rules of every generation
/// @param startGen The initial generation
/// @param currGen The current generation
/// @param allGenerations All generation which can be accessed by index of every generation
class ElementaryRule: public CryptMethods {
private:
    int ruleNumber;
    int maxLength;
    int maxDepth;
    int nrCurrGen;
    int maxGenerated;
    std::vector<int> ruleCod = std::vector<int>(8);
    std::vector<int> startGen;
    std::vector<int> currGen;
    std::vector<std::vector<int>> allGenerations;
public:
    // Constructors
    /// @brief Constructor based on a specific rule identifier, length and depth
    explicit ElementaryRule(int ruleNumber = 90, int maxLength = 50, int maxDepth = 30, std::vector<int> startGen = {-1});

    /// @brief Copy constructor
    ElementaryRule(const ElementaryRule &);

    // Deconstructors
    /// @brief Deconstruct
    ~ElementaryRule();

    // cout <<
    /// @brief operator<<
    friend std::ostream &operator<<(std::ostream &, const ElementaryRule &);

    // operator=
    /// @brief operator=
    ElementaryRule &operator=(const ElementaryRule &);

    // Getters
    int getRuleNumber() const;

    int getCurrGenNumber() const;

    int getMaxDepth() const;

    int getMaxLength() const;

    int getElement(int, int) const;

    std::vector<int> getCurrGeneration() const;

    std::vector<int> getStartGen() const;


    // Setters
    void setMaxDepth(int);

    void setMaxLength(int);

    void setRuleNumber(int);

    // Main Functionality
    /// @brief CreateNextGen() - Used for creating the next generation based on the current one
    void CreateNextGen();

    /// @brief Used to generate multiple generation, it is based on CreateNextGen()
    void MultipleGeneration(int);

    /// @brief Used for displaying the current generation
    void DisplayCurrentGeneration() const;

    /// @brief Used to display all generation from 0 to nrCurrGen
    void DisplayUpToCurrentGeneration() const;

    /// @brief It is used to go to a given generation by the parameter number
    void UpdateCurrGeneration(int);

    /// @brief It is used to create all generations
    void GenerateToMaxDepth();

    void DisplayAll();

    std::string CreateCryptMask() override;
};


#endif //OOP_ELEMENTARYRULE_H
