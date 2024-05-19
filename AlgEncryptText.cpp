//
// Created by robert on 17.05.2024.
//
#include "AlgEncryptText.h"
#include <iostream>
#include <fstream>
//
//template<typename T>
//AlgEncryptText<T>::AlgEncryptText(T key, std::string inp) {
//    this->myKey = key;
//    this->input = inp;
//    this->output = "Not Processed yet!";
//}
//
//template<typename T>
//void AlgEncryptText<T>::doTextEncryption() {
//    std::cout << "This type of key cannot be processed!\n";
//}


template<> void AlgEncryptText<float>::doTextEncryption() {
    union {
        float f;
        int i;
    } keyUnion;
    keyUnion.f = myKey;
    int Xor1 = keyUnion.i >> 24;
    int Xor2 = keyUnion.i << 8 >> 24;
    int Xor3 = keyUnion.i << 16 >> 24;
    int Xor4 = keyUnion.i << 24 >> 24;
    this->output = this->input;
    for(size_t i = 0; i<this->input.size(); i++)
    {
        if(i % 4 == 0)
        {
            this->output[i] = this->input[i] ^ Xor1;
        }
        else if(i % 4 == 1)
        {
            this->output[i] = this->input[i] ^ Xor2;
        }
        else if(i % 4 == 2){
            this->output[i] = this->input[i] ^ Xor3;
        }
        else if(i%4 == 3){
            this->output[i] = this->input[i] ^ Xor4;
        }
    }
}
template<> void AlgEncryptText<int>::doTextEncryption() {
    int Xor1 = myKey >> 24;
    int Xor2 = myKey << 8 >> 24;
    int Xor3 = myKey << 16 >> 24;
    int Xor4 = myKey << 24 >> 24;
    this->output = this->input;
    for(size_t i = 0; i<this->input.size(); i++)
    {
        if(i % 4 == 0)
        {
            this->output[i] = this->input[i] ^ Xor1;
        }
        else if(i % 4 == 1)
        {
            this->output[i] = this->input[i] ^ Xor2;
        }
        else if(i % 4 == 2){
            this->output[i] = this->input[i] ^ Xor3;
        }
        else if(i%4 == 3){
            this->output[i] = this->input[i] ^ Xor4;
        }
    }
}
template<> void AlgEncryptText<char>::doTextEncryption() {
    int Xor = (int)myKey;
    this->output = this->input;
    for(size_t i = 0 ; i<this->input.size(); i++)
    {
        this->output[i] = this->input[i] ^ Xor;
    }
}
template<> void AlgEncryptText<std::string>::doTextEncryption() {
    this->output = this->input;
    for(size_t i = 0 ; i<this->input.size(); i++)
    {
        this->output[i] = this->input[i] ^ this->myKey[i%this->myKey.size()];
    }
}


template<>
std::string AlgEncryptText<int>::getOutput() {
    return this->output;
}

template<>
std::string AlgEncryptText<float>::getOutput() {
    return this->output;
}

template<>
std::string AlgEncryptText<char>::getOutput() {
    return this->output;
}

template<>
std::string AlgEncryptText<std::string>::getOutput() {
    return this->output;
}