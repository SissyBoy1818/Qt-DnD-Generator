#ifndef CHARACTERINFO_H
#define CHARACTERINFO_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QString>
#include <QDebug>

struct RaceInfo
{
    QList<QString> names;
    QList<QString> surnames;
    QList<QString> clans;
    std::pair<int,int> lifetime;

    RaceInfo() {};

    RaceInfo(const QJsonObject& jsonObject) {
        for (const QJsonValue& v : jsonObject["names"].toArray()) {
            names.append(v.toString());
        }
        for (const QJsonValue& v : jsonObject["surnames"].toArray()) {
            surnames.append(v.toString());
        }
        for (const QJsonValue& v : jsonObject["clans"].toArray()) {
            clans.append(v.toString());
        }
        lifetime.first = jsonObject["ages"].toArray()[0].toInt();
        lifetime.second = jsonObject["ages"].toArray()[1].toInt();
    };
};

class CharacterInfo
{
public:
    CharacterInfo();
    const QMap<QString, RaceInfo>& races() const;

private:
    QMap<QString, RaceInfo> _races;
};

inline CharacterInfo::CharacterInfo()
{
    QFile file("D:\\Programming\\dnd-generator\\generator_resources\\races.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject root = doc.object();
    QJsonArray race = root["race"].toArray();

    for (auto a : race){
        QFile nfile("D:\\Programming\\dnd-generator\\generator_resources\\" + a.toString() + "\\" + a.toString() + ".json");
        nfile.open(QIODevice::ReadOnly | QIODevice::Text);
        QString ndata = nfile.readAll();
        nfile.close();
        QJsonDocument ndoc = QJsonDocument::fromJson(ndata.toUtf8());
        QJsonObject nroot = ndoc.object();
        _races[a.toString()] = RaceInfo(nroot[a.toString()].toObject());
    }
    qDebug() << _races.keys();
}

inline const QMap<QString, RaceInfo>& CharacterInfo::races() const
{
    return _races;
}

#endif // CHARACTERINFO_H
