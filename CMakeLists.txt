cmake_minimum_required(VERSION 3.23)

set(PROJECT_NAME UML)
project(${PROJECT_NAME})

set(application UMLApplication)
set(library UMLLibrary)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Config" FORCE)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/UMLLibrary)

add_subdirectory(UMLLibrary)
add_subdirectory(UMLApplication)
add_subdirectory(gtest)
add_subdirectory(test)
