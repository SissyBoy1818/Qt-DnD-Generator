#include "charactergenerator.h"

characterGenerator::characterGenerator()
{
    randomEngine.seed(time(nullptr));
}

Character characterGenerator::generate(int8_t race, int8_t name, int8_t occ)
{
    if (race == -1)     race = rand()%3;
    if (name == -1)     name = rand()%2 + race;
    if (occ == -1)      occ = rand()%3;

    return Character(name::names[name]->at(occ), race::races[race], occupation::village_occupation[occ], age::ages[race](randomEngine));
}
