#include "position_aeronef.hpp"
#include "QtCore/qstring.h"
#include <GeographicLib/Geocentric.hpp>
#include <GeographicLib/LocalCartesian.hpp>
#include <iostream>
#include "mathAero.cpp"
using namespace GeographicLib;
using namespace std;

Position_Aeronef::Position_Aeronef()
{

}

double* Position_Aeronef::GeoToCartosienne(const QString& dmsCoordinate)
{

    double* coordonnes = new double[3]; // Allouer un tableau de 3 doubles
    try {
        mathAero MathConvertor;
        Geocentric earth(Constants::WGS84_a(), Constants::WGS84_f());
        const double lat0 = 43 + 31/60.0 + 21/3600.0; // Latitude de référence (Istres)
        const double lon0 = 4 + 55/60.0 + 27/3600.0; // Longitude de référence (Istres)

        LocalCartesian proj(lat0, lon0, 0, earth);
        // Conversion des coordonnées de Calais en décimal
        double lat = MathConvertor.convertDMSToDecimal(dmsCoordinate.section(' ', 0, 0)); // Latitude de Calais

        double lon = MathConvertor.convertDMSToDecimal(dmsCoordinate.section(' ', 1, 1)); // Longitude de Calais
        double h = 0; // Altitude de Calais
        cout << "lat" << lat << "lon " << lon << "\n" << std::endl;

        double x, y, z;
        proj.Forward(lat, lon, h, x, y, z);
        cout << x << " " << y << " " << z << "\n" << std::endl;
        coordonnes[0] = x;
        coordonnes[1] = y;
        coordonnes[2] = z;

        // Calcul en inverse
        double lat_rev, lon_rev, h_rev;
        proj.Reverse(coordonnes[0], coordonnes[1], coordonnes[2], lat_rev, lon_rev, h_rev);
        cout << lat_rev << " " << lon_rev << " " << h_rev << "\n" << std::endl;
    }
    catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << "\n";
    }

    return Echelle_MAP(coordonnes);
}


double* Position_Aeronef::Echelle_MAP(double* position) {
    double scaleFactor = 1.3;
    double scaledX = std::round(position[0] * scaleFactor / (1280 / 2));
    double scaledY = std::round(position[1] * scaleFactor / (720 / 2));

    double x_final = scaledX + 640;
    double y_final = std::abs((scaledY + 360) - 720);

    double* result = new double[2];
    result[0] = x_final;
    result[1] = y_final;
    std::cout << "Scaled coordinates:" << std::endl;
    std::cout << "x: " << x_final << std::endl;
    std::cout << "y: " << y_final << std::endl;

    return result;
}
