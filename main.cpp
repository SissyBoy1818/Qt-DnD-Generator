#include "character_generator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    character_generator w;

    w.show();
    return a.exec();
}
