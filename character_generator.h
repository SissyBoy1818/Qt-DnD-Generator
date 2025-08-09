#ifndef CHARACTER_GENERATOR_H
#define CHARACTER_GENERATOR_H

#include <QWidget>
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
    QHBoxLayout* mainLayout;

    QPushButton* generateButton;
    QPushButton* showSavedButton;

public slots:
    void generateNewList();

signals:

};
#endif // CHARACTER_GENERATOR_H
