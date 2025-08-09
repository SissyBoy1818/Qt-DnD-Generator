#ifndef CHARACTER_H
#define CHARACTER_H

#include <QString>

class Character
{
public:
    Character(const QString& name, const QString& race, const QString& occupation, int16_t age);
    ~Character();

    // getters
    QString name() const;
    QString race() const;
    QString occupation() const;
    int16_t age() const;

    // setters
    void setName(const QString &newName);
    void setRace(const QString &newRace);
    void setOccupation(const QString &newOccupation);
    void setAge(int16_t newAge);

private:
    QString _name;
    QString _race;
    QString _occupation;
    int16_t _age;
};

#endif // CHARACTER_H
