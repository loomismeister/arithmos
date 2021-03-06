project(Arithmos)
SET(CMAKE_SYSTEM_NAME Generic)
cmake_minimum_required (VERSION 3.2)

SET_PROPERTY(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS TRUE)

include_directories(
  src/includes
)

add_subdirectory(src/tests)
add_subdirectory(libs/sqlite)

set(CMAKE_CXX_FLAGS "-g -DDEBUG -std=c++11 -O3 -Wall -Weffc++ -Wextra")

add_executable(
  ${PROJECT_NAME}

  src/main.cc
)

target_link_libraries(${PROJECT_NAME}
  sqlite
  )

add_custom_command(TARGET ${PROJECT_NAME}
  POST_BUILD
  COMMAND size $<TARGET_FILE:${PROJECT_NAME}> -A)

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
