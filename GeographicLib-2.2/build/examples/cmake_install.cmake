# Install script for directory: /Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/GeographicLib-dev" TYPE FILE FILES
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/CMakeLists.txt"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-Accumulator.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-AlbersEqualArea.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-AuxAngle.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-AuxLatitude.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-AzimuthalEquidistant.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-CassiniSoldner.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-CircularEngine.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-Constants.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-DMS.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-DST.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-Ellipsoid.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-EllipticFunction.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-GARS.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-GeoCoords.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-Geocentric.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-Geodesic.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-Geodesic-small.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-GeodesicExact.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-GeodesicLine.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-GeodesicLineExact.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-GeographicErr.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-Geohash.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-Geoid.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-Georef.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-Gnomonic.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-GravityCircle.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-GravityModel.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-LambertConformalConic.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-LocalCartesian.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-MGRS.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-MagneticCircle.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-MagneticModel.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-Math.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-NearestNeighbor.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-NormalGravity.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-OSGB.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-PolarStereographic.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-PolygonArea.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-Rhumb.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-RhumbLine.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-SphericalEngine.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-SphericalHarmonic.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-SphericalHarmonic1.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-SphericalHarmonic2.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-TransverseMercator.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-TransverseMercatorExact.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-UTMUPS.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/example-Utility.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/GeoidToGTX.cpp"
    "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/examples/make-egmcof.cpp"
    )
endif()

