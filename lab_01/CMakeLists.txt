project(
    OOP_Lab_01
    DESCRIPTION "Lab 01 for BMSTU OOP Course, ICS7"
    LANGUAGES CXX
)
cmake_minimum_required(VERSION 3.5)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(HEADER_LIST 
"${OOP_Lab_01_SOURCE_DIR}/include/mainwindow.h"
"${OOP_Lab_01_SOURCE_DIR}/include/io.h"
"${OOP_Lab_01_SOURCE_DIR}/include/points.h"
"${OOP_Lab_01_SOURCE_DIR}/include/errors.h"
"${OOP_Lab_01_SOURCE_DIR}/include/alloc.h"
"${OOP_Lab_01_SOURCE_DIR}/include/alloc.inl"
"${OOP_Lab_01_SOURCE_DIR}/include/def.h"
"${OOP_Lab_01_SOURCE_DIR}/include/figure.h"
"${OOP_Lab_01_SOURCE_DIR}/include/edges.h"
"${OOP_Lab_01_SOURCE_DIR}/include/requests.h"
"${OOP_Lab_01_SOURCE_DIR}/include/draw.h"
"${OOP_Lab_01_SOURCE_DIR}/include/backup.h"
)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS
    ui
)
# add_compile_options(
#     -Werror

#     -Wall
#     -Wextra
#     -Wpedantic

#     -Wcast-align
#     -Wcast-qual
#     -Wconversion
#     -Wctor-dtor-privacy
#     -Wenum-compare
#     -Wfloat-equal
#     -Wnon-virtual-dtor
#     -Wold-style-cast
#     -Woverloaded-virtual
#     -Wredundant-decls
#     -Wsign-promo
    
# )

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Qt6 COMPONENTS Widgets REQUIRED)

# Make an automatic library - will be static or dynamic based on user setting
QT6_WRAP_UI( UI_HEADERS ui/mainwindow.ui )
add_library(main_library STATIC src/requests.cpp src/mainwindow.cpp src/figure.cpp src/io.cpp src/alloc.cpp src/edges.cpp src/draw.cpp src/errors.cpp src/points.cpp src/backup.cpp ${HEADER_LIST} ${UI_HEADERS})
target_include_directories(main_library PUBLIC ./include)
target_link_libraries(main_library PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_compile_features(main_library PUBLIC cxx_std_11)

add_executable(lab_01 src/main.cpp ${UI_HEADERS} ui/mainwindow.ui)

target_compile_features(lab_01 PRIVATE cxx_std_11)
target_link_libraries(lab_01 PRIVATE main_library Qt${QT_VERSION_MAJOR}::Widgets)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(lab_01)
endif()
