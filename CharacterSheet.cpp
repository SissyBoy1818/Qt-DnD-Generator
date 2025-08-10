#include "CharacterSheet.h"

CharacterSheet::CharacterSheet(const Character& character, QWidget *parent)
    : QWidget{parent}
{
    // initialize layouts and buttons
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    QLabel* imageLabel = new QLabel();
    QPixmap icon("D:\\Programming\\dnd-generator\\pic.png");
    QVBoxLayout* charInfoLayout = new QVBoxLayout();
    QHBoxLayout* mainInfoLayout = new QHBoxLayout();
    QHBoxLayout* additionalInfoLayout = new QHBoxLayout();
    saveButton = new QCheckBox(this);

    // create text labels
    name = new QLabel(character.name(), this);
    occ = new QLabel(character.occupation(), this);
    race = new QLabel(character.race(), this);
    age = new QLabel(QString::number(character.age()), this);

    // add character info to layouts
    mainInfoLayout->addWidget(name);
    mainInfoLayout->addWidget(occ);
    additionalInfoLayout->addWidget(race);
    additionalInfoLayout->addWidget(age);


    // set size of wigets
    setMinimumHeight(100);
    setMaximumHeight(100);
    saveButton->setMinimumWidth(50);
    resize(400, 100);

    // add widgets to layouts
    imageLabel->setPixmap(icon.scaled(75, 75, Qt::KeepAspectRatio));
    mainLayout->addWidget(imageLabel, 2);
    mainLayout->addLayout(charInfoLayout, 18);
    mainLayout->addWidget(saveButton, 1);
    charInfoLayout->addLayout(mainInfoLayout, 3);
    charInfoLayout->addLayout(additionalInfoLayout, 1);
}

CharacterSheet::CharacterSheet(const CharacterSheet &other, QWidget *parent)
    : QWidget{parent}
{
    // initialize layouts and buttons
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    QLabel* imageLabel = new QLabel();
    QPixmap icon("D:\\Programming\\dnd-generator\\pic.png");
    QVBoxLayout* charInfoLayout = new QVBoxLayout();
    QHBoxLayout* mainInfoLayout = new QHBoxLayout();
    QHBoxLayout* additionalInfoLayout = new QHBoxLayout();
    saveButton = new QCheckBox(this);

    // create text labels
    QLabel* name = new QLabel(other.name->text(), this);
    QLabel* occ = new QLabel(other.occ->text(), this);
    QLabel* race = new QLabel(other.race->text(), this);
    QLabel* age = new QLabel(other.age->text(), this);

    // add character info to layouts
    mainInfoLayout->addWidget(name);
    mainInfoLayout->addWidget(occ);
    additionalInfoLayout->addWidget(race);
    additionalInfoLayout->addWidget(age);

    // set size of wigets
    setMaximumHeight(100);
    saveButton->setMinimumWidth(50);
    resize(400, 100);

    // add widgets to layouts
    imageLabel->setPixmap(icon.scaled(75, 75, Qt::KeepAspectRatio));
    mainLayout->addWidget(imageLabel, 2);
    mainLayout->addLayout(charInfoLayout, 18);
    mainLayout->addWidget(saveButton, 1);
    charInfoLayout->addLayout(mainInfoLayout, 3);
    charInfoLayout->addLayout(additionalInfoLayout, 1);
}

const QCheckBox *CharacterSheet::getSaveButton() const
{
    return saveButton;
}
