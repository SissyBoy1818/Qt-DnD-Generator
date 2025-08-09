#ifndef CHARACTERLIST_H
#define CHARACTERLIST_H

#include "character.h"

#include <QWidget>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QLabel>
#include <QPixmap>

class characterList : public QWidget
{
    Q_OBJECT
public:
    explicit characterList(const Character& character, QWidget *parent = nullptr);

private:


signals:
    void save();
};

#endif // CHARACTERLIST_H
