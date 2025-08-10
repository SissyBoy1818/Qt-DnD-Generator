#ifndef MAINGENERATORWIDGET_H
#define MAINGENERATORWIDGET_H

#include "characterlist.h"
#include "charactergenerator.h"

#include <vector>
#include <QWidget>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QColumnView>
#include <QScrollArea>

class MainGeneratorWidget : public QWidget
{
    Q_OBJECT

public:
    MainGeneratorWidget(QWidget *parent = nullptr);
    ~MainGeneratorWidget();

private:
    characterGenerator cg;
    std::vector<QWidget*> generatedCharacters;

    QHBoxLayout* mainLayout;
    QStackedWidget* workWidget;
    QVBoxLayout* characterListLayout;

    QPushButton* generateButton;
    QPushButton* showSavedButton;

public slots:
    void generateNewList();

signals:

};
#endif // MAINGENERATORWIDGET_H
