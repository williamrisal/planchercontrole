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
    // Séparation des degrés, minutes et secondes
    QStringList parts = dmsCoordinate.split(QRegularExpression("[^\\d.]"), Qt::SkipEmptyParts);

    // Récupération des parties de la coordonnée
    double degrees = parts[0].toDouble();

    double minutes = parts[1].toDouble();

    double seconds = parts[2].toDouble();

    QChar hemisphere = dmsCoordinate[0];


    // Conversion en décimal
    double decimalCoordinate = degrees + (minutes / 60.0) + (seconds / 3600.0);

    // Application du signe en fonction de l'hémisphère (N, S, E, W)
    if (hemisphere == 'S' || hemisphere == 'W') {
        decimalCoordinate *= -1.0;
    }

    return decimalCoordinate;
}

