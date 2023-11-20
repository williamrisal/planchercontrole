#ifndef MAPIMAGE_H
#define MAPIMAGE_H

#include "QtGui/qevent.h"
#include "QtWidgets/qgraphicsitem.h"
#include "src/Custommap.hpp"
#include "src/ShowImage.hpp"
#include "src/mathAero.hpp"
#include "src/position_aeronef.hpp"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QPointF>
#include <QMap>
#include "monitoringfile.hpp"

#define DI(altitude) ("/Users/williamrisal/Documents/DGA projet/planchercontrole-main/capture/Radar Aladin Istres DI/capture_DI_" + std::to_string(altitude) + " ft.png")
#define DS(altitude) "/Users/williamrisal/Documents/DGA projet/planchercontrole-main/capture/Radar Centaure Salon DS/capture_DS_" + std::to_string(altitude) + "ft.png"
#define JX(altitude) "/Users/williamrisal/Documents/DGA projet/planchercontrole-main/capture/capture_JX_" + std::to_string(altitude) + "ft.png"
#define JO(altitude) "/Users/williamrisal/Documents/DGA projet/planchercontrole-main/capture/Radar RMI Montpellier JO/capture_JO_" + std::to_string(altitude) + "ft.png"
#define GV(altitude) "/Users/williamrisal/Documents/DGA projet/planchercontrole-main/capture/Radar TRAC2000 Vitrolles GV/capture_GV_" + std::to_string(altitude) + "ft.png"
#define RO(altitude) "/Users/williamrisal/Documents/DGA projet/planchercontrole-main/capture/Radar TRAC2400 Narbonne/capture_RO_" + std::to_string(altitude) + "ft.png"
#define RS(altitude) "/Users/williamrisal/Documents/DGA projet/planchercontrole-main/capture/Radar TRAC2400 Sainte Baume RS/capture_RS_" + std::to_string(altitude) + "ft.png"
#define territoire false


class MapImage : public QGraphicsView {
    Q_OBJECT

public:
    MapImage(QWidget *parent = nullptr);
    void UpdateRadar(QVector3D position = {0,0,0});
    Position_Aeronef Position;
    QRectF viewRect;
    Custommap mapCustom;
    void zoomIn();
    void zoomOut();
    void setPointculminant();
    void setPathPoylgone();
    int altitude = 582;
    bool pcActivate = true;
    bool StrategiqueActivate = true;
    QPointF positionRadar;
    void setPoint(int Choose);
    void traitementDossierPeriemetre();
    QList<QGraphicsItem*> PolygoneList;
    void ShowElementPeriemetre(bool Activate, int a);



public slots:
    void showOnlyRadar(QString Radar, bool Activate);
    void ShowElementCulminante(bool Activate);
    void ShowElementStrategique(bool Activate);

    void keyPressEvent(QKeyEvent *event) {
        if (event->key() == Qt::Key_Plus) {
            zoomIn();
        } else if (event->key() == Qt::Key_Minus) {
            zoomOut();
        } else {
            QGraphicsView::keyPressEvent(event);
        }
    }
    void setaltitude(int value){
        if (this->altitude != value){
            this->altitude = value;
            this->UpdateRadar();
            if (pcActivate){
                for (int i = 0; i < CulminanteList.size(); ++i) {
                    if (CulminanteList.at(i)){
                        scene->removeItem(CulminanteList.at(i));
                    }
                }
                setPointculminant();
            }
        }
    }
    void moveImage(int i ){
        QVector3D position;
        if(i == 0){
            position.setX(-5);
            position.setY(0);
            this->UpdateRadar(position);
        }
        if(i == 1){
            position.setX(5);
            position.setY(0);
            this->UpdateRadar(position);
        }
        if(i == 2){
            position.setX(0);
            position.setY(-5);
            this->UpdateRadar(position);
        }
        if(i == 3){
            position.setX(0);
            position.setY(5);
            this->UpdateRadar(position);
        }
        if(i == 4){
            position.setX(0);
            position.setY(0);
            position.setZ(5);
            this->UpdateRadar(position);
        }
        if(i == 5){
            position.setX(0);
            position.setY(0);
            position.setZ(-5);
            this->UpdateRadar(position);
        }
    }


private:
    QGraphicsScene* scene;
    QMap<QString, QPointF> checkedRadars;
    QMap<QString, QGraphicsItem*> radarItems;
    Custommap m_Custommap;
    QList<QGraphicsItem*> CulminanteList;
    QList<QGraphicsItem*> StrategiqueList;
    MonitoringFile loadFile;
    mathAero math;
};

#endif // MAPIMAGE_H
