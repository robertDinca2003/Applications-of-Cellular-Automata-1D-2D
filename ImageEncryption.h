//
// Created by robert on 16.05.2024.
//

#ifndef OOP_IMAGEENCRYPTION_H
#define OOP_IMAGEENCRYPTION_H
#include <utility>
#include <memory>
#include <iostream>

class ImageEncryptionStrategy{
public:
    virtual void readData() = 0;
    virtual void doEncryption()=0;
};

class StrategyBlackWhite : ImageEncryptionStrategy{
public:
    void readData() override{

    }
    void doEncryption() override{

    }
};

class StrategyColor : ImageEncryptionStrategy{
    void readData() override{

    }
    void doEncryption() override{

    }
};

class ImageEncryptionContext{
private:
    std::unique_ptr<ImageEncryptionStrategy> strategy;
public:
    explicit ImageEncryptionContext(std::unique_ptr<ImageEncryptionStrategy> &&strategy = {}) : strategy(std::move(strategy)){

    }

    void set_strategy(std::unique_ptr<ImageEncryptionStrategy> &&strategy){
        this->strategy = std::move(strategy);
    }

    void LogsFromEncryption(){
        if(strategy)
        {
            std::cout<<"There is a strategy\n";
        }
        else{
            std::cout << "There is not any strategies\n";
        }
    };
};


#endif //OOP_IMAGEENCRYPTION_H
