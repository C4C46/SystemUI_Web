#include "SystemUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SystemUI w;
    w.show();
    return a.exec();
}
