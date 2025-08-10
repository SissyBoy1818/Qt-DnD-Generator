#ifndef CHARACTERSHEET_H
#define CHARACTERSHEET_H

#include "character.h"

#include <QWidget>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QLabel>
#include <QPixmap>

class CharacterSheet : public QWidget
{
    Q_OBJECT
public:
    explicit CharacterSheet(const Character& character, QWidget *parent = nullptr);
    CharacterSheet(const CharacterSheet& other, QWidget *parent = nullptr);

    const QCheckBox *getSaveButton() const;

private:
    QCheckBox* saveButton;

    QLabel* name;
    QLabel* occ;
    QLabel* race;
    QLabel* age;
};

#endif // CHARACTERSHEET_H
