# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BUILD_SOURCE_DIRS "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2;/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build")
set(CPACK_CMAKE_GENERATOR "Unix Makefiles")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "/opt/homebrew/Cellar/cmake/3.26.4/share/cmake/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "GeographicLib built using CMake")
set(CPACK_DMG_SLA_USE_RESOURCE_FILE_LICENSE "ON")
set(CPACK_GENERATOR "TGZ;ZIP")
set(CPACK_IGNORE_FILES "#;~$;/\\.git;/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/BUILD;/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/man/(.*\\.pod|makeusage\\.sh|dummy\\..*)$;/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/cmake/maintainer-.*\\.cmake$;/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/(develop|cgi-bin|.*\\.cache)/;/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/(data-distrib|data-installer)/;/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/(archive|scratch|mpfr_mpir_x86_x64_msvc2010)/;/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/.*\\.(zip|tar\\.gz|bak|lsp)$;/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/(autogen|biblio)\\.sh$;/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/(pom.xml|makefile-admin|HOWTO-RELEASE.txt)$")
set(CPACK_INSTALLED_DIRECTORIES "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2;/")
set(CPACK_INSTALL_CMAKE_PROJECTS "")
set(CPACK_INSTALL_PREFIX "/usr/local")
set(CPACK_MODULE_PATH "")
set(CPACK_NSIS_DISPLAY_NAME "GeographicLib-2.2")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
set(CPACK_NSIS_PACKAGE_NAME "GeographicLib-2.2")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OBJDUMP_EXECUTABLE "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
set(CPACK_OSX_SYSROOT "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX13.3.sdk")
set(CPACK_OUTPUT_CONFIG_FILE "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build/CPackConfig.cmake")
set(CPACK_PACKAGE_CONTACT "charles@karney.com")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "/opt/homebrew/Cellar/cmake/3.26.4/share/cmake/Templates/CPack.GenericDescription.txt")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "GeographicLib library, utilities, and documentation")
set(CPACK_PACKAGE_FILE_NAME "GeographicLib-2.2")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "GeographicLib-2.2")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "GeographicLib-2.2")
set(CPACK_PACKAGE_NAME "GeographicLib")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "GeographicLib")
set(CPACK_PACKAGE_VERSION "2.2")
set(CPACK_PACKAGE_VERSION_MAJOR "2")
set(CPACK_PACKAGE_VERSION_MINOR "2")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_RESOURCE_FILE_LICENSE "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/LICENSE.txt")
set(CPACK_RESOURCE_FILE_README "/opt/homebrew/Cellar/cmake/3.26.4/share/cmake/Templates/CPack.GenericDescription.txt")
set(CPACK_RESOURCE_FILE_WELCOME "/opt/homebrew/Cellar/cmake/3.26.4/share/cmake/Templates/CPack.GenericWelcome.txt")
set(CPACK_RPM_PACKAGE_SOURCES "ON")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_GENERATOR "TGZ;ZIP")
set(CPACK_SOURCE_IGNORE_FILES "#;~$;/\\.git;/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/BUILD;/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/man/(.*\\.pod|makeusage\\.sh|dummy\\..*)$;/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/cmake/maintainer-.*\\.cmake$;/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/(develop|cgi-bin|.*\\.cache)/;/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/(data-distrib|data-installer)/;/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/(archive|scratch|mpfr_mpir_x86_x64_msvc2010)/;/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/.*\\.(zip|tar\\.gz|bak|lsp)$;/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/(autogen|biblio)\\.sh$;/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/(pom.xml|makefile-admin|HOWTO-RELEASE.txt)$")
set(CPACK_SOURCE_INSTALLED_DIRECTORIES "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2;/")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build/CPackSourceConfig.cmake")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "GeographicLib-2.2")
set(CPACK_SOURCE_TOPLEVEL_TAG "Darwin-Source")
set(CPACK_STRIP_FILES "")
set(CPACK_SYSTEM_NAME "Darwin")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "Darwin-Source")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "/Users/williamrisal/Documents/DGA projet/PlancherControle/GeographicLib-2.2/build/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
