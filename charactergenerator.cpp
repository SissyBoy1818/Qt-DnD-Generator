#include "charactergenerator.h"

characterGenerator::characterGenerator()
{
    randomEngine.seed(time(nullptr));
    df();
}

Character characterGenerator::generate()
{
    QString race;
    race = getRandomKeyFromJsonObject(races);
    QString name, surname, clan;
    name = getRandomValue(races[race].toObject()["names"].toArray());
    surname = getRandomValue(races[race].toObject()["surnames"].toArray());
    clan = getRandomValue(races[race].toObject()["clans"].toArray());
    int16_t age = QRandomGenerator::global()->bounded(races[race].toObject()["ages"].toArray()[0].toInt(), races[race].toObject()["ages"].toArray()[1].toInt());

    QString fullName = name + ' ' + surname + " из " + clan;

    return Character{fullName, race, "", age};
}

QString characterGenerator::getRandomKeyFromJsonObject(const QJsonObject &object) {
    if (object.isEmpty()) {
        return QString();
    }

    QStringList keys = object.keys();

    int randomIndex = QRandomGenerator::global()->bounded(keys.size());
    return keys.at(randomIndex);
}

QString characterGenerator::getRandomValue(const QJsonArray &list) {
    if (list.isEmpty()) {
        return QString();
    }

    int index = QRandomGenerator::global()->bounded(list.size());
    return list[index].toString();
}
