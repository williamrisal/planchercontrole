#ifndef CHECKPIXEL_H
#define CHECKPIXEL_H
#include "QtWidgets/qmainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QMouseEvent>
#include <iostream>
#include <qmessagebox.h>


class CheckPixel : public QLabel
{
public:
    CheckPixel(QWidget* parent = nullptr) : QLabel(parent) {}

public slots:
    void mousePressEvent(QMouseEvent* event)
    {
        std::cout << "test" << std::endl;

        // Capture d'écran de toute l'application
        QScreen* screen = QGuiApplication::primaryScreen();
        QPixmap screenshot = screen->grabWindow(0);

        // Récupération de la couleur du pixel à la position du clic
        QColor color = screenshot.toImage().pixelColor(event->globalPos());

        int b = color.blue();
        int r = color.red();
        int g = color.green();
        qDebug() << color.blue() << color.red() << color.green();

        if ((b != 90 && (r != 82)) || g != 85) {
            QMessageBox::information(this, "Popup", "Trouvé");
        }
    }
};

#endif // CHECKPIXEL_H
