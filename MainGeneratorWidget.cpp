#include "MainGeneratorWidget.h"

MainGeneratorWidget::MainGeneratorWidget(QWidget *parent)
    : QWidget(parent)
{
    // initialize layouts and buttons
    mainLayout = new QHBoxLayout(this);
    workWidget = new QStackedWidget(this);
    generateButton = new QPushButton("Generator");
    showSavedButton = new QPushButton("Saved chars");

    // create menu and add buttons
    QWidget* menuWidget = new QWidget();
    QVBoxLayout* menuLayout = new QVBoxLayout(menuWidget);
    menuLayout->addWidget(generateButton);
    menuLayout->addWidget(showSavedButton);

    // create scrollarea with characters
    // QScrollArea* scrollArea = new QScrollArea();
    characterListLayout = new QVBoxLayout(this);

    // scrollArea->setWidget(characterListWidget);

    // add all layouts to main layout
    mainLayout->addWidget(menuWidget, 1);
    mainLayout->addLayout(characterListLayout,7);
    // mainLayout->addWidget(scrollArea, 4);

    setLayout(mainLayout);
    resize(800,600);

    // connect slots and signals
    connect(generateButton, &QPushButton::clicked, this, &MainGeneratorWidget::generateNewList);
}

MainGeneratorWidget::~MainGeneratorWidget() {}

void MainGeneratorWidget::generateNewList()
{
    qDebug() << "clicked";

    for (auto ch : generatedCharacters) {
        characterListLayout->removeWidget(ch);
        delete ch;
    }
    generatedCharacters.clear();

    for (int i = 0; i < 5; ++i)
    {
        auto ch = cg.generate();
        characterList* chw = new characterList(ch, this);

        generatedCharacters.push_back(chw);
        characterListLayout->addWidget(chw);
    }
}
