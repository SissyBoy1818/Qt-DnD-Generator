#include "MainGeneratorWidget.h"

MainGeneratorWidget::MainGeneratorWidget(QWidget *parent)
    : QWidget(parent)
{
    // initialize layouts and buttons
    mainLayout = new QHBoxLayout(this);
    workWidget = new QStackedWidget(this);
    generateButton = new QPushButton("Generator");
    showSavedButton = new QPushButton("Saved chars");
    generatedCharList = new QWidget(workWidget);
    characterListLayout = new QVBoxLayout(generatedCharList);

    // create menu and add buttons
    QWidget* menuWidget = new QWidget();
    QVBoxLayout* menuLayout = new QVBoxLayout(menuWidget);
    menuLayout->addWidget(generateButton);
    menuLayout->addWidget(showSavedButton);

    // create scrollarea with characters
    scrollArea = new QScrollArea(workWidget);
    QWidget* scrollContent = new QWidget(scrollArea);
    savedCharsLayout = new QVBoxLayout(scrollContent);
    scrollArea->setWidget(scrollContent);
    scrollContent->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
    savedCharsLayout->addStretch();
    scrollArea->setWidgetResizable(true);

    // add all layouts to main layout
    mainLayout->addWidget(menuWidget, 1);
    mainLayout->addWidget(workWidget,7);
    workWidget->addWidget(generatedCharList);
    workWidget->addWidget(scrollArea);

    workWidget->setCurrentWidget(generatedCharList);
    setLayout(mainLayout);
    resize(800,600);

    // connect slots and signals
    connect(generateButton, &QPushButton::clicked, this, &MainGeneratorWidget::generateNewList);
    connect(showSavedButton, &QPushButton::clicked, this, &MainGeneratorWidget::showSaved);
}

MainGeneratorWidget::~MainGeneratorWidget() {}

void MainGeneratorWidget::showSaved()
{
    workWidget->setCurrentWidget(scrollArea);
}

void MainGeneratorWidget::generateNewList()
{
    qDebug() << "generate";

    workWidget->setCurrentWidget(generatedCharList);

    for (auto ch : generatedCharacters) {
        characterListLayout->removeWidget(ch);
        delete ch;
    }
    generatedCharacters.clear();

    for (int i = 0; i < 5; ++i)
    {
        auto ch = cg.generate();
        CharacterSheet* chw = new CharacterSheet(ch, this);

        generatedCharacters.push_back(chw);
        characterListLayout->addWidget(chw);

        connect(chw->getSaveButton(), &QCheckBox::checkStateChanged, this, [=](){ this->saveCharacter(chw); });
    }
}

void MainGeneratorWidget::saveCharacter(const CharacterSheet* character)
{
    CharacterSheet* savedChar = new CharacterSheet(*character);
    savedSheets.push_back(savedChar);
    savedCharsLayout->addWidget(savedChar);
}

void MainGeneratorWidget::closeEvent(QCloseEvent *event)
{
    qDebug() << "CLOSED";
    event->accept();
}
