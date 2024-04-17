//
// Created by robert on 16.04.2024.
//

#ifndef OOP_CRYPTMETHODS_H
#define OOP_CRYPTMETHODS_H

#include <string>

class CryptMethods {
public:
    virtual std::string CreateCryptMask() = 0;

    virtual ~CryptMethods() = default;
};


#endif //OOP_CRYPTMETHODS_H
