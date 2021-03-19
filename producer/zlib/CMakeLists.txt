# Example of how to produce a NUGET package.

project( zlib C )

cmake_minimum_required( VERSION 3.17 )

set( ZLIB_VERSION "1.2.11" )

set( CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" )

add_subdirectory( zlib-${ZLIB_VERSION} )

set( ZLIB_SOURCE_DIR "${CMAKE_SOURCE_DIR}/zlib-${ZLIB_VERSION}" )

message( "*** ZLIB_SOURCE_DIR = ${ZLIB_SOURCE_DIR}" )

include_directories( ZLIB_SOURCE_DIR )

set( CPACK_GENERATOR NuGet )

set( CPACK_PACKAGE_NAME "zlib" )
set( CPACK_PACKAGE_VENDOR "David Summers" )
set( CPACK_PACKAGE_DESCRIPTION "zlib nuget package" )
set( CPACK_PACKAGE_VERSION "${ZLIB_VERSION}" )
set( CPACK_TOPLEVEL_DIRECTORY "install" )

include( CPack )

