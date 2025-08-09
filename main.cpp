#include "character_generator.h"
#include "charactergenerator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    character_generator w;
    characterGenerator cg;

    auto asd = cg.generate();
    qDebug() << asd.name() << asd.age() << asd.race() << asd.occupation();

    w.show();
    return a.exec();
}
