//
// Created by Hugo-Jean Egu on 21/04/2020.
//

#ifndef EXERCICE1_VIKING_H
#define EXERCICE1_VIKING_H
#pragma once
#include "Warrior.h"

class Viking : public Warrior{

public:

    Viking(): Warrior(120, 6, "Axe") {
    }
};

#endif //EXERCICE1_VIKING_H
