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

    CharacterInfo ci;

    Character generate(const QString& settings);

private:
    std::mt19937 randomEngine;

    QString getRandomValue(const QList<QString> &list);
    QString getRandomKeyFromJsonObject(const QMap<QString, RaceInfo> &object);
};

#endif // CHARACTERGENERATOR_H
