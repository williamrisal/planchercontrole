#include "monitoringfile.hpp"
#include "QtCore/qdir.h"
#include "QtCore/qpoint.h"
#include "src/mathAero.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

MonitoringFile::MonitoringFile()
{

}


QJsonObject MonitoringFile::LoadJson(QString NameJson) {

    QFile file(NameJson);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Impossible d'ouvrir le fichier JSON : " << file.errorString();
    }
    QString jsonContent = file.readAll();

    file.close();

    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonContent.toUtf8(), &jsonError);

    if (jsonError.error != QJsonParseError::NoError) {
        qWarning() << "Erreur de parsing JSON : " << jsonError.errorString();
    }

    if (!jsonDoc.isObject()) {
        qWarning() << "Le document JSON n'est pas un objet JSON valide.";
    }

    return(jsonDoc.object());

}


void MonitoringFile::modifyJsonFile(const QString &filePath, const QString &RadarName, const QVector3D Rectification) {
    QFile jsonFile(filePath);
    mathAero math;

    if (jsonFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonFile.readAll());
        QVariantMap jsonData = jsonDoc.toVariant().toMap();

        if (jsonData.contains(RadarName)) {
            QVariantMap radarData = jsonData[RadarName].toMap();
            radarData["Rectification"] = math.ConvertQVector3DToString(Rectification);
            jsonData[RadarName] = radarData;
        } else {
            jsonFile.close();
            qDebug() << "Erreur : Radar introuvable dans le fichier JSON.";
            return;
        }

        jsonFile.resize(0);
        jsonFile.seek(0);

        QJsonDocument newJsonDoc = QJsonDocument::fromVariant(jsonData);
        jsonFile.write(newJsonDoc.toJson());

        jsonFile.close();
    } else {
        qDebug() << "Erreur : Impossible d'ouvrir le fichier JSON.";
    }
}


QJsonObject MonitoringFile::loadRadar(){
    QJsonObject jsonObj = LoadJson(GotoRacineFile() + QDir::separator() + "src"+ QDir::separator() + "RadarPosition.json");
   // trouver une solution ici pour que le path soi adapter
    return (jsonObj);
}

QJsonObject MonitoringFile::loadRadio(){
    QJsonObject jsonObj = LoadJson(GotoRacineFile() + QDir::separator() + "Radio"+ QDir::separator() + "RadioPosition.json");
    // trouver une solution ici pour que le path soi adapter
    return (jsonObj);
}

QJsonObject MonitoringFile::loadPointStrategique(){
    QJsonObject jsonObj = LoadJson(GotoRacineFile() + QDir::separator() + "src"+ QDir::separator() + "Position_Strategique.json");
    return (jsonObj);

}

QString MonitoringFile::GotoRacineFile(){
    QDir directory(QDir::currentPath());

    directory.cdUp(); // Remonte au répertoire parent
    directory.cdUp(); // Remonte au répertoire parent
    directory.cdUp(); // Remonte au répertoire parent
    directory.cdUp(); // Remonte au répertoire parent

    directory.cd("planchercontrole-main"); // Descend dans le répertoire "planchercontrole-main"
    return directory.path();
}




