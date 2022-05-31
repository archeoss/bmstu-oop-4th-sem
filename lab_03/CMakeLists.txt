project(
    OOP_Lab_03
    DESCRIPTION "Lab 03 for BMSTU OOP Course, ICS7"
    LANGUAGES CXX
)
cmake_minimum_required(VERSION 3.5)

set(QT_DIR "C:\\Qt\\6.2.4\\mingw_64\\lib\\cmake\\Qt6")
set(CMAKE_PREFIX_PATH "C:\\Qt\\6.2.4\\mingw_64\\")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Qt6 COMPONENTS Widgets REQUIRED)

#add_compile_options(
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
set(DRAWER_DOMAIN src/drawer/)
set(DRAWER_SRC
        ${DRAWER_DOMAIN}/drawer.h
        ${DRAWER_DOMAIN}/drawer.cpp
        ${DRAWER_DOMAIN}/mainwindow.cpp
        ${DRAWER_DOMAIN}/mainwindow.h
        ${DRAWER_DOMAIN}/factory.h
        ${DRAWER_DOMAIN}/factory.cpp)

set(OBJECTS_DOMAIN src/objects/)
set(OBJECTS_SRC
        ${OBJECTS_DOMAIN}/object.h
        ${OBJECTS_DOMAIN}/model.cpp
        ${OBJECTS_DOMAIN}/model.h
        ${OBJECTS_DOMAIN}/visibleObject.h
        ${OBJECTS_DOMAIN}/invisibleObject.h
        ${OBJECTS_DOMAIN}/camera.cpp
        ${OBJECTS_DOMAIN}/camera.h
        ${OBJECTS_DOMAIN}/scene.cpp
        ${OBJECTS_DOMAIN}/scene.h
        ${OBJECTS_DOMAIN}/composite.cpp
        ${OBJECTS_DOMAIN}/composite.h)

set(FACADE_DOMAIN src/command/)
set(FACADE_SRC
        ${FACADE_DOMAIN}/command.h
        ${FACADE_DOMAIN}/facade.cpp
        ${FACADE_DOMAIN}/facade.h)

set(VECTOR_DOMAIN src/vector)
set(VECTOR_SRC
        ${VECTOR_DOMAIN}/vector.hpp
        ${VECTOR_DOMAIN}/vector.h
        ${VECTOR_DOMAIN}/iterator.hpp
        ${VECTOR_DOMAIN}/iterator.h)

set(MANAGERS_DOMAIN src/managers)
set(MANAGERS_SRC
        ${MANAGERS_DOMAIN}/visitor.h
        ${MANAGERS_DOMAIN}/baseManager.h
        ${MANAGERS_DOMAIN}/drawManager.cpp
        ${MANAGERS_DOMAIN}/drawManager.h 
        ${MANAGERS_DOMAIN}/transformManager.cpp 
        ${MANAGERS_DOMAIN}/transformManager.h 
        ${MANAGERS_DOMAIN}/sceneManager.cpp 
        ${MANAGERS_DOMAIN}/sceneManager.h 
        ${MANAGERS_DOMAIN}/cameraManager.cpp 
        ${MANAGERS_DOMAIN}/cameraManager.h)

set(FIGURE_DOMAIN src/figure)
set(FIGURE_SRC
        ${FIGURE_DOMAIN}/edge.cpp
        ${FIGURE_DOMAIN}/edge.h
        ${FIGURE_DOMAIN}/point.cpp
        ${FIGURE_DOMAIN}/point.h
        ${FIGURE_DOMAIN}/figure.cpp
        ${FIGURE_DOMAIN}/figure.h)

set(LOADER_DOMAIN src/loader)
set(LOADER_SRC
        ${LOADER_DOMAIN}/modelBuilder.cpp
        ${LOADER_DOMAIN}/modelBuilder.h
        ${LOADER_DOMAIN}/modelLoader.cpp
        ${LOADER_DOMAIN}/modelLoader.h
        ${LOADER_DOMAIN}/fileLoader.cpp
        ${LOADER_DOMAIN}/fileLoader.h
        ${LOADER_DOMAIN}/baseLoader.h
        ${LOADER_DOMAIN}/loadDirector.cpp
        ${LOADER_DOMAIN}/loadDirector.h
        ${LOADER_DOMAIN}/baseModelBuilder.h
        ${LOADER_DOMAIN}/loader.h
        ${LOADER_DOMAIN}/loadManager.cpp
        ${LOADER_DOMAIN}/loadManager.h)

set(EXCEPTION_DOMAIN src/exceptions)
set(EXCEPTION_SRC
        ${EXCEPTION_DOMAIN}/baseException.h
#        ${EXCEPTION_DOMAIN}/modelLoader.cpp
#        ${EXCEPTION_DOMAIN}/modelLoader.h
#        ${EXCEPTION_DOMAIN}/fileLoader.cpp
#        ${EXCEPTION_DOMAIN}/fileLoader.h
#        ${EXCEPTION_DOMAIN}/baseLoader.h
#        ${EXCEPTION_DOMAIN}/loadDirector.cpp
#        ${EXCEPTION_DOMAIN}/loadDirector.h
#        ${EXCEPTION_DOMAIN}/baseModelBuilder.h
#        ${EXCEPTION_DOMAIN}/loader.h
#        ${EXCEPTION_DOMAIN}/loadManager.cpp
#        ${EXCEPTION_DOMAIN}/loadManager.h
        src/exceptions/containerException.h src/exceptions/defException.h src/exceptions/drawException.h src/exceptions/loadException.h src/exceptions/sceneException.h)

############
##  Tests  #
############
#
#set(SET_TESTS_DOMAIN src/tests)
#set(TESTS_SRC
#${SET_TESTS_DOMAIN}/tests.hpp
#${SET_TESTS_DOMAIN}/tests.h)
#
###############
##  Dir conf  #
###############
#

include_directories(
        ${DRAWER_DOMAIN}
        ${OBJECTS_DOMAIN}
        ${VECTOR_DOMAIN}
        ${FIGURE_DOMAIN}
        ${MANAGERS_DOMAIN}
        ${FACADE_DOMAIN}
        ${LOADER_DOMAIN}
        ${EXCEPTION_DOMAIN}
)
#
#################
##  Executable  #
#################
#
add_executable(lab_03
        main.cpp
        ${OBJECTS_SRC}
        ${VECTOR_SRC}
        ${FIGURE_SRC}
        ${MANAGERS_SRC}
        ${FACADE_SRC}
        ${DRAWER_SRC}
        ${LOADER_SRC}
        ${EXCEPTION_SRC}
        )
#
#

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_COMPILER clang++)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS
        ui
        )

# Make an automatic library - will be static or dynamic based on user setting
QT6_WRAP_UI(
        ${DRAWER_DOMAIN} design/mainwindow.ui)
#add_library(main_library SHARED src/requests.cpp src/events.cpp src/mainwindow.cpp src/figure/figure.cpp src/io.cpp src/alloc.cpp src/edges.cpp src/draw.cpp src/errors.cpp src/points.cpp src/backup.cpp ${HEADER_LIST} ${UI_HEADERS})
#target_include_directories(main_library PUBLIC ./include)
#target_link_libraries(main_library PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
#target_compile_features(main_library PUBLIC cxx_std_11)

#add_executable(lab_03 src/main.cpp ${UI_HEADERS} ui/mainwindow.ui)

#target_compile_features(lab_03 PRIVATE cxx_std_11)
target_link_libraries(lab_03 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
#
#if(QT_VERSION_MAJOR EQUAL 6)
#    qt_finalize_executable(lab_03)
#endif()

# Dummy
#cmake_minimum_required(VERSION 3.5)
#project(dummy)
#
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#
#set(SOURCE_FILES src/command/command.cpp src/facade/facade.cpp )
#add_executable(dummy ${SOURCE_FILES})