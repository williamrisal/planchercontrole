#ifndef POSITION_AERONEF_HPP
#define POSITION_AERONEF_HPP

#include "QtCore/qpoint.h"
#include "QtCore/qstring.h"
#include <iostream>
#include <exception>
#include <cmath>
#include <GeographicLib/LocalCartesian.hpp>


class Position_Aeronef
{
public:
    Position_Aeronef();
    QPointF GeoToCartosienne(const QString &dmsCoordinate);
    QPointF GeoDecimalToCartosienne(double lat, double lon);
    QPointF Echelle_MAP(QPointF position);
    QPointF CartesienneToGeographieDecimal(QPointF cartesienne);
};

#endif // POSITION_AERONEF_HPP
