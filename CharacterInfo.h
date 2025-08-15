#ifndef CHARACTERINFO_H
#define CHARACTERINFO_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QString>
#include <QDebug>

static QJsonObject races;

inline void df()
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
        races.insert(a.toString(), nroot[a.toString()]);
    }
    qDebug() << races;
}

#endif // CHARACTERINFO_H
