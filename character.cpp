#include "character.h"

Character::Character(const QString& name, const QString& race, const QString& occupation, int16_t age)
    : _name(name), _race(race), _occupation(occupation), _age(age)
{}

Character::~Character()
{
}

QString Character::name() const
{
    return _name;
}

void Character::setName(const QString &newName)
{
    _name = newName;
}

QString Character::race() const
{
    return _race;
}

void Character::setRace(const QString &newRace)
{
    _race = newRace;
}

QString Character::occupation() const
{
    return _occupation;
}

void Character::setOccupation(const QString &newOccupation)
{
    _occupation = newOccupation;
}

int16_t Character::age() const
{
    return _age;
}

void Character::setAge(int16_t newAge)
{
    _age = newAge;
}
