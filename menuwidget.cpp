#include "menuwidget.h"

MenuWidget::MenuWidget(QWidget *parent)
    : QWidget{parent}
{
    generateButton = new QPushButton("Generator");
    showSavedButton = new QPushButton("Saved chars");
    menuLayout = new QVBoxLayout(this);
    QSpacerItem* verticalSpacer1 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Expanding);
    QSpacerItem* verticalSpacer2 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Expanding);

    menuLayout->addSpacerItem(verticalSpacer1);
    menuLayout->addWidget(generateButton);
    menuLayout->addWidget(showSavedButton);
    menuLayout->addSpacerItem(verticalSpacer2);
    menuLayout->setSpacing(15);
}

QPushButton *MenuWidget::getGenerateButton() const
{
    return generateButton;
}

QPushButton *MenuWidget::getShowSavedButton() const
{
    return showSavedButton;
}
