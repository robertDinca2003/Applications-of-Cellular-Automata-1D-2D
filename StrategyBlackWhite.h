//
// Created by robert on 21.05.2024.
//

#ifndef OOP_STRATEGYBLACKWHITE_H
#define OOP_STRATEGYBLACKWHITE_H


#include <vector>
#include <string>
#include <opencv2/opencv.hpp>
#include "ImageEncryptionStrategy.h"
#include "ElementaryRule.h"

class StrategyBlackWhite : public ImageEncryptionStrategy {

public:
    void readData(std::vector<std::vector<int>> &binaryMatrix, int opt) override;

    void doEncryption() override;

    void doDecryption() override;

};


#endif //OOP_STRATEGYBLACKWHITE_H
