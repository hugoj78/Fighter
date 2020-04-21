//
// Created by Hugo-Jean Egu on 21/04/2020.
//

#ifndef EXERCICE1_HIGHLANDER_H
#define EXERCICE1_HIGHLANDER_H
#pragma once
#include "Warrior.h"

class Highlander : public Warrior{

public:

    Highlander() : Warrior(150, 12, "Great Sword") {
    }

    Highlander(string type) : Warrior(150, 12, "Great Sword", _type) {
        _type = type;
    }
};
#endif //EXERCICE1_HIGHLANDER_H
