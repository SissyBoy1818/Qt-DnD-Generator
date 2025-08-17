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
    savedCharsLayout->setContentsMargins(5, 20, 15, 20);

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
    scrollContent->setObjectName("scrollContent");

    setObjectName("mainWidget");
    setStyleSheet(
        "#mainWidget {\
           background-color: #273345;\
        }\
        #scrollContent {\
            background-color: #273345;\
            border: 1px solid #1e2a38;\
            border-radius: 8px;\
        }\
        #scrollContent:vertical {\
            background-color: #273747;\
            width: 12px;\
            margin: 15px 0 15px 0;\
            border-radius: 6px;\
        }\
        #scrollContent::handle:vertical {\
            background-color: #3a4b6a;\
            min-height: 20px;\
            border-radius: 6px;\
        }"
        );
    scrollArea->setStyleSheet("QScrollArea {background-color: #273345; border: none;}");

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
