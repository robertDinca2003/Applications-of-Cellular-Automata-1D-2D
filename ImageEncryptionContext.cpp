//
// Created by robert on 21.05.2024.
//

#include "ImageEncryptionContext.h"


void ImageEncryptionContext::set_strategy(std::unique_ptr<ImageEncryptionStrategy> &&sstrategy){
    this->strategy = std::move(sstrategy);
}

void ImageEncryptionContext::LogsFromEncryption() {
    if(strategy)
    {
        std::cout<<"There is a strategy\n";
    }
    else{
        std::cout << "There is not any strategies\n";
    }
};
void ImageEncryptionContext::useStrategy(int option) {
    if (!option) {
        this->strategy->doEncryption();
        std::cout << "ENC\n";
    } else {
        this->strategy->doDecryption();
        std::cout << "DEC\n";
    }
}