#ifndef POSITION_AERONEF_HPP
#define POSITION_AERONEF_HPP

#include "QtCore/qstring.h"
#include <iostream>
#include <exception>
#include <cmath>
#include <GeographicLib/LocalCartesian.hpp>


class Position_Aeronef
{
public:
    Position_Aeronef();
    double *GeoToCartosienne(const QString &dmsCoordinate);
    double *Echelle_MAP(double* position);
};

#endif // POSITION_AERONEF_HPP
