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
#include "ImageEncryption.h"

class MenuFactory {
public:
    static Menu *createMenuInstance(int selection);

};


#endif //OOP_MENUFACTORY_H
