//
// Created by robert on 16.05.2024.
//

#ifndef OOP_MENUFACTORY_H
#define OOP_MENUFACTORY_H
#include "NewMain.h"
#include "MenuFactory.h"
#include "Visualization.h"
#include "Cryptography.h"
//#include "Fractals.h"
#include "WolframVisualMenu.h"
#include "ConwaysVisualMenu.h"
#include "BelousovVisualMenu.h"
#include "Custom2DMenu.h"
#include "TextEncryption.h"
#include "Fractals.h"

class MenuFactory {
public:
    static Menu* createMenuInstance(int selection){
        switch (selection) {
            case 0: return nullptr;
            case 1: return new Main();
            case 11: return new Visualization();
            case 12: return new Cryptography();
            case 13: return new Fractals();
            case 111: return new WolframVisualMenu();
            case 112: return new ConwaysVisualMenu();
            case 113: return new BelousovVisualMenu();
            case 114: return new Custom2DMenu();
            case 121: return new Cryptography();
            case 122: return new TextEncryption();
            case 123: return new Cryptography();
            case 131: return new Fractals();
            case 132: return new Fractals();

        }

        return nullptr;
    }

};


#endif //OOP_MENUFACTORY_H
