#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PaintedWidget pw;
    pw.show();

    return a.exec();
}
