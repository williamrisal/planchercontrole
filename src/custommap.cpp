#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QPointF>
#include <QGraphicsScene>
#include <QGraphicsPolygonItem>
#include <QDebug>
#include "custommap.hpp"
#include "src/mapimage.hpp"
QColor grayColor(128, 128, 128, 128); // Gris avec une transparence de 128 (0-255)

Custommap::Custommap() {}

void Custommap::drawMultiPolygon(QGraphicsScene& scene, Position_Aeronef* position, const QString& geojsonFilePath) {
    // Ouvrir le fichier GeoJSON en lecture
    QFile geojsonFile(geojsonFilePath);
    if (!geojsonFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Erreur lors de l'ouverture du fichier GeoJSON";
        return;
    }

    // Lire tout le contenu du fichier GeoJSON
    QByteArray geojsonData = geojsonFile.readAll();
    geojsonFile.close();

    // Analyser le GeoJSON en un document JSON
    QJsonDocument jsonDoc = QJsonDocument::fromJson(geojsonData);

    // Vérifier si l'analyse a réussi
    if (!jsonDoc.isObject()) {
        qDebug() << "Erreur lors de l'analyse du GeoJSON";
        return;
    }

    // Obtenir l'objet JSON racine
    QJsonObject jsonObj = jsonDoc.object();

    if (jsonObj.contains("type") && jsonObj["type"].toString() == "Feature") {
        // Obtenir l'objet "geometry"
        QJsonObject geometryObj = jsonObj["geometry"].toObject();

            QJsonArray coordinatesArray = geometryObj["coordinates"].toArray();

            for (const QJsonValue& polygonValue : coordinatesArray) {
                QJsonArray polygon = polygonValue.toArray();

                // Créez un vecteur pour stocker les coordonnées du polygone
                QVector<QPointF> polygonPoints;
                // Parcourez les anneaux du polygone
                for (const QJsonValue& ringValue : polygon) {
                    QJsonArray ring = ringValue.toArray();

                    // Parcourez les points du polygone
                    for (const QJsonValue& pointValue : ring) {
                        QJsonArray point = pointValue.toArray();

                        // Extraire les coordonnées individuelles
                        double lon = point[0].toDouble();
                        double lat = point[1].toDouble();

                        // Utilisez position pour convertir les coordonnées géographiques en coordonnées de scène
                        QPointF scenePoint = position->GeoDecimalToCartosienne(lat, lon);

                        polygonPoints.append(scenePoint);
                    }

                    QGraphicsPolygonItem* polygonItem = scene.addPolygon(QPolygonF(polygonPoints), QPen(Qt::blue), QBrush(Qt::gray));
                    polygonPoints.clear();
                }
            }

    }
}

void Custommap::drawPolygon(QGraphicsScene& scene, Position_Aeronef* position, const QString& geojsonFilePath, bool type) {
    // Ouvrir le fichier GeoJSON en lecture
    QFile geojsonFile(geojsonFilePath);
    QBrush ColorBackground;
    QPen ColorPen;

    if (!geojsonFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Erreur lors de l'ouverture du fichier GeoJSON";
        return;
    }

    if (type == territoire){
        ColorBackground = QBrush(Qt::transparent);
        ColorPen = QPen(Qt::black);
    }
    else {
        ColorBackground = QBrush(Qt::gray);
        ColorPen = QPen(Qt::blue);
    }

    // Lire tout le contenu du fichier GeoJSON
    QByteArray geojsonData = geojsonFile.readAll();
    geojsonFile.close();

    // Analyser le GeoJSON en un document JSON
    QJsonDocument jsonDoc = QJsonDocument::fromJson(geojsonData);

    // Vérifier si l'analyse a réussi
    if (!jsonDoc.isObject()) {
        qDebug() << "Erreur lors de l'analyse du GeoJSON";
        return;
    }

    // Obtenir l'objet JSON racine
    QJsonObject jsonObj = jsonDoc.object();
    if (jsonObj.contains("type") && jsonObj["type"].toString() == "FeatureCollection") {

        // Obtenir le tableau "features"
        QJsonArray featuresArray = jsonObj["features"].toArray();

        for (const QJsonValue& featureValue : featuresArray) {
            QJsonObject featureObj = featureValue.toObject();

            if (featureObj.contains("geometry")) {
                QJsonObject geometryObj = featureObj["geometry"].toObject();

                if (geometryObj.contains("type") && geometryObj["type"].toString() == "Polygon") {
                    // Obtenir les coordonnées du polygone
                    QJsonArray coordinatesArray = geometryObj["coordinates"].toArray();

                    QVector<QPointF> polygonPoints;

                    // Parcourez les points du polygone
                    for (const QJsonValue& pointValue : coordinatesArray[0].toArray()) {
                        QJsonArray point = pointValue.toArray();

                        QPointF scenePoint = position->GeoDecimalToCartosienne(point[1].toDouble(), point[0].toDouble());

                        polygonPoints.append(scenePoint);
                    }

                    QGraphicsPolygonItem* polygonItem = scene.addPolygon(QPolygonF(polygonPoints), ColorPen, ColorBackground);
                }
            }
        }
    }
}


void Custommap::culuminant_Point(QGraphicsScene& scene, QPointF position, int altitude, QList<QGraphicsItem *> *ellipseList) {
    double radiusNautical = 25.0; // Rayon en nautiques
    double scalePixelPerNautical = 1.7116 ; // Échelle pixel/nautique (approximativement à la latitude moyenne)
    QBrush ColorCircle = altitude > 3000 ? grayColor : Qt::red;
    // Convertir le rayon de nautiques en pixels
    double radiusPixels = radiusNautical * scalePixelPerNautical;

    circle = scene.addEllipse(QRectF(position.x() - radiusPixels, position.y() - radiusPixels, 2 * radiusPixels, 2 * radiusPixels), QPen(grayColor), ColorCircle); // Utilisation de QBrush pour remplir l'intérieur en rouge
    point = scene.addEllipse(QRectF(position.x() - 2, position.y() - 2, 4, 4), QPen(Qt::NoPen), ColorCircle);
    circle->setOpacity(0.5);

    ellipseList->push_back(point);
    ellipseList->push_back(circle);

}

// Fonction pour ajouter des villes depuis un GeoJSON à la scène
void Custommap::AddCitiesFromGeoJSON(Position_Aeronef* position, QGraphicsScene* scene) {
    // Ouvrir le fichier GeoJSON
    QFile file(loadFile.GotoRacineFile() + QDir::separator() + "City.geojson");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Erreur lors de l'ouverture du fichier GeoJSON";
        return;
    }

    // Lire le contenu du fichier GeoJSON
    QString geoJSON = file.readAll();
    file.close();

    // Charger le GeoJSON
    QJsonDocument jsonDocument = QJsonDocument::fromJson(geoJSON.toUtf8());
    if (!jsonDocument.isObject()) {
        qDebug() << "Erreur lors du chargement du GeoJSON";
        return;
    }

    QJsonObject jsonObject = jsonDocument.object();
    if (!jsonObject.contains("features")) {
        qDebug() << "Le GeoJSON ne contient pas de fonction 'features'";
        return;
    }

    QJsonArray features = jsonObject["features"].toArray();
    for (const QJsonValue& featureValue : features) {
        QJsonObject feature = featureValue.toObject();
        if (!feature.contains("geometry") || !feature["geometry"].isObject()) {
            qDebug() << "La fonction GeoJSON n'a pas de géométrie valide";
            continue;
        }

        QJsonObject geometry = feature["geometry"].toObject();
        if (geometry.contains("coordinates") && geometry["coordinates"].isArray()) {
            QJsonArray coordinates = geometry["coordinates"].toArray();
            if (coordinates.size() == 2 && coordinates[0].isDouble() && coordinates[1].isDouble()) {
                double lon = coordinates[0].toDouble();
                double lat = coordinates[1].toDouble();

                // Convertir les coordonnées géographiques en cartésiennes
                QPointF cartesienne = position->GeoDecimalToCartosienne(lat, lon);

                // Créer un élément graphique pour la ville
                QGraphicsEllipseItem* ville = new QGraphicsEllipseItem(cartesienne.x(), cartesienne.y(), 5, 5);
                ville->setBrush(Qt::green); // Couleur de la ville

                // Ajouter le nom de la ville au-dessus du point
                QString nomVille = feature.value("properties").toObject().value("ville").toString();
                QGraphicsTextItem* textVille = new QGraphicsTextItem(nomVille);
                textVille->setPos(cartesienne.x(), cartesienne.y() - 15); // Décalage vers le haut
                scene->addItem(ville);
                scene->addItem(textVille);
            }
        }
    }
}

void Custommap::DrawAerodrome(Position_Aeronef* position, QGraphicsScene* scene) {
    // Chargez le fichier GeoJSON
    QFile file(loadFile.GotoRacineFile() + QDir::separator() + "Aerodrome.geojson");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Impossible d'ouvrir le fichier GeoJSON.";
        return;
    }

    // Lisez le contenu du fichier GeoJSON
    QString fileContent = file.readAll();
    file.close();

    // Analysez le contenu du fichier GeoJSON
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileContent.toUtf8());
    QJsonObject rootObject = jsonDoc.object();

    // Vérifiez si le fichier GeoJSON contient un tableau de features (points)
    if (rootObject.contains("features") && rootObject["features"].isArray()) {
        QJsonArray features = rootObject["features"].toArray();

        // Parcourez chaque feature (aéroport)
        for (const QJsonValue& featureValue : features) {
            QJsonObject feature = featureValue.toObject();

            // Vérifiez si la feature est un point
            if (feature.contains("geometry") && feature["geometry"].isObject() && feature["geometry"].toObject()["type"] == "Point") {
                // Obtenez les coordonnées du point
                QJsonArray coordinates = feature["geometry"].toObject()["coordinates"].toArray();
                double lon = coordinates[0].toDouble();
                double lat = coordinates[1].toDouble();

                // Utilisez les valeurs de lat et lon pour créer un ellipse
                QPointF positionCartesienne = position->GeoDecimalToCartosienne(lat, lon);
                // Créez un QGraphicsEllipseItem et ajoutez-le à la scène
                QGraphicsEllipseItem* ellipse = scene->addEllipse(QRectF(positionCartesienne.x() - 2, positionCartesienne.y() - 2, 4, 4), QPen(Qt::NoPen), QBrush(Qt::red));
            }
        }
    }
}

void Custommap::showAirport(Position_Aeronef* position,QGraphicsScene *scene){
    QFile file(loadFile.GotoRacineFile() + QDir::separator() + "apt_hvy.dat");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Erreur d'ouverture du fichier";
        return;
    }

    QTextStream in(&file);
    QString previousLine = "";

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(" ", Qt::SkipEmptyParts);

        if (!parts.isEmpty()) {
            QString firstValue = parts.first();

            if (firstValue == "10" && parts.size() >= 3 && parts.last()  == "1") {
                // Ligne contenant des coordonnées d'aéroport
                if (previousLine.contains("LF")) {

                    bool ok; // Un booléen pour vérifier la conversion
                    double latitude = parts[1].toDouble(&ok);
                    double longitude = parts[2].toDouble(&ok);
                    QPointF positionCartesienne = position->GeoDecimalToCartosienne(latitude, longitude);

                    QGraphicsEllipseItem *point = new QGraphicsEllipseItem(0, 0, 5, 5); // Créez un point de 5x5 pixels
                    point->setPos(positionCartesienne.x(), positionCartesienne.y()); // Définissez la position du point sur la scène (50, 50)
                    scene->addItem(point);

                   }
                }

            previousLine = line;

        }
    }

    file.close();
}

