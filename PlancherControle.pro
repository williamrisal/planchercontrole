QT       += core gui
include($${PWD}/QSidePanel-Sidebar-master/QSidePanel/q_side_panel.pri)
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/custommap.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/mapimage.cpp \
    src/mathAero.cpp \
    src/monitoringfile.cpp \
    src/position_aeronef.cpp \
    src/sidebarpreference.cpp

HEADERS += \
    src/custommap.hpp \
    src/mainwindow.h \
    src/mapimage.hpp \
    src/mathAero.hpp \
    src/monitoringfile.hpp \
    src/position_aeronef.hpp \
    src/showimage.hpp \
    src/sidebarpreference.hpp

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


DISTFILES += \
    City.geojson \
    Perimetre/carre_paca.geojson \
    Perimetre/main.py \
    Perimetre/polygone_paca.geojson \
    Radio/SRSA Istres-2.png \
    Radio/SRSA Istres-2.png \
    Radio/SRSA Istres-2.png \
    Radio/SRSA Istres-2.png \
    Region/PathRegion.json \
    Region/region-auvergne-rhone-alpes.geojson \
    Region/region-bretagne.geojson \
    Region/region-nouvelle-aquitaine.geojson \
    Region/region-occitanie.geojson \
    Region/region-pays-de-la-loire.geojson \
    Region/region-provence-alpes-cote-d-azur.geojson \
    Region/regions.geojson \
    region-provence-alpes-cote-d-azur.geojson \
    src/PositionPointCulminant.json \
    src/Position_Strategique.json \
    src/RadarPosition.json

macx: LIBS += -L$$PWD/GeographicLib-2.2/build/src/ -lGeographicLib

INCLUDEPATH += $$PWD/GeographicLib-2.2/include
DEPENDPATH += $$PWD/GeographicLib-2.2/include
