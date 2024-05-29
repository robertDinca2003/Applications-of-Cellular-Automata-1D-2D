//
// Created by robert on 21.05.2024.
//

#ifndef OOP_IMAGEENCRYPTIONSTRATEGY_H
#define OOP_IMAGEENCRYPTIONSTRATEGY_H

#include <vector>

class ImageEncryptionStrategy {
public:
    virtual void readData(std::vector<std::vector<int>> &myMat, int opt) = 0;

    virtual void doEncryption() = 0;

    virtual void doDecryption() = 0;
};


#endif //OOP_IMAGEENCRYPTIONSTRATEGY_H
