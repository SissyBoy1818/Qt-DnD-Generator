#ifndef CHARACTERGENERATOR_H
#define CHARACTERGENERATOR_H

#include "character.h"
#include "characters_info.h"
#include <random>

class characterGenerator
{
public:
    characterGenerator();

    Character generate();

private:
    std::mt19937 randomEngine;
};

#endif // CHARACTERGENERATOR_H
