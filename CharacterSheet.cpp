#include "CharacterSheet.h"

CharacterSheet::CharacterSheet(const Character& character, QWidget *parent)
    : QWidget{parent}
{
    setUI();
    // create text labels
    name->setText(character.name());
    occ->setText(character.occupation());
    race->setText(character.race());
    age->setText(QString::number(character.age()) + " лет");

    if (character.sex())
        icon->load("D:\\Programming\\dnd-generator\\generator_resources\\" + character.race() + "\\" + character.race() +  "_m.png");
    else
        icon->load("D:\\Programming\\dnd-generator\\generator_resources\\" + character.race() + "\\" + character.race() +  "_f.png");

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
    saveButton->setText("🗑");
    saveButton->setStyleSheet(
        "QPushButton {"
        "  background-color: #E57373;"
        "  color: white;"
        "  border-radius: 5px;"
        "  padding: 5px 10px;"
        "}"
        "QPushButton:hover {"
        "  background-color: #D32F2F;"
        "}"
        "QPushButton:pressed {"
        "  background-color: #B71C1C;"
        "}"
        );

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
    saveButton = new QPushButton("💾", this);
    name = new QLabel(this);
    occ = new QLabel(this);
    race = new QLabel(this);
    age = new QLabel(this);
    QSpacerItem* spacer = new QSpacerItem(10,10);

    QFont nameFont{"Arial", 16, QFont::Bold, true};
    name->setFont(nameFont);
    QFont ageFont{"Arial", 16, -1, true};
    age->setFont(ageFont);

    // add character info to layouts
    mainInfoLayout->addWidget(name);
    mainInfoLayout->addWidget(age);
    additionalInfoLayout->addWidget(race);
    additionalInfoLayout->addWidget(occ);
    additionalInfoLayout->addSpacerItem(spacer);

    // set size of wigets
    setMinimumHeight(100);
    setMaximumHeight(100);
    saveButton->setFixedSize(30,30);
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
        "   border: 1px solid #1b2433;"
        "   border-radius: 15px;"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\
                                        stop:0 #2e3f59, stop:1 #1e2a38);"
        "}"
        "QPushButton {\
            background-color: #3b6ea0;\
            color: white;\
            border: none;\
            border-radius: 15px;\
            width: 30px;\
            height: 30px;\
            font-weight: bold;\
        }\
        QPushButton:hover {\
            background-color: #325b82;\
        }\
        QPushButton:pressed {\
            background-color: #264466;\
        }"
        );

    connect(saveButton, &QPushButton::clicked, this, &CharacterSheet::hideSaveButton);
}

void CharacterSheet::hideSaveButton()
{
    saveButton->hide();
}
