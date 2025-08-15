#include "MainGeneratorWidget.h"
#include "CharacterInfo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainGeneratorWidget w;

    w.show();
    return a.exec();
}
