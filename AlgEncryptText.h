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
AlgEncryptText<T>::AlgEncryptText(const T key, const std::string inp) {
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
//template<>
//void AlgEncryptText<float>::doTextEncryption() ;
//extern template class AlgEncryptText<float>;
//extern template class AlgEncryptText<char>;
//extern template class AlgEncryptText<int>;
template<>
void AlgEncryptText<float>::doTextEncryption();
template<>
void AlgEncryptText<int>::doTextEncryption();
template<>
void AlgEncryptText<char>::doTextEncryption();
template<>
void AlgEncryptText<std::string>::doTextEncryption();

template<typename T>
std::string AlgEncryptText<T>::getOutput() {
    return output;
}


#endif //OOP_ALGENCRYPTTEXT_H
