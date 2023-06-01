#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "GeographicLib::GeographicLib_SHARED" for configuration "Release"
set_property(TARGET GeographicLib::GeographicLib_SHARED APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeographicLib::GeographicLib_SHARED PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libGeographicLib.24.1.0.dylib"
  IMPORTED_SONAME_RELEASE "@rpath/libGeographicLib.24.dylib"
  )

list(APPEND _cmake_import_check_targets GeographicLib::GeographicLib_SHARED )
list(APPEND _cmake_import_check_files_for_GeographicLib::GeographicLib_SHARED "${_IMPORT_PREFIX}/lib/libGeographicLib.24.1.0.dylib" )

# Import target "GeographicLib::CartConvert" for configuration "Release"
set_property(TARGET GeographicLib::CartConvert APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeographicLib::CartConvert PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/CartConvert"
  )

list(APPEND _cmake_import_check_targets GeographicLib::CartConvert )
list(APPEND _cmake_import_check_files_for_GeographicLib::CartConvert "${_IMPORT_PREFIX}/bin/CartConvert" )

# Import target "GeographicLib::ConicProj" for configuration "Release"
set_property(TARGET GeographicLib::ConicProj APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeographicLib::ConicProj PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/ConicProj"
  )

list(APPEND _cmake_import_check_targets GeographicLib::ConicProj )
list(APPEND _cmake_import_check_files_for_GeographicLib::ConicProj "${_IMPORT_PREFIX}/bin/ConicProj" )

# Import target "GeographicLib::GeodesicProj" for configuration "Release"
set_property(TARGET GeographicLib::GeodesicProj APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeographicLib::GeodesicProj PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/GeodesicProj"
  )

list(APPEND _cmake_import_check_targets GeographicLib::GeodesicProj )
list(APPEND _cmake_import_check_files_for_GeographicLib::GeodesicProj "${_IMPORT_PREFIX}/bin/GeodesicProj" )

# Import target "GeographicLib::GeoConvert" for configuration "Release"
set_property(TARGET GeographicLib::GeoConvert APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeographicLib::GeoConvert PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/GeoConvert"
  )

list(APPEND _cmake_import_check_targets GeographicLib::GeoConvert )
list(APPEND _cmake_import_check_files_for_GeographicLib::GeoConvert "${_IMPORT_PREFIX}/bin/GeoConvert" )

# Import target "GeographicLib::GeodSolve" for configuration "Release"
set_property(TARGET GeographicLib::GeodSolve APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeographicLib::GeodSolve PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/GeodSolve"
  )

list(APPEND _cmake_import_check_targets GeographicLib::GeodSolve )
list(APPEND _cmake_import_check_files_for_GeographicLib::GeodSolve "${_IMPORT_PREFIX}/bin/GeodSolve" )

# Import target "GeographicLib::GeoidEval" for configuration "Release"
set_property(TARGET GeographicLib::GeoidEval APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeographicLib::GeoidEval PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/GeoidEval"
  )

list(APPEND _cmake_import_check_targets GeographicLib::GeoidEval )
list(APPEND _cmake_import_check_files_for_GeographicLib::GeoidEval "${_IMPORT_PREFIX}/bin/GeoidEval" )

# Import target "GeographicLib::Gravity" for configuration "Release"
set_property(TARGET GeographicLib::Gravity APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeographicLib::Gravity PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/Gravity"
  )

list(APPEND _cmake_import_check_targets GeographicLib::Gravity )
list(APPEND _cmake_import_check_files_for_GeographicLib::Gravity "${_IMPORT_PREFIX}/bin/Gravity" )

# Import target "GeographicLib::MagneticField" for configuration "Release"
set_property(TARGET GeographicLib::MagneticField APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeographicLib::MagneticField PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/MagneticField"
  )

list(APPEND _cmake_import_check_targets GeographicLib::MagneticField )
list(APPEND _cmake_import_check_files_for_GeographicLib::MagneticField "${_IMPORT_PREFIX}/bin/MagneticField" )

# Import target "GeographicLib::Planimeter" for configuration "Release"
set_property(TARGET GeographicLib::Planimeter APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeographicLib::Planimeter PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/Planimeter"
  )

list(APPEND _cmake_import_check_targets GeographicLib::Planimeter )
list(APPEND _cmake_import_check_files_for_GeographicLib::Planimeter "${_IMPORT_PREFIX}/bin/Planimeter" )

# Import target "GeographicLib::RhumbSolve" for configuration "Release"
set_property(TARGET GeographicLib::RhumbSolve APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeographicLib::RhumbSolve PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/RhumbSolve"
  )

list(APPEND _cmake_import_check_targets GeographicLib::RhumbSolve )
list(APPEND _cmake_import_check_files_for_GeographicLib::RhumbSolve "${_IMPORT_PREFIX}/bin/RhumbSolve" )

# Import target "GeographicLib::TransverseMercatorProj" for configuration "Release"
set_property(TARGET GeographicLib::TransverseMercatorProj APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeographicLib::TransverseMercatorProj PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/TransverseMercatorProj"
  )

list(APPEND _cmake_import_check_targets GeographicLib::TransverseMercatorProj )
list(APPEND _cmake_import_check_files_for_GeographicLib::TransverseMercatorProj "${_IMPORT_PREFIX}/bin/TransverseMercatorProj" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
