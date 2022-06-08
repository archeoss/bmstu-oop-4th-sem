project(
    OOP_Lab_04
    DESCRIPTION "Lab 04 for BMSTU OOP Course, ICS7"
    LANGUAGES CXX
)
cmake_minimum_required(VERSION 3.5)

# set(QT_DIR "C:\\Qt\\6.2.4\\mingw_64\\lib\\cmake\\Qt6")
# set(CMAKE_PREFIX_PATH "C:\\Qt\\6.2.4\\mingw_64\\")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Qt6 COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_COMPILER clang++)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS
        src/gui
        )

# Make an automatic library - will be static or dynamic based on user setting
QT6_WRAP_UI(
        src/gui/mainwindow.h design/mainwindow.ui)
# add_compile_options(-Wno-everything)
#    -Werror
#
#    -Wall
#    -Wextra
#    -Wpedantic
#
#    -Wcast-align
#    -Wcast-qual
#    -Wconversion
#    -Wctor-dtor-privacy
#    -Wenum-compare
#    -Wfloat-equal
#    -Wnon-virtual-dtor
#    -Wold-style-cast
#    -Woverloaded-virtual
#    -Wredundant-decls
#    -Wsign-promo
#
#)
#
set(CMAKE_CXX_STANDARD 17)
#
##########
##  SRC  #
##########
#
set(CABIN_DOMAIN src/cabin/)
set(CABIN_SRC
        ${CABIN_DOMAIN}/cabin.h
        ${CABIN_DOMAIN}/cabin.cpp)

set(CNTRL_DOMAIN src/control_panel/)
set(CNTRL_SRC
        ${CNTRL_DOMAIN}/controlpanel.h
        ${CNTRL_DOMAIN}/controlpanel.cpp)

set(DOORS_DOMAIN src/doors/)
set(DOORS_SRC
        ${DOORS_DOMAIN}/doors.h
        ${DOORS_DOMAIN}/doors.cpp)

set(GUI_DOMAIN src/gui)
set(GUI_SRC
        ${GUI_DOMAIN}/mainwindow.cpp
        ${GUI_DOMAIN}/mainwindow.h)

set(LIFT_DOMAIN src/lift)
set(LIFT_SRC
        ${LIFT_DOMAIN}/lift.h
        ${LIFT_DOMAIN}/lift.cpp)
#
###############
##  Dir conf  #
###############
#

include_directories(
        ${CABIN_DOMAIN}
        ${CNTRL_DOMAIN}
        ${DOORS_DOMAIN}
        ${GUI_DOMAIN}
        ${LIFT_DOMAIN}
        src/
)
#
#################
##  Executable  #
#################
#
add_executable(lab_04
        src/main.cpp
        src/constants.h
        ${CABIN_SRC}
        ${CNTRL_SRC}
        ${DOORS_SRC}
        ${GUI_SRC}
        ${LIFT_SRC}
        )
target_link_libraries(lab_04 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
