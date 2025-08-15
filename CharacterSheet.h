#ifndef CHARACTERSHEET_H
#define CHARACTERSHEET_H

#include "character.h"
//#include "characters_info.h"

#include <QWidget>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>

class CharacterSheet : public QWidget
{
    Q_OBJECT
public:
    explicit CharacterSheet(const Character& character, QWidget *parent = nullptr);
    CharacterSheet(const CharacterSheet& other, QWidget *parent = nullptr);

    const QPushButton *getSaveButton() const;

private:
    void setUI();

    QLabel* imageLabel;
    QPushButton* saveButton;
    QPixmap* icon;

    QLabel* name;
    QLabel* occ;
    QLabel* race;
    QLabel* age;

private slots:
    void hideSaveButton();
};

#endif // CHARACTERSHEET_H
