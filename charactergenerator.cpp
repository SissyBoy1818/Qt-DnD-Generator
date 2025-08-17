#include "charactergenerator.h"

characterGenerator::characterGenerator() : ci()
{
    randomEngine.seed(time(nullptr));
}

Character characterGenerator::generate(const QString& settings)
{
    QString race, name, surname, clan;
    if (settings == "random")
        race = getRandomKeyFromJsonObject(ci.races());
    else
        race = settings;
    name = getRandomValue(ci.races()[race].names);
    surname = getRandomValue(ci.races()[race].surnames);
    clan = getRandomValue(ci.races()[race].clans);
    int16_t age = QRandomGenerator::global()->bounded(ci.races()[race].lifetime.first, ci.races()[race].lifetime.second);

    QString fullName = name + ' ' + surname + " из " + clan;
    bool sex = QRandomGenerator::global()->bounded(0,2);

    return Character{fullName, race, "", age, sex};
}

QString characterGenerator::getRandomKeyFromJsonObject(const QMap<QString, RaceInfo> &object) {
    if (object.isEmpty()) {
        return QString();
    }

    QStringList keys = object.keys();

    int randomIndex = QRandomGenerator::global()->bounded(keys.size());
    return keys.at(randomIndex);
}

QString characterGenerator::getRandomValue(const QList<QString> &list) {
    if (list.isEmpty()) {
        return QString();
    }

    int index = QRandomGenerator::global()->bounded(list.size());
    return list[index];
}
