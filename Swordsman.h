//
// Created by Hugo-Jean Egu on 21/04/2020.
//

#ifndef EXERCICE1_SWORDSMAN_H
#define EXERCICE1_SWORDSMAN_H
#pragma once
#include "Warrior.h"

class Swordsman : public Warrior{

public:

    Swordsman() : Warrior(100, 5, "Sword") {
    }

    Swordsman(string type) : Warrior(100, 5, "Sword", _type) {
        _type = type;
    }
};
#endif //EXERCICE1_SWORDSMAN_H
