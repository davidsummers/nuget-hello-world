# Example of how to produce a NUGET package.

project( jsoncpp )

cmake_minimum_required( VERSION 3.17 )

set( JSONCPP_VERSION "1.9.4" )

option( JSCONCPP_WITH_PKGCONFIG_SUPPORT "PKGCONFIG"     OFF )
option( JSONCPP_WITH_CMAKE_PACKAGE      "CMake Package" ON  )
option( JSONCPP_WITH_TESTS              "Tests"         OFF )
option( BUILD_SHARED_LIBS               "Shared Libs"   ON  )
option( BUILD_STATIC_LIBS               "Static Libs"   ON  )

set( CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" )

add_subdirectory( jsoncpp-${JSONCPP_VERSION} )

include_directories( ${CMAKE_SOURCE_DIR}/jsoncpp-${JSONCPP_VERSION} )

set( CPACK_GENERATOR NuGet )

set( CPACK_PACKAGE_NAME "jconcpp" )
set( CPACK_PACKAGE_VENDOR "David Summers" )
set( CPACK_PACKAGE_DESCRIPTION "jconcpp nuget package" )
set( CPACK_PACKAGE_VERSION "${JSONCPP_VERSION}" )
set( CPACK_TOPLEVEL_DIRECTORY "install" )

include( CPack )

