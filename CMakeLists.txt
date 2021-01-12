cmake_minimum_required( VERSION 3.15 )

project( HelloWorld )

if ( MSVC )

  set( PLATFORM "windows-x64" )
  set( TARGET_FRAMEWORK "win10" )

  add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
  add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)

else( )

  set( PLATFORM "linux-x64" )
  set( TARGET_FRAMEWORK "lin" )

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

set( ZLIB_ROOT ${CMAKE_BINARY_DIR}/packages/zlib.1.2.11-2-${PLATFORM} )

find_package( ZLIB REQUIRED )

add_executable( hello
                hello.cpp
              )

target_include_directories( hello PUBLIC
                            ${ZLIB_INCLUDE_DIRS}
                          )

target_link_libraries( hello PUBLIC
                       ${ZLIB_LIBRARIES}
                     )
