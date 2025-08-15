#ifndef CHARACTERGENERATOR_H
#define CHARACTERGENERATOR_H

#include "character.h"
#include "CharacterInfo.h"

#include <QStringList>
#include <QRandomGenerator>

#include <random>

class characterGenerator
{
public:
    characterGenerator();

    Character generate();

private:
    std::mt19937 randomEngine;

    QString getRandomValue(const QJsonArray &list);
    QString getRandomKeyFromJsonObject(const QJsonObject &object);
};

#endif // CHARACTERGENERATOR_H
