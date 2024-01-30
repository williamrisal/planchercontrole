#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QPushButton>
#include <QFileDialog>
#include <sys/signal.h>
#include <QSlider>
#include "ui_mainwindow.h"
#include "QtWidgets/qgridlayout.h"
#include "ui_mainwindow.h"
#include "mapimage.hpp"
#include "sidebarpreference.hpp"
#include "position_aeronef.hpp"
#include <QShortcut>



class MainWindow : public QMainWindow
{
    Q_OBJECT
    Position_Aeronef Position;
public:
    MainWindow(QWidget *parent = nullptr);
 /*   void mousePressEvent(QMouseEvent* event)
    {
        QPoint globalPos = mapFromGlobal(event->globalPos());
        QScreen* screen = QGuiApplication::screenAt(globalPos);

        if (screen) {
            QPixmap screenshot = screen->grabWindow(winId(), globalPos.x(), globalPos.y(), 1, 1);
            QColor color = screenshot.toImage().pixelColor(0, 0);

            int r = color.red();
            int g = color.green();
            int b = color.blue();

            qDebug() << "RGB: " << r << g << b;
            QMessageBox::information(this, "Popup", "Trouvé");
            qDebug() << "test:";
            QPointF test = Position.CartesienneToGeographieDecimal(QPointF(globalPos.x(), globalPos.y())) ;
            qDebug() << "test:";
            qDebug() << test.x();
            qDebug() << test.y();
            }

    }*/


    ~MainWindow();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
