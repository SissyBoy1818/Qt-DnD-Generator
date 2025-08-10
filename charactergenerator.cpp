#include "charactergenerator.h"

characterGenerator::characterGenerator()
{
    randomEngine.seed(time(nullptr));
}

Character characterGenerator::generate()
{
    int8_t race = rand()%3;
    int8_t name = rand()%2 + race;
    int8_t occ = rand()%3;

    return Character(name::names[name]->at(occ), race::races[race], occupation::village_occupation[occ], age::ages[race](randomEngine));
}
