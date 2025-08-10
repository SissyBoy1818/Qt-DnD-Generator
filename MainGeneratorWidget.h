#ifndef MAINGENERATORWIDGET_H
#define MAINGENERATORWIDGET_H

#include "CharacterSheet.h"
#include "charactergenerator.h"

#include <vector>
#include <QWidget>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QColumnView>
#include <QScrollArea>
#include <QTabWidget>

class MainGeneratorWidget : public QWidget
{
    Q_OBJECT

public:
    MainGeneratorWidget(QWidget *parent = nullptr);
    ~MainGeneratorWidget();

private:
    void saveCharacter(const CharacterSheet* character);

    characterGenerator cg;
    std::vector<CharacterSheet*> savedSheets;
    std::vector<CharacterSheet*> generatedCharacters;

    QHBoxLayout* mainLayout;
    QStackedWidget* workWidget;
    QVBoxLayout* characterListLayout;

    QPushButton* generateButton;
    QPushButton* showSavedButton;

    QWidget* generatedCharList;
    QScrollArea* scrollArea;
    QVBoxLayout* savedCharsLayout;

public slots:
    void showSaved();
    void generateNewList();

signals:

};
#endif // MAINGENERATORWIDGET_H
