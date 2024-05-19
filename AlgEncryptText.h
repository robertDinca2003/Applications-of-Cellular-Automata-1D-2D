//
// Created by robert on 17.05.2024.
//

#ifndef OOP_ALGENCRYPTTEXT_H
#define OOP_ALGENCRYPTTEXT_H
#include <string>
#include <iostream>
template<class T>
class AlgEncryptText {
private:
    T myKey;
    std::string input;
    std::string output;
public:
    AlgEncryptText(T,std::string);
    void doTextEncryption();

    std::string getOutput();
};
//
//
template<typename T>
AlgEncryptText<T>::AlgEncryptText(T key, std::string inp) {
    this->myKey = key;
    this->input = inp;
    this->output = "Not Processed yet!";
}
//
template<typename T>
void AlgEncryptText<T>::doTextEncryption()
{
    std::cout << "This type of key cannot be processed!\n";
}
//
//
template<>
void AlgEncryptText<float>::doTextEncryption() ;




#endif //OOP_ALGENCRYPTTEXT_H
