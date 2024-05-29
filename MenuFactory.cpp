//
// Created by robert on 16.05.2024.
//

#include "MenuFactory.h"

Menu* MenuFactory::createMenuInstance(int selection) {
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
        case 121: return new ImageEncryption();
        case 122: return new TextEncryption();
        case 131: return new Fractals();
        case 132: return new Fractals();

    }

    return nullptr;
}