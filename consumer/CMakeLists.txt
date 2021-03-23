cmake_minimum_required( VERSION 3.15 )

project( HelloWorld )

set( JSONCPP_CONSUME_VERSION "1.9.4" )

if ( JSONCPP_CONSUME_VERSION MATCHES "1.9.4" )

  set( JSONCPP_LIB_DIR "lib64" )

else( )

  set( JSONCPP_LIB_DIR "lib" )

endif( )

# Find Nuget
find_program( NUGET nuget )
if ( NOT NUGET )

  message( FATAL "CMake could not find the nuget command line tool.  Please install it!" )

else( )

  # Copy the Nuget config file from source location to the CMake build directory.
  configure_file( packages.config.in packages.config )

  # Run Nuget using the .config file to install any missing depednencies to the build directory
  execute_process( COMMAND
	           ${NUGET} restore packages.config -Noninteractive -SolutionDirectory ${CMAKE_BINARY_DIR}
                   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
                 )
  
endif( )

set( jsoncpp_DIR ${CMAKE_BINARY_DIR}/packages/jsoncpp.${JSONCPP_CONSUME_VERSION}/${JSONCPP_LIB_DIR}/cmake/jsoncpp )

message( "jsoncpp_DIR = ${jsoncpp_DIR}" )

find_package( jsoncpp REQUIRED )

message( "jsoncpp_INCLUDE_DIRS = ${jsoncpp_INCLUDE_DIRS}" )
message( "jsoncpp_LIBRARIES = ${jsoncpp_LIBRARIES}" )

add_executable( hello
                hello.cpp
              )

target_link_libraries( hello PUBLIC
                       jsoncpp_static
                     )
