#ifndef MAINGENERATORWIDGET_H
#define MAINGENERATORWIDGET_H

#include "generatorwidget.h"
#include "menuwidget.h"

#include <vector>
#include <QWidget>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QColumnView>
#include <QScrollArea>
#include <QTabWidget>
#include <QCloseEvent>
#include <QSpacerItem>

class MainGeneratorWidget : public QWidget
{
    Q_OBJECT

public:
    MainGeneratorWidget(QWidget *parent = nullptr);
    ~MainGeneratorWidget();

private:
    std::vector<CharacterSheet*> savedSheets;
    GeneratorWidget* generator;

    QHBoxLayout* mainLayout;
    QStackedWidget* workWidget;
    QVBoxLayout* characterListLayout;

    QWidget* generatedCharList;
    QScrollArea* scrollArea;
    QVBoxLayout* savedCharsLayout;

protected:
    void closeEvent(QCloseEvent *event) override;

public slots:
    void showSaved();
    void showGenerator();
    void saveCharacter(const CharacterSheet* character);

signals:

};
#endif // MAINGENERATORWIDGET_H
