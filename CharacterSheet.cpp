#include "CharacterSheet.h"

CharacterSheet::CharacterSheet(const Character& character, QWidget *parent)
    : QWidget{parent}
{
    setUI();
    // create text labels
    name->setText(character.name());
    occ->setText(character.occupation());
    race->setText(character.race());
    age->setText(QString::number(character.age()));

    icon->load(pic::pics[character.race()]);
    imageLabel->setPixmap(icon->scaled(75, 75, Qt::KeepAspectRatio));
}

CharacterSheet::CharacterSheet(const CharacterSheet &other, QWidget *parent)
    : QWidget{parent}
{
    setUI();
    // create text labels
    name->setText(other.name->text());
    occ->setText(other.occ->text());
    race->setText(other.race->text());
    age->setText(other.age->text());

    *icon = *(other.icon);
    imageLabel->setPixmap(icon->scaled(75, 75, Qt::KeepAspectRatio));
}

const QPushButton *CharacterSheet::getSaveButton() const
{
    return saveButton;
}

void CharacterSheet::setUI()
{
    // initialize layouts and buttons
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    imageLabel = new QLabel();
    icon = new QPixmap;
    QVBoxLayout* charInfoLayout = new QVBoxLayout();
    QHBoxLayout* mainInfoLayout = new QHBoxLayout();
    QHBoxLayout* additionalInfoLayout = new QHBoxLayout();
    saveButton = new QPushButton("save", this);
    name = new QLabel(this);
    occ = new QLabel(this);
    race = new QLabel(this);
    age = new QLabel(this);

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
    mainLayout->addWidget(imageLabel, 2);
    mainLayout->addLayout(charInfoLayout, 18);
    mainLayout->addWidget(saveButton, 1);
    charInfoLayout->addLayout(mainInfoLayout, 3);
    charInfoLayout->addLayout(additionalInfoLayout, 1);

    setAttribute(Qt::WA_StyledBackground, true);
    setObjectName("characterSheet");
    setStyleSheet(
        "#characterSheet {"
        "   border: 3px solid black;"
        "   border-radius: 15px;"
        "   background-color: #3d5375;"
        "}"
        );

    connect(saveButton, &QPushButton::clicked, this, &CharacterSheet::hideSaveButton);
}

void CharacterSheet::hideSaveButton()
{
    saveButton->hide();
}
