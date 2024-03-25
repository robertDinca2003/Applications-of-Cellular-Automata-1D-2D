//
// Created by robert on 20.03.2024.
//

#ifndef OOP_ELEMENTARYRULE_H
#define OOP_ELEMENTARYRULE_H
#include <vector>
#include <iostream>

using namespace std;

class ElementaryRule {
private:
    int ruleNumber;
    int maxLength;
    int maxDepth;
    int nrCurrGen;
    int maxGenerated;
    vector<int> ruleCod = vector<int>(8);
    vector<int> startGen;
    vector<int> currGen;
    vector <vector<int>> allGenerations;
public:
    // Constructors
    explicit ElementaryRule(int ruleNumber = 90, int maxLength = 50, int maxDepth = 30, vector<int> startGen = {-1});
    ElementaryRule(const ElementaryRule&);

    // Deconstructors
    ~ElementaryRule();

    // cout <<
    friend ostream &operator<<(ostream&,const ElementaryRule&);

    // operator=
    ElementaryRule &operator=(const ElementaryRule&);

    // Getters
    [[nodiscard]] int getRuleNumber() const;
    [[nodiscard]] int getCurrGenNumber() const;
    [[nodiscard]] int getMaxDepth() const;
    [[nodiscard]] int getMaxLength() const;
    [[nodiscard]] int getElement(int,int) const;
    [[nodiscard]] vector<int> getCurrGeneration() const;
    [[nodiscard]] vector<int> getStartGen() const;


    // Setters
    void setMaxDepth(int);
    void setMaxLength(int);

    // Main Functionality
    void CreateNextGen();
    void MultipleGeneration(int);
    void DisplayCurrentGeneration() const;
    void DisplayUpToCurrentGeneration() const;
    void UpdateCurrGeneration(int);
    void GenerateToMaxDepth();
    void DisplayAll();
};


#endif //OOP_ELEMENTARYRULE_H
