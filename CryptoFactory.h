//
// Created by robert on 16.05.2024.
//

#ifndef OOP_CRYPTOFACTORY_H
#define OOP_CRYPTOFACTORY_H
#include "CryptMethods.h"

class CryptoFactory {
public:
     CryptMethods* createCryptMethod(int);
};


#endif //OOP_CRYPTOFACTORY_H
