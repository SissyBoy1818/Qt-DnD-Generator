#include "characterlist.h"

characterList::characterList(const Character& character, QWidget *parent)
    : QWidget{parent}
{
    // initialize layouts and buttons
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    QLabel* imageLabel = new QLabel();
    QPixmap icon("D:\\Programming\\dnd-generator\\pic.png");
    QVBoxLayout* charInfoLayout = new QVBoxLayout();
    QHBoxLayout* mainInfoLayout = new QHBoxLayout();
    QHBoxLayout* additionalInfoLayout = new QHBoxLayout();
    QCheckBox* saveButton = new QCheckBox(this);

    // create text labels
    QLabel* text1 = new QLabel(character.name(), this);
    QLabel* text2 = new QLabel(character.occupation(), this);
    QLabel* text3 = new QLabel(character.race(), this);
    QLabel* text4 = new QLabel(QString::number(character.age()), this);

    // add character info to layouts
    mainInfoLayout->addWidget(text1);
    mainInfoLayout->addWidget(text2);
    additionalInfoLayout->addWidget(text3);
    additionalInfoLayout->addWidget(text4);


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
