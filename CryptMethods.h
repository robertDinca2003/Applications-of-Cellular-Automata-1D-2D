//
// Created by robert on 16.04.2024.
//

#ifndef OOP_CRYPTMETHODS_H
#define OOP_CRYPTMETHODS_H

#include <string>
/// @brief CryptMethods - Is a class which encrypt text based on specific rules
class CryptMethods {
public:
    virtual std::string CreateCryptMask() = 0;

    virtual ~CryptMethods() = default;
};


#endif //OOP_CRYPTMETHODS_H
