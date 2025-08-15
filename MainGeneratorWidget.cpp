#include "MainGeneratorWidget.h"

MainGeneratorWidget::MainGeneratorWidget(QWidget *parent)
    : QWidget(parent)
{
    // initialize layouts and buttons
    mainLayout = new QHBoxLayout(this);
    workWidget = new QStackedWidget(this);

    // create menu and add buttons
    MenuWidget* menu = new MenuWidget(this);
    generator = new GeneratorWidget(workWidget);

    // create scrollarea with characters
    scrollArea = new QScrollArea(workWidget);
    QWidget* scrollContent = new QWidget(scrollArea);
    savedCharsLayout = new QVBoxLayout(scrollContent);
    scrollArea->setWidget(scrollContent);
    scrollContent->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
    savedCharsLayout->addStretch();
    scrollArea->setWidgetResizable(true);

    // add all layouts to main layout
    mainLayout->addWidget(menu, 1);
    mainLayout->addWidget(workWidget,7);
    workWidget->addWidget(generator);
    workWidget->addWidget(scrollArea);

    workWidget->setCurrentWidget(generator);
    setLayout(mainLayout);
    resize(800,600);

    // connect slots and signals
    connect(menu->getGenerateButton(), &QPushButton::clicked, this, &MainGeneratorWidget::showGenerator);
    connect(menu->getShowSavedButton(), &QPushButton::clicked, this, &MainGeneratorWidget::showSaved);
    connect(generator, &GeneratorWidget::saveCharacter, this, &MainGeneratorWidget::saveCharacter);

    // qss to make it look better
    setObjectName("mainWidget");
    setStyleSheet(
        "#mainWidget {"
        "   background-color: #273345;"
        "}"
        );

    showGenerator();
}

MainGeneratorWidget::~MainGeneratorWidget() {}

void MainGeneratorWidget::showSaved()
{
    workWidget->setCurrentWidget(scrollArea);
}

void MainGeneratorWidget::showGenerator()
{
    workWidget->setCurrentWidget(generator);
}

void MainGeneratorWidget::saveCharacter(const CharacterSheet* character)
{
    CharacterSheet* savedChar = new CharacterSheet(*character);
    savedSheets.push_back(savedChar);
    savedCharsLayout->addWidget(savedChar);
}

void MainGeneratorWidget::closeEvent(QCloseEvent *event)
{
    // TODO: save characters in file

    qDebug() << "CLOSED";
    event->accept();
}
