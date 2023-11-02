#include "position_aeronef.hpp"
#include <GeographicLib/Geocentric.hpp>
#include <GeographicLib/LocalCartesian.hpp>
#include <iostream>
#include "QtCore/qrect.h"
#include "mathAero.cpp"
using namespace GeographicLib;
using namespace std;

Position_Aeronef::Position_Aeronef()
{

}

QPointF Position_Aeronef::GeoToCartosienne(const QString& dmsCoordinate)
{
    QPointF coordonnes;

    try {
        mathAero MathConvertor;
        Geocentric earth(Constants::WGS84_a(), Constants::WGS84_f());
        const double lat0 = 43 + 31/60.0 + 21/3600.0; // Latitude de référence (Istres)
        const double lon0 = 4 + 55/60.0 + 27/3600.0; // Longitude de référence (Istres)

        LocalCartesian proj(lat0, lon0, 0, earth);
        // Conversion des coordonnées DMS en décimal
        double lat = MathConvertor.convertDMSToDecimal(dmsCoordinate.section(' ', 0, 0)); // Latitude de Calais
        double lon = MathConvertor.convertDMSToDecimal(dmsCoordinate.section(' ', 1, 1)); // Longitude de Calais

        double x, y, z;
        proj.Forward(lat, lon, 0, x, y, z);
        coordonnes.setX(x);
        coordonnes.setY(y);
    }
    catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << "\n";
    }

    return Echelle_MAP(coordonnes);
}


QPointF Position_Aeronef::GeoDecimalToCartosienne(double lat, double lon)
{

    QPointF coordonnes;
    try {
        mathAero MathConvertor;
        Geocentric earth(Constants::WGS84_a(), Constants::WGS84_f());
        const double lat0 = 43 + 31/60.0 + 21/3600.0; // Latitude de référence (Istres)
        const double lon0 = 4 + 55/60.0 + 27/3600.0; // Longitude de référence (Istres)

        LocalCartesian proj(lat0, lon0, 0, earth);
        // Conversion des coordonnées de Calais en décimal

        double h = 0; // Altitude de Calais

        double x, y, z;
        proj.Forward(lat, lon, h, x, y, z);
        coordonnes.setX(x);
        coordonnes.setY(y);

    }
    catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << "\n";
    }
    return Echelle_MAP(coordonnes);

}

QPointF Position_Aeronef::CartesienneToGeographieDecimal(QPointF cartesienne) {
    try {

        // Définissez les paramètres de la planète (WGS84 par exemple)
        Geocentric earth(Constants::WGS84_a(), Constants::WGS84_f());
        const double lat0 = 43 + 31/60.0 + 21/3600.0; // Latitude de référence (Istres)
        const double lon0 = 4 + 55/60.0 + 27/3600.0; // Longitude de référence (Istres)

        // Créez une projection locale centrée sur le point de référence
        LocalCartesian proj(lat0, lon0, 0, earth);

        // Convertissez les coordonnées cartésiennes en coordonnées géographiques
        double x = cartesienne.x();
        double y = cartesienne.y();
        double z = 0; // L'altitude est supposée être à zéro

        double lat, lon, h;
        proj.Reverse(x, y, z, lat, lon, h);

        // Convertissez les coordonnées degrés, minutes, secondes en décimal
        double latDecimal = lat;
        double lonDecimal = lon;
        qDebug() << "lat" << latDecimal << "lon" << lonDecimal;
        return QPointF(latDecimal, lonDecimal);
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << "\n";
    }

    // En cas d'erreur ou d'exception, retournez un QPointF nul
    return QPointF(0, 0);
}

QPointF Position_Aeronef::Echelle_MAP(QPointF position) {
    double scaledX = std::round(position.x()  / (640));
    double scaledY = std::round(position.y()  / (640));

    double x_final = scaledX;
    double y_final = -scaledY;

    QPointF result;
    result.setX(x_final);
    result.setY(y_final);

    return result;
}

