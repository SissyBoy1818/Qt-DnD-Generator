#include "charactergenerator.h"

characterGenerator::characterGenerator()
{
    srand(time(0));
}

Character characterGenerator::generate()
{
    int8_t race = rand()%3;
    int8_t name = rand()%2 + race;
    int8_t occ = rand()%3;

    return Character(rname::rnames[name]->at(occ), race::races[race], occupation::village_occupation[occ], static_cast<int16_t>(rand()%32000));
}
