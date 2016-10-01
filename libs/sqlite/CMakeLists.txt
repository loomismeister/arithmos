# define project for C language
project(sqlite C)

message("Building on: ${CMAKE_SYSTEM_NAME}")

option(SQLITE_BUILD_STATIC  "Build SQLite static library" ON)
option(WITH_SQLITE_DEBUG    "Build SQLite debug features" OFF)
option(WITH_SQLITE_MEMDEBUG "Build SQLite memory debug features" OFF)
option(WITH_SQLITE_RTREE    "Build R*Tree index extension" OFF)

set(SQLITE_WIN_BUILD OFF)
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(SQLITE_WIN_BUILD ON)
endif()

# ---------------------
# Version detection
# ---------------------
file(STRINGS "sqlite3.h" _sqlite_api_h_VER_STRING REGEX ".*#define[ ]+SQLITE_VERSION[ ]+")

string(REGEX MATCH "[0-9\\.]+" SQLITE_VER_STRING ${_sqlite_api_h_VER_STRING})
string(REGEX MATCHALL "[0-9]+" _sqlite_ver_LIST "${SQLITE_VER_STRING}")
list(LENGTH _sqlite_ver_LIST _sqlite_list_len)
list(GET _sqlite_ver_LIST 0 SQLITE_VER_MAJOR)
list(GET _sqlite_ver_LIST 1 SQLITE_VER_MINOR)
list(GET _sqlite_ver_LIST 2 SQLITE_VER_PATCH)
if(_sqlite_list_len EQUAL 4)
    list(GET _sqlite_ver_LIST 3 SQLITE_VER_PATCHLEVEL)
    message("Patch level: ${SQLITE_VER_PATCHLEVEL}")
endif()

message("FOUND: SQLite version = ${SQLITE_VER_STRING}")

find_package(Threads REQUIRED)

set(SRC_LIB_FILE sqlite${SQLITE_VER_MAJOR}.c)
set(SRC_SHELL_FILE shell.c)
file(GLOB HDR_FILES *.h)

# adding compilation flags depending on options
if(WITH_SQLITE_DEBUG)
    add_definitions(-DSQLITE_DEBUG)
endif()
if(WITH_SQLITE_MEMDEBUG)
    add_definitions(-DSQLITE_MEMDEBUG)
endif()
if(WITH_SQLITE_RTREE)
    add_definitions(-DSQLITE_ENABLE_RTREE)
endif()

if (SQLITE_BUILD_STATIC)
    # build static library
    add_library(${PROJECT_NAME} STATIC ${SRC_LIB_FILE})
endif()

# build shell executable
#add_executable(shell ${SRC_SHELL_FILE})
