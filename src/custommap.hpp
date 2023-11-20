#ifndef CUSTOMAP_HPP
#define CUSTOMAP_HPP

#include "src/monitoringfile.hpp"
#include "src/position_aeronef.hpp"
#include <QObject>
#include <QGraphicsScene>

class Custommap : public QObject
{
    Q_OBJECT

public:
    Custommap();
    void drawMultiPolygon(QGraphicsScene& scene, Position_Aeronef *Position, const QString& geojsonFilePath);
    //void drawPolygone(QGraphicsScene& scene, double echelle, Position* position, const QVector<QPointF>& polygone);
    void culuminant_Point(QGraphicsScene& scene, QPointF position, int altitude, QList<QGraphicsItem *> *ellipseList);
    QGraphicsPolygonItem *drawPolygon(QGraphicsScene& scene, Position_Aeronef* position, const QString& geojsonFilePath, bool type = true);
    void AddCitiesFromGeoJSON(Position_Aeronef* position, QGraphicsScene* scene);
    void DrawAerodrome(Position_Aeronef* position, QGraphicsScene* scene);
    void showAirport(Position_Aeronef* position,QGraphicsScene *scene);

    QGraphicsEllipseItem* circle;
    QGraphicsEllipseItem* point;
    MonitoringFile loadFile;

};

#endif // CUSTOMAP_HPP
