#include "mapimage.hpp"
#include "QtWidgets/qgraphicsitem.h"
#include "showimage.hpp"
#include <QJsonObject>
#include <QJsonDocument>



MapImage::MapImage(QWidget *parent) : QGraphicsView(parent) {
    setFocus();
    setDragMode(QGraphicsView::ScrollHandDrag);
    setInteractive(true);

    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(QColor("#52555a"));

    setScene(scene);
    viewRect = viewport()->rect();

    setPathPoylgone();
    m_Custommap.AddCitiesFromGeoJSON(&Position, scene);
    m_Custommap.DrawAerodrome(&Position, scene);
  //  setPoint(0);// 0 pour les radar
    setPoint(1);// 1 pour les point strategique
    setPointculminant();
    m_Custommap.showAirport(&Position, scene);
    traitementDossierPeriemetre();
    show();
}

void MapImage::showOnlyRadar(QString Radar, bool Activate) {

    QJsonObject RadarVille = loadFile.loadRadar();
    QJsonObject radarInfo = RadarVille[Radar].toObject();
    QString radarPath;
    QVector3D rectification = math.ConvertStringtoQVector3D(radarInfo["Rectification"].toString());

    if (Activate) {
        if (!checkedRadars.contains(Radar)) {
            checkedRadars.insert(Radar, {0, 0});

            QString positionPath = loadFile.GotoRacineFile() + QDir::separator() + "capture"+ QDir::separator() + radarInfo["Image_Path"].toString();

            radarPath = positionPath + QString::number(altitude) + ".png";
            qDebug() << radarPath;

            if (QFile::exists(radarPath)) {

                QPixmap radarImage(radarPath);
                int nouvelleLargeur = radarImage.width() + rectification.z();
                int nouvelleHauteur = radarImage.height() + rectification.z();

                QPixmap imageRedimensionnee = radarImage.scaled(nouvelleLargeur, nouvelleHauteur);

                QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(imageRedimensionnee);
                QPointF positionCartesienne = Position.GeoToCartosienne(radarInfo["Position"].toString());
                pixmapItem->setPos(positionCartesienne + QPointF(rectification.x(), rectification.y()));
                pixmapItem->setOpacity(0.6); // Mettez l'opacité souhaitée ici


                scene->addItem(pixmapItem);
                radarItems.insert(Radar, pixmapItem);
            }
        }
    } else {
        checkedRadars.remove(Radar);
        auto it = radarItems.find(Radar);
        if (it != radarItems.end()) {
            scene->removeItem(*it);
            radarItems.erase(it);
        }
    }
}



void MapImage::UpdateRadar(QVector3D positionRadar) {
    QJsonObject RadarVille = loadFile.loadRadar();

    QString radarPath;
    QJsonObject radarInfo;
    QVector3D rectification;
    QString positionPath = loadFile.GotoRacineFile() + QDir::separator() + "capture"+ QDir::separator() + radarInfo["Image_Path"].toString();

    for (auto it = radarItems.begin(); it != radarItems.end(); ++it) {
        radarInfo = RadarVille[it.key()].toObject();
        rectification = math.ConvertStringtoQVector3D(radarInfo["Rectification"].toString()) + positionRadar;


        radarPath = positionPath + radarInfo["Image_Path"].toString() + QString::number(altitude) + ".png";
        loadFile.modifyJsonFile(loadFile.GotoRacineFile() + QDir::separator() + "src"+ QDir::separator() + "RadarPosition.json",it.key(),rectification);

        QPixmap radarImage(radarPath);
        int nouvelleLargeur = radarImage.width() + rectification.z();
        int nouvelleHauteur = radarImage.height() + rectification.z();

        QPixmap imageRedimensionnee = radarImage.scaled(nouvelleLargeur, nouvelleHauteur);

        QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(imageRedimensionnee);

        QPointF positionCartesienne = Position.GeoToCartosienne(radarInfo["Position"].toString());
        pixmapItem->setPos(positionCartesienne + QPointF(rectification.x(), rectification.y()));
        pixmapItem->setOpacity(0.6);

        if (scene->items().contains(it.value())) {
            scene->removeItem(it.value());
        }
        qDebug() << "test";

        scene->addItem(pixmapItem);
        radarItems.insert(it.key(), pixmapItem);
    }
}

void MapImage::UpdateRadio(QVector3D positionRadio) {

    QJsonObject RadioVille = loadFile.loadRadio();
    QString RadioPath;
    QJsonObject RadioInfo;
    QVector3D rectification;

    QString positionPath = loadFile.GotoRacineFile() + QDir::separator() + "Radio"+ QDir::separator() + RadioInfo["Image_Path"].toString();
    for (auto it = radioItems.begin(); it != radioItems.end(); ++it) {
        RadioInfo = RadioVille[it.key()].toObject();
        rectification = math.ConvertStringtoQVector3D(RadioInfo["Rectification"].toString()) + positionRadio;

        RadioPath = positionPath + RadioInfo["Image_Path"].toString();
        loadFile.modifyJsonFile(loadFile.GotoRacineFile() + QDir::separator() + "Radio"+ QDir::separator() + "RadioPosition.json",it.key(),rectification);
        qDebug() << RadioPath;

        QPixmap RadioImage(RadioPath);
        int nouvelleLargeur = RadioImage.width() + rectification.z();
        int nouvelleHauteur = RadioImage.height() + rectification.z();

        QPixmap imageRedimensionnee = RadioImage.scaled(nouvelleLargeur, nouvelleHauteur);

        QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(imageRedimensionnee);

        QPointF positionCartesienne = Position.GeoToCartosienne(RadioInfo["Position"].toString());
        pixmapItem->setPos(positionCartesienne + QPointF(rectification.x(), rectification.y()));
        pixmapItem->setOpacity(0.6);


        if (scene->items().contains(it.value())) {
            scene->removeItem(it.value());
        }
        qDebug() << "test";

        scene->addItem(pixmapItem);
        radioItems.insert(it.key(), pixmapItem);
    }
}

void MapImage::setPathPoylgone(){
    QJsonObject jsonObj = loadFile.LoadJson(loadFile.GotoRacineFile() + QDir::separator() + "Region" + QDir::separator() + "PathRegion.json");
    QStringList ville = jsonObj.keys();

    for (const QString &ville : ville) {
        QJsonObject villeObj = jsonObj[ville].toObject();
        QString path = villeObj["path"].toString();
        m_Custommap.drawMultiPolygon(*scene, &Position, loadFile.GotoRacineFile() + QDir::separator() + "Region" + QDir::separator() + path);
        qDebug() << path;

    }
    qDebug() << loadFile.GotoRacineFile() + QDir::separator() + "Region" + QDir::separator() + "regions.geojson";
    m_Custommap.drawPolygon(*scene, &Position, loadFile.GotoRacineFile() + QDir::separator() + "Region" + QDir::separator() + "regions.geojson");

}

void MapImage::ShowElementCulminante(bool Activate){
    if (this->pcActivate != Activate || !this->pcActivate){
        this->pcActivate = Activate;

        if (Activate == false){
            for (int i = 0; i < CulminanteList.size(); ++i) {
                scene->removeItem(CulminanteList.at(i));
            }
        }
        else {
            setPointculminant();
        }
    }
}

void MapImage::ShowElementStrategique(bool Activate){
    if (this->StrategiqueActivate != Activate || !this->StrategiqueActivate){
        this->StrategiqueActivate = Activate;

        if (Activate == false){
            for (int i = 0; i < StrategiqueList.size(); ++i) {
                scene->removeItem(StrategiqueList.at(i));

            }
        }
        else {
            setPoint(1);
        }
    }
}

void MapImage::setPoint(int Choose) {
    QColor color;
    QJsonObject Point;
    if (Choose == 0){
       Point = loadFile.loadRadar();
        color = Qt::blue;

    }
    else {
        Point = loadFile.loadPointStrategique();
        color = Qt::yellow;
    }
    QStringList villes = Point.keys();

    for (const QString& ville : villes) {
        QJsonObject villeObj = Point[ville].toObject();
        QString position = villeObj["Position"].toString();
        double lat = math.convertDMSToDecimal(position.section(' ', 0, 0)); // Latitude
        double lon = math.convertDMSToDecimal(position.section(' ', 1, 1)); // Longitude

        QPointF positionRadar = Position.GeoDecimalToCartosienne(lat, lon);
        auto test = scene->addEllipse(QRectF(positionRadar.x() - 2, positionRadar.y() - 2, 4, 4), QPen(Qt::NoPen), QBrush(color)); // Utilisation de Qt::red pour spécifier la couleur de la brosse.
        StrategiqueList.push_back(test);

    }
}

void MapImage::setPointculminant(){
    QJsonObject jsonObj = loadFile.LoadJson(loadFile.GotoRacineFile() + QDir::separator() + "src" + QDir::separator()+ "PositionPointCulminant.json");
    QStringList ville = jsonObj.keys();

    for (const QString& ville : ville) {
        QJsonObject villeObj = jsonObj[ville].toObject();
        QString position = villeObj["Position"].toString();
        m_Custommap.culuminant_Point(*scene,Position.GeoToCartosienne(position), this->altitude, &CulminanteList);
    }
}
void MapImage::traitementDossierPeriemetre()
{
    QString pathByPerimetre;
    QGraphicsPolygonItem *tmpPerimetre;
    QDir directory(loadFile.GotoRacineFile() + QDir::separator() +"Perimetre");

    qDebug() << directory.path();
    if (!directory.exists()) {
        qDebug() << "Le dossier spécifié n'existe pas.";
        return;
    }

    QStringList filters;
    filters << "*.geojson";

    directory.setNameFilters(filters);

    QStringList files = directory.entryList(QDir::Files);

    foreach (const QString &file, files) {
        pathByPerimetre = directory.filePath(file);
        qDebug() << pathByPerimetre;
        tmpPerimetre = m_Custommap.drawPolygon(*scene, &Position, pathByPerimetre, territoire);
        PolygoneList.append(tmpPerimetre);
    }
}

void MapImage::ShowElementPeriemetre(bool Activate, int a){
    if (this->pcActivate != Activate || !this->pcActivate){
        this->pcActivate = Activate;

        if (Activate == false){
            scene->removeItem(PolygoneList.at(a));
        }
        else {
            scene->addItem(PolygoneList.at(a));
        }
    }
}


void MapImage::SowElementRadio(QString Radio, bool Activate){

    QJsonObject RadioVille = loadFile.loadRadio();
    QJsonObject RadioInfo = RadioVille[Radio].toObject();
    QString RadioPath;
    QVector3D rectification = math.ConvertStringtoQVector3D(RadioInfo["Rectification"].toString());

    if (Activate) {
        if (!checkedRadios.contains(Radio)) {
            checkedRadios.insert(Radio, {0, 0});

            QString RadioPath = loadFile.GotoRacineFile() + QDir::separator() + "Radio"+ QDir::separator() + RadioInfo["Image_Path"].toString();

            qDebug() << RadioPath;

            if (QFile::exists(RadioPath)) {

                QPixmap RadioImage(RadioPath);
                int nouvelleLargeur = RadioImage.width() + rectification.z();
                int nouvelleHauteur = RadioImage.height() + rectification.z();

                QPixmap imageRedimensionnee = RadioImage.scaled(nouvelleLargeur, nouvelleHauteur);

                QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(imageRedimensionnee);
                QPointF positionCartesienne = Position.GeoToCartosienne(RadioInfo["Position"].toString());
                pixmapItem->setPos(positionCartesienne + QPointF(rectification.x(), rectification.y()));
                pixmapItem->setOpacity(0.6); // Mettez l'opacité souhaitée ici


                scene->addItem(pixmapItem);
                radioItems.insert(Radio, pixmapItem);
            }
        }
    } else {
        checkedRadios.remove(Radio);
        auto it = radioItems.find(Radio);
        if (it != radioItems.end()) {
            scene->removeItem(*it);
            radioItems.erase(it);
        }
    }
}
void MapImage::zoomIn() {
    scale(1.2, 1.2);
}

void MapImage::zoomOut() {
    scale(0.8, 0.8);
}
