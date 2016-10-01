SET(CMAKE_SYSTEM_NAME Generic)
cmake_minimum_required (VERSION 3.2)
project(Arithmos)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include_directories(
  src/includes
)

set(CMAKE_CXX_FLAGS "-g -DDEBUG -std=c++11 -O3 -Wall -Weffc++ -Wextra")

add_executable(
  ${PROJECT_NAME}

  src/main.cc
)

add_custom_command(TARGET ${PROJECT_NAME}
  POST_BUILD
  COMMAND size $<TARGET_FILE:${PROJECT_NAME}>.exe -A)

add_subdirectory(src/tests)

option(BUILD_TESTS "Determine whether to build tests." ON)
if(BUILD_TESTS)
  enable_testing()

  if(NOT TARGET Catch)
    include(ExternalProject)
    set(FETCH_EXTERNAL_CATCH
      URL https://github.com/philsquared/Catch/archive/master.zip
    )
    ExternalProject_Add(Catch-External
      PREFIX ${CMAKE_BINARY_DIR}/external/catch
      ${FETCH_EXTERNAL_CATCH}
      CONFIGURE_COMMAND ""
      BUILD_COMMAND ""
      INSTALL_COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/external/Catch/src/Catch-External/single_include/catch.hpp
                                               ${CMAKE_BINARY_DIR}/external/Catch/include/catch.hpp
    )
    add_library(Catch INTERFACE)
    add_dependencies(Catch Catch-External)
    target_include_directories(Catch INTERFACE ${CMAKE_BINARY_DIR}/external/Catch/include)
  endif()
endif()
