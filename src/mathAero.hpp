#ifndef mathAeroAERO_H
#define mathAeroAERO_H


#include "QtCore/qpoint.h"
#include "QtCore/qstring.h"
#include "QtGui/qvectornd.h"
class mathAero
{
public:
    mathAero();
    double convertDMSToDecimal(const QString& dmsCoordinate);
    QPointF ConvertStringtoQPointF(QString str);
    QString QpointToString(const QPointF& point, int zoom);
    QVector3D ConvertStringtoQVector3D(QString str);
    QString vectorToString(const QVector3D& vector);
    QString ConvertQVector3DToString(const QVector3D& vector3D);

};

#endif // mathAeroAERO_H
