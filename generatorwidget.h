#ifndef GENERATORWIDGET_H
#define GENERATORWIDGET_H

#include "CharacterSheet.h"
#include "charactergenerator.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QPushButton>
#include <QComboBox>
#include <QSizePolicy>

class GeneratorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GeneratorWidget(QWidget *parent = nullptr);

private:
    QString _settings;
    characterGenerator cg;
    std::vector<CharacterSheet*> generatedCharacters;

    QWidget* generatorSettings;
    QPushButton* applySettingsButton;
    QPushButton* generateNewButton;

    QScrollArea* scrollArea;
    QWidget* scrollContent;
    QVBoxLayout* characterListLayout;

private slots:
    void generateNewList();
    void settingsChanged(const QString& newSettings);

signals:
    void saveCharacter(CharacterSheet*);
};

#endif // GENERATORWIDGET_H
