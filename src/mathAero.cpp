#include "mathAero.hpp"
#include "QtGui/qvectornd.h"
#include <QRegularExpression>
#include <QStringList>
#include <iostream>
#include <ostream>
#include <QPointF>
#include <QString>

mathAero::mathAero()
{

}

double mathAero::convertDMSToDecimal(const QString& dmsCoordinate)
{
    QStringList parts = dmsCoordinate.split(QRegularExpression("[^\\d.]"), Qt::SkipEmptyParts);
    double degrees = parts[0].toDouble();
    double minutes = parts[1].toDouble();
    double seconds = parts[2].toDouble();
    QChar hemisphere = dmsCoordinate[0];
    
    double decimalCoordinate = degrees + (minutes / 60.0) + (seconds / 3600.0);
    if (hemisphere == 'S' || hemisphere == 'W') {
        decimalCoordinate *= -1.0;
    }

    return decimalCoordinate;
}

QPointF mathAero::ConvertStringtoQPointF(QString str){

    str = str.mid(1, str.length() - 2); // Pour supprimer les accolades

    QStringList parts = str.split(",");

    if (parts.size() == 2) {
        bool ok1, ok2;
        qreal x = parts[0].toDouble(&ok1);
        qreal y = parts[1].toDouble(&ok2);

        if (ok1 && ok2) {
            QPointF point(x, y);
            return point;

        }
    }
}

QVector3D mathAero::ConvertStringtoQVector3D(QString str) {
    str = str.mid(1, str.length() - 2);

    QStringList parts = str.split(",");

    if (parts.size() == 3) {
        bool ok1, ok2;
        qreal x = parts[0].toDouble(&ok1);
        qreal y = parts[1].toDouble(&ok2);
        qreal z = parts[2].toDouble(&ok2);
        qDebug() << "x" << x << "y" << y << "z" << z;

        if (ok1 && ok2) {
            QVector3D point(x, y, z);
            return point;
        }
    }

    return QVector3D();
}


QString mathAero::QpointToString(const QPointF& point, int zoom) {
    return "{" + QString::number(point.x()) + "," + QString::number(point.y()) + "," + QString::number(zoom) + "}";
}


QString mathAero::ConvertQVector3DToString(const QVector3D& vector3D) {
    return QString("{%1,%2,%3}").arg(vector3D.x()).arg(vector3D.y()).arg(vector3D.z());
}
