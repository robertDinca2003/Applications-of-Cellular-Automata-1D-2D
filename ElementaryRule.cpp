//
// Created by robert on 20.03.2024.
//
#include "ElementaryRule.h"

ElementaryRule::ElementaryRule(int ruleNumber, int maxLength, int maxDepth, std::vector<int> startGen) {
    // Initialize integer variables
    this->ruleNumber = ruleNumber;
    this->maxLength = maxLength;
    this->maxDepth = maxDepth;
    this->nrCurrGen = 0;
    this->maxGenerated = 0;

    //Generate Rule Set
    int tempNumber = this->ruleNumber;
    for (int i = 0; i < 8; i++) {
        ruleCod[i] = tempNumber & 1;
        tempNumber = tempNumber >> 1;

    }

    //Setting up vector lengths
    //Initialize initial generation
    this->currGen.resize(maxLength);

    this->startGen.resize(maxLength);
    for (int i = 0; i < maxLength; i++)
        this->startGen[i] = 0;
    if (startGen.size() == 1 && startGen[0] == -1)
        this->startGen[maxLength / 2] = 1;
    else
        for (int i = 0; i < maxLength; i++)
            this->startGen[i] = startGen[i];

    allGenerations.resize(maxDepth);
    for (int i = 0; i < maxDepth; i++)
        allGenerations[i].resize(maxLength);
    for (int i = 0; i < maxLength; i++)
        allGenerations[0][i] = this->startGen[i], currGen[i] = this->startGen[i];
   std::cout << "Constructed Elementary Rule\n";
}

ElementaryRule::ElementaryRule(const ElementaryRule &other) : ruleNumber(other.ruleNumber), maxLength(other.maxLength),
                                                              maxDepth(other.maxDepth), nrCurrGen(other.nrCurrGen),
                                                              maxGenerated(other.maxGenerated) {
   std::cout << "I am starting from here\n";
    for (int i = 0; i < 8; i++)
        this->ruleCod[i] = other.ruleCod[i];
    this->startGen.resize(other.startGen.size());
    for (size_t i = 0; i < other.startGen.size(); i++)
        this->startGen[i] = other.startGen[i];
    this->allGenerations.resize(other.maxDepth);
   std::cout << "I am here 1\n";
    for (size_t i = 0; i < allGenerations.size(); i++)
        this->allGenerations[i].resize(maxLength);

    for (size_t i = 0; i < allGenerations.size(); i++)
        for (int j = 0; j < maxLength; j++)
            this->allGenerations[i][j] = other.allGenerations[i][j];
    this->currGen.resize(maxLength);
    for (int i = 0; i < maxLength; i++)
        this->currGen[i] = other.allGenerations[other.nrCurrGen][i];
   std::cout << "I am here 2\n";

}

ElementaryRule::~ElementaryRule() {
   std::cout << "Deconstructed Elementary Rule\n";
}

std::ostream &operator<<(std::ostream &os, const ElementaryRule &rule) {
    os << "ruleNumber: " << rule.ruleNumber << " maxLength: " << rule.maxLength << " maxDepth: " << rule.maxDepth
       << " nrCurrGen: " << rule.nrCurrGen << " maxGenerated: " << rule.maxGenerated;
    return os;
}


ElementaryRule &ElementaryRule::operator=(const ElementaryRule &other) {
   std::cout << "Stating\n";
    if (this == &other)
        return *this;
   std::cout << "I am here 1\n";
    this->ruleNumber = other.ruleNumber;
    this->maxLength = other.maxLength;
    this->maxDepth = other.maxDepth;
    this->nrCurrGen = other.nrCurrGen;
    this->maxGenerated = other.maxGenerated;
   std::cout << "I am here 2\n";
    for (int i = 0; i < 8; i++)
        this->ruleCod[i] = other.ruleCod[i];
    this->startGen.resize(other.startGen.size());
    for (size_t i = 0; i < other.startGen.size(); i++)
        this->startGen[i] = other.startGen[i];
    this->allGenerations.resize(other.maxDepth);
   std::cout << "I am here 3\n";
    for (size_t i = 0; i < allGenerations.size(); i++)
        this->allGenerations[i].resize(maxLength);
    for (size_t i = 0; i < allGenerations.size(); i++)
        for (int j = 0; j < maxLength; j++)
            this->allGenerations[i][j] = other.allGenerations[i][j];
    this->currGen.resize(maxLength);
    for (int i = 0; i < maxLength; i++)
        this->currGen[i] = other.allGenerations[other.nrCurrGen][i];

    return *this;
}

int ElementaryRule::getRuleNumber() const {
    return this->ruleNumber;
}

int ElementaryRule::getCurrGenNumber() const {
    return this->nrCurrGen;
}

int ElementaryRule::getMaxDepth() const {
    return this->maxDepth;
}

int ElementaryRule::getMaxLength() const {
    return this->maxLength;
}

int ElementaryRule::getElement(int generation, int position) const {
    return this->allGenerations[generation][position];
}

std::vector<int> ElementaryRule::getCurrGeneration() const {
    return this->currGen;
}

std::vector<int> ElementaryRule::getStartGen() const {
    return this->startGen;
}

void ElementaryRule::setMaxDepth(int newMaxDepth) {
    if (newMaxDepth < this->maxDepth) {
        //Throw Exception
       std::cout << "Can t decrease in depth\n";
        return;
    }
    this->maxDepth = newMaxDepth;
    this->allGenerations.resize(this->maxDepth);
    for(size_t i = 0 ; i < this->allGenerations.size(); i++)
    {
        if((int)this->allGenerations[i].size() != this->maxLength)
        {
            this->allGenerations[i].resize(this->maxLength);
        }
    }

}

void ElementaryRule::setMaxLength(int newMaxLength) {
    if (newMaxLength < this->maxLength) {
        //Throw Exception
       std::cout << "Cant decrease in length\n";
        return;
    }
    this->maxLength = newMaxLength;
    this->currGen.resize(this->maxLength);
    for (int i = 0; i < maxDepth; i++)
        allGenerations[i].resize(this->maxLength);

}

void ElementaryRule::CreateNextGen() {
    if (nrCurrGen < maxGenerated) {
        nrCurrGen++;
        for (int i = 0; i < maxLength; i++)
            currGen[i] = allGenerations[nrCurrGen][i];
        return;
    }
    if (nrCurrGen == maxDepth - 1) {
        // Exception throw
       std::cout << "Max Size Reached";
        return;
    }
    nrCurrGen++;
    maxGenerated++;
    std::vector<int> temp(maxLength);
    for (int i = 0; i < maxLength; i++)
        temp[i] = currGen[(i - 1 + maxLength) % maxLength] * 4 + currGen[i] * 2 +
                  currGen[(i + maxLength + 1) % maxLength];
    for (int i = 0; i < maxLength; i++)
        currGen[i] = ruleCod[temp[i]], allGenerations[nrCurrGen][i] = currGen[i];

}

void ElementaryRule::MultipleGeneration(int depth) {
    if (depth >= maxDepth) {
        //Throw Exception
        return;
    }
    if (depth < maxGenerated)
        return;
    for (int i = nrCurrGen; i < depth; i++)
        CreateNextGen();
}

void ElementaryRule::DisplayCurrentGeneration() const {
   std::cout << "Current generation " << nrCurrGen << "\n";
    for (int i = 0; i < maxLength; i++) {
       std::cout << currGen[i];
    }
   std::cout << "\n";
}

void ElementaryRule::DisplayUpToCurrentGeneration() const {
   std::cout << "Generation from 0 to " << nrCurrGen << ":\n";
    for (int i = 0; i <= nrCurrGen; i++) {
        for (int j = 0; j < maxLength; j++) {
            if (allGenerations[i][j])
               std::cout << 0;
            else
               std::cout << ' ';
        }
       std::cout << '\n';
    }
}

void ElementaryRule::UpdateCurrGeneration(int number) {
    if (number < maxGenerated) {
        this->nrCurrGen = number;
        for (int i = 0; i < maxLength; i++) {
            currGen[i] = allGenerations[nrCurrGen][i];
        }
    }
    if (number > maxGenerated) {
        MultipleGeneration(number);
    }

}

void ElementaryRule::GenerateToMaxDepth() {
    MultipleGeneration(maxDepth - 1);
}

void ElementaryRule::DisplayAll() {
    if (maxGenerated < maxDepth - 1)
        GenerateToMaxDepth();
    UpdateCurrGeneration(maxDepth - 1);
    DisplayUpToCurrentGeneration();

}

void ElementaryRule::setRuleNumber(int ruleNum) {
    this->ruleNumber = ruleNum;
    for(int i = 0 ; i < 8 ; i++)
        this->ruleCod[i] = ruleNum & 1 , ruleNum = ruleNum >> 1;

}

std::string ElementaryRule::CreateCryptMask() {
    std::cout <<"i am outputed\n";
    int height = this->getMaxDepth()-1;
    int length = this->getMaxLength();
    int startPoint = length - (1+height*2);
    if(startPoint < 0) startPoint = 0;
    char byte=0;
    int cnt = 7;
    std::string output = "";
    this->GenerateToMaxDepth();
    for(int i = startPoint ; i < std::min(startPoint + (height)*2,length); i++)
    {
        std::cout << i << "\n";
        if(cnt == 0){
            output.push_back(byte);
            byte = 0;
            cnt = 7;
        }

        byte = byte ^ (this->getElement(height,i) << (i%7));

        cnt--;
    }
    if(cnt != 7)
        output.push_back(byte);
    std::cout << output<<"\ni am outputed\n";
    return output;
}
