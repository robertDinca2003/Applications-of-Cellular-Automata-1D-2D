//
// Created by robert on 16.05.2024.
//

#include "CryptoFactory.h"
#include "ConwaysGameOfLife.h"
#include "ElementaryRule.h"
CryptMethods *CryptoFactory::createCryptMethod(int selection) {
    switch(selection){
        case 1: return new ConwaysGameOfLife();
        case 2: return new ElementaryRule();
    }
    return nullptr;
}
