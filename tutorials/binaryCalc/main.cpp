#include <QtGui/QApplication>
#include "binaryCalc.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    binaryCalc w;
    w.show();

    return a.exec();
}
