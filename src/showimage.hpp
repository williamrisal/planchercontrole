#ifndef SHOWIMAGE_HPP
#define SHOWIMAGE_HPP

#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include "src/CheckPixel.hpp"
#include <QMainWindow>
#include <QPixmap>
#include <QPushButton>
#include "CheckPixel.hpp"
#include <QFileDialog>
#include <sys/signal.h>
#include <QSlider>
#define CAPTURE_ISTRE(Altitude) ("/Users/williamrisal/Documents/DGA projet/PlancherControle/capture/Radar Aladin Istres DI/capture_DI_" + QString::number(Altitude) + " ft.png")
#define CAPTURE_SAINT_BAUME(Altitude) ("/Users/williamrisal/Documents/DGA projet/PlancherControle/capture/Radar TRAC2400 Sainte Baume RS/capture_RS_" + QString::number(Altitude) + "ft.png")
#define CAPTURE_VITROLLE(Altitude) ("/Users/williamrisal/Documents/DGA projet/PlancherControle/capture/Radar TRAC2000 Vitrolles GV/capture_GV_" + QString::number(Altitude) + "ft.png")
#define CAPTURE_MONTPELLIER(Altitude) ("/Users/williamrisal/Documents/DGA projet/PlancherControle/capture/Radar RMI Montpellier JO/capture_JO_" + QString::number(Altitude) + "ft.png")
#define CAPTURE_VENTOUX(Altitude) ("/Users/williamrisal/Documents/DGA projet/PlancherControle/capture/Radar RMI Mont Ventoux JX/capture_JX_" + QString::number(Altitude) + "ft.png")
#define CAPTURE_SALON(Altitude) ("/Users/williamrisal/Documents/DGA projet/PlancherControle/capture/Radar Centaure Salon DS/capture_DS_" + QString::number(Altitude) + "ft.png")
#define CAPTURE_NARBONNE(Altitude) ("/Users/williamrisal/Documents/DGA projet/PlancherControle/capture/Radar TRAC2400 Narbonne/capture_RO_" + QString::number(Altitude) + "ft.png")

class ShowImage : public QWidget
{
    Q_OBJECT
public:
    ShowImage(QWidget *parent) : QWidget(parent) {
        m_imageLabel = new QLabel(this);
    }

    QPixmap getImage(QString url){
        if (imageCache.contains(url)) {
            m_imageLabel->setPixmap(imageCache.value(url));
            return imageCache.value(url);
        }

        return SetImage(url);
    }

    QPixmap SetImage(QString url){
        QPixmap pixmap(url);
        QPixmap resizedPixmap = pixmap.scaled(QSize(400, 400), Qt::KeepAspectRatio);

        m_imageLabel->setFixedSize(resizedPixmap.size());
        m_imageLabel->setAlignment(Qt::AlignCenter);
        m_imageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        m_imageLabel->setScaledContents(true);
        m_imageLabel->setPixmap(resizedPixmap);

        imageCache.insert(url, resizedPixmap);

        return resizedPixmap;
    }

private:
    QLabel *m_imageLabel;
    QMap<QString, QPixmap> imageCache;

};

#endif // SHOWIMAGE_HPP
