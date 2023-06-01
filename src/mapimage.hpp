#ifndef MAPIMAGE_HPP
#define MAPIMAGE_HPP
#include "QtCore/qobject.h"
#include "QtWidgets/qwidget.h"
#include "showimage.hpp"
#include <QPixmap>


class MapImage : public QWidget
{
    Q_OBJECT
public:
    MapImage(QWidget *parent = nullptr);
    void Images();
    int Altitude = 582;
    void ImagePosition(ShowImage *image, const QPoint& position, QString Url);
    void resizeEvent(QResizeEvent *event);


public slots:
    void setAltitude(int ALtitude){
      if (ALtitude != this->Altitude){
            this->Altitude = ALtitude;
            std::cout << "raffriachissementé" << std::endl;
            Images();
      }

    }


private:
    CheckPixel *m_checkPixel;
    ShowImage *m_showImage_Istre = new ShowImage(this);
    ShowImage *m_showImage_Salon = new ShowImage(this);
    ShowImage *m_showImage_Ventoux = new ShowImage(this);
    ShowImage *m_showImage_Montpellier = new ShowImage(this);
    ShowImage *m_showImage_Vitrolles = new ShowImage(this);
    ShowImage *m_showImage_Narbonne = new ShowImage(this);
    ShowImage *m_showImage_Sainte_baume = new ShowImage(this);

};

#endif // MAPIMAGE_HPP
