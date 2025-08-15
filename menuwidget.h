#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class MenuWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MenuWidget(QWidget *parent = nullptr);

    QPushButton *getGenerateButton() const;

    QPushButton *getShowSavedButton() const;

private:
    QVBoxLayout* menuLayout;

    QPushButton* generateButton;
    QPushButton* showSavedButton;

signals:
};

#endif // MENUWIDGET_H
