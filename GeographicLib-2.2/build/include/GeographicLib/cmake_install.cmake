# Install script for directory: /Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/GeographicLib" TYPE FILE FILES
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/Accumulator.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/AlbersEqualArea.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/AuxAngle.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/AuxLatitude.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/AzimuthalEquidistant.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/CassiniSoldner.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/CircularEngine.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/Constants.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/DAuxLatitude.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/DMS.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/DST.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/Ellipsoid.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/EllipticFunction.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/GARS.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/GeoCoords.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/Geocentric.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/Geodesic.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/GeodesicExact.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/GeodesicLine.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/GeodesicLineExact.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/Geohash.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/Geoid.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/Georef.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/Gnomonic.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/GravityCircle.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/GravityModel.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/LambertConformalConic.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/LocalCartesian.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/MGRS.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/MagneticCircle.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/MagneticModel.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/Math.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/NearestNeighbor.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/NormalGravity.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/OSGB.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/PolarStereographic.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/PolygonArea.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/Rhumb.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/SphericalEngine.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/SphericalHarmonic.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/SphericalHarmonic1.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/SphericalHarmonic2.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/TransverseMercator.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/TransverseMercatorExact.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/UTMUPS.hpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/include/GeographicLib/Utility.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/GeographicLib" TYPE FILE FILES "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build/include/GeographicLib/Config.h")
endif()

