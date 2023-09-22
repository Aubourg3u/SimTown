cmake_minimum_required(VERSION 3.10)

# set the project name
project(HelloProj VERSION 1.0)

# specify the C++ standard
# use the CMAKE_CXX_STANDARD variable
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIERED TRUE)

#export configuration to source code
configure_file(CMake/SimTownConfig.h.in SimTownConfig.h)

#add libraries
add_subdirectory(src/class)

#add executable
option(HELLOWORD_WITH_EXECUTABLES "Compile mains" ON)
if(HELLOWORD_WITH_EXECUTABLES)
 message(STATUS "Configuring Hello World with executables")
 add_subdirectory(mains)
endif()