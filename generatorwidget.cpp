#include "generatorwidget.h"

GeneratorWidget::GeneratorWidget(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QPushButton* generateButton = new QPushButton();
    characterListLayout = new QVBoxLayout();

    mainLayout->addWidget(generateButton);
    mainLayout->addLayout(characterListLayout);

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
        auto ch = cg.generate();
        CharacterSheet* chw = new CharacterSheet(ch, this);

        generatedCharacters.push_back(chw);
        characterListLayout->addWidget(chw);

        connect(chw->getSaveButton(), &QPushButton::clicked, this, [=](){ emit saveCharacter(chw); });
    }
}
