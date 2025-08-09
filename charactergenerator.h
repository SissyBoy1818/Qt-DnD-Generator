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
};

#endif // CHARACTERGENERATOR_H
