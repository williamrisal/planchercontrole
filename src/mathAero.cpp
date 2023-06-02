#include "mathAero.hpp"
#include <QRegularExpression>
#include <QStringList>
#include <iostream>
#include <ostream>

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

