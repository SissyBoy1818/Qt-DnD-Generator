#ifndef CHARACTER_GENERATOR_H
#define CHARACTER_GENERATOR_H

#include "characterlist.h"
#include "charactergenerator.h"

#include <QWidget>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QColumnView>
#include <QScrollArea>

class character_generator : public QWidget
{
    Q_OBJECT

public:
    character_generator(QWidget *parent = nullptr);
    ~character_generator();

private:
    characterGenerator cg;

    QHBoxLayout* mainLayout;
    QStackedWidget* workWidget;
    QVBoxLayout* characterListLayout;

    QPushButton* generateButton;
    QPushButton* showSavedButton;

public slots:
    void generateNewList();

signals:

};
#endif // CHARACTER_GENERATOR_H
