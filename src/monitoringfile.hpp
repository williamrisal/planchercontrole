#ifndef MONITORINGFILE_HPP
#define MONITORINGFILE_HPP


#include "QtCore/qjsonobject.h"
class MonitoringFile
{
public:
    MonitoringFile();
    QJsonObject LoadJson(QString NameJson);
    void modifyJsonFile(const QString &filePath, const QString &RadarName, const QVector3D Rectification);
    QJsonObject loadPointStrategique();
    QJsonObject loadRadar();
    QJsonObject loadRadio();
    QString GotoRacineFile();

};

#endif // MONITORINGFILE_HPP
