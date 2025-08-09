#include "character_generator.h"

character_generator::character_generator(QWidget *parent)
    : QWidget(parent)
{
    // initialize layouts and buttons
    mainLayout = new QHBoxLayout(this);
    generateButton = new QPushButton("Generate");
    showSavedButton = new QPushButton("Show Saved");

    // create menu and add buttons
    QWidget* menuWidget = new QWidget();
    QVBoxLayout* menuLayout = new QVBoxLayout(menuWidget);
    menuLayout->addWidget(generateButton);
    menuLayout->addWidget(showSavedButton);
    menuLayout->addStretch();

    // create scrollarea with characters
    QScrollArea* scrollArea = new QScrollArea();
    QWidget* characterListWidget = new QWidget();
    QVBoxLayout* characterListLayout = new QVBoxLayout(characterListWidget);

    scrollArea->setWidget(characterListWidget);

    // add all layouts to main layout
    mainLayout->addWidget(menuWidget, 1);
    mainLayout->addWidget(scrollArea, 4);

    setLayout(mainLayout);
    resize(800,600);

    // connect slots and signals
    connect(generateButton, &QPushButton::clicked, this, &character_generator::generateNewList);
}

character_generator::~character_generator() {}

void character_generator::generateNewList()
{
    qDebug() << "clicked";
}
