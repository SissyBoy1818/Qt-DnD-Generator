#include "menuwidget.h"

MenuWidget::MenuWidget(QWidget *parent)
    : QWidget{parent}
{
    generateButton = new QPushButton("Generator");
    showSavedButton = new QPushButton("Saved\nchars");
    menuLayout = new QVBoxLayout(this);
    QSpacerItem* verticalSpacer1 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Expanding);
    QSpacerItem* verticalSpacer2 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Expanding);

    menuLayout->addSpacerItem(verticalSpacer1);
    menuLayout->addWidget(generateButton);
    menuLayout->addWidget(showSavedButton);
    menuLayout->addSpacerItem(verticalSpacer2);
    menuLayout->setSpacing(15);

    setAttribute(Qt::WA_StyledBackground, true);
    setObjectName("menuWidget");
    setStyleSheet(
        "#menuWidget {"
        "   background-color: #273345;"
        "   border-radius: 15px;"
        "   border: 2px solid black"
        "}"
        );

    generateButton->setFixedSize(100, 100);
    showSavedButton->setFixedSize(100, 100);
    generateButton->setAttribute(Qt::WA_StyledBackground, true);
    showSavedButton->setAttribute(Qt::WA_StyledBackground, true);
    setStyleSheet(
        "QPushButton {\
            background-color: #1e2a38;\
            color: white;\
            border: none;\
            border-radius: 15px;\
            width: 100px;\
            height: 120px;\
            font-size: 16px;\
            padding: 10px;\
        }\
        QPushButton:hover {\
            background-color: #273b55;\
        }\
        QPushButton:pressed {\
            background-color: #141f2c;\
        }\
        QPushButton:disabled {\
            background-color: #3b4b5b;\
            color: #aaaaaa;\
        }"
        );
}

QPushButton *MenuWidget::getGenerateButton() const
{
    return generateButton;
}

QPushButton *MenuWidget::getShowSavedButton() const
{
    return showSavedButton;
}
