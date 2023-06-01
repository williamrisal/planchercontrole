#include "mainwindow.h"

#include <QApplication>
#include "position_aeronef.hpp"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(1280, 720);
    Position_Aeronef aeronef;
    w.show();
    return a.exec();
}
