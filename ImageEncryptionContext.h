//
// Created by robert on 21.05.2024.
//

#ifndef OOP_IMAGEENCRYPTIONCONTEXT_H
#define OOP_IMAGEENCRYPTIONCONTEXT_H

#include <iostream>
#include <memory>
#include "ImageEncryptionStrategy.h"

class ImageEncryptionContext {
private:
    std::unique_ptr<ImageEncryptionStrategy> strategy;
public:
    explicit ImageEncryptionContext(std::unique_ptr<ImageEncryptionStrategy> &&strategy = {}) : strategy(
            std::move(strategy)) {}

    void set_strategy(std::unique_ptr<ImageEncryptionStrategy> &&sstrategy);

    void LogsFromEncryption();

    void useStrategy(int option);

};


#endif //OOP_IMAGEENCRYPTIONCONTEXT_H
