#include "generatorwidget.h"

GeneratorWidget::GeneratorWidget(QWidget *parent)
    : QWidget{parent}, _settings("random"), cg()
{
    generatorSettings = new QWidget(this);
    QVBoxLayout* settingsLayout = new QVBoxLayout(generatorSettings);
    QComboBox* raceComboBox = new QComboBox;

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QPushButton* generateButton = new QPushButton("Generate new chars");
    characterListLayout = new QVBoxLayout();

    raceComboBox->addItem("random");
    for (const auto& r : cg.ci.races().keys())
        raceComboBox->addItem(r);

    settingsLayout->addWidget(raceComboBox);
    settingsLayout->addWidget(generateButton);
    mainLayout->addWidget(generatorSettings);
    mainLayout->addLayout(characterListLayout);

    generateNewList();

    connect(raceComboBox, &QComboBox::currentTextChanged, this, &GeneratorWidget::settingsChanged);
    connect(generateButton, &QPushButton::clicked, this, &GeneratorWidget::generateNewList);
}

void GeneratorWidget::generateNewList()
{
    for (auto ch : generatedCharacters) {
        characterListLayout->removeWidget(ch);
        delete ch;
    }
    generatedCharacters.clear();

    for (int i = 0; i < 5; ++i)
    {
        auto ch = cg.generate(_settings);
        CharacterSheet* chw = new CharacterSheet(ch, this);

        generatedCharacters.push_back(chw);
        characterListLayout->addWidget(chw);

        connect(chw->getSaveButton(), &QPushButton::clicked, this, [=](){ emit saveCharacter(chw); });
    }
}

void GeneratorWidget::settingsChanged(const QString &newSettings)
{
    _settings = newSettings;
}
