#ifndef CHARACTERGENERATOR_H
#define CHARACTERGENERATOR_H

#include "character.h"
#include "characters_info.h"
#include <random>

class characterGenerator
{
public:
    characterGenerator();

    Character generate(int8_t race = -1, int8_t name = -1, int8_t occ = -1);

private:
    std::mt19937 randomEngine;
};

#endif // CHARACTERGENERATOR_H
