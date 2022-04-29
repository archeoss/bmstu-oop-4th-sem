project(
    OOP_Lab_02
    DESCRIPTION "Lab 02 for BMSTU OOP Course, ICS7"
    LANGUAGES CXX
)
cmake_minimum_required(VERSION 3.5)

# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)
# set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_compile_options(
    -Werror

    -Wall
    -Wextra
    -Wpedantic

    -Wcast-align
    -Wcast-qual
    -Wconversion
    -Wctor-dtor-privacy
    -Wenum-compare
    -Wfloat-equal
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Woverloaded-virtual
    -Wredundant-decls
    -Wsign-promo
    
)

set(CMAKE_CXX_STANDARD 11)

#########
#  SRC  #
#########

set(SRC_DOMAIN src/set/)
set(BASE_SRC
        ${SRC_DOMAIN}/container.cpp
        ${SRC_DOMAIN}/container.h
        ${SRC_DOMAIN}/errors.h)

set(SET_DOMAIN src/set/)
set(SET_SRC
        ${SET_DOMAIN}/set.hpp
        ${SET_DOMAIN}/set.h)

set(SET_NODE_DOMAIN src/set/node)
set(SET_NODE_SRC
        ${SET_NODE_DOMAIN}/set_node.hpp
        ${SET_NODE_DOMAIN}/set_node.h)

set(SET_ITERATOR_DOMAIN src/set/iter)
set(SET_ITERATOR_SRC
        ${SET_ITERATOR_DOMAIN}/setIter.hpp
        ${SET_ITERATOR_DOMAIN}/setIter.h)

###########
#  Tests  #
###########

set(SET_TESTS_DOMAIN src/tests)
set(TESTS_SRC
${SET_TESTS_DOMAIN}/tests.hpp
${SET_TESTS_DOMAIN}/tests.h)

##############
#  Dir conf  #
##############

include_directories(
        ${SRC_DOMAIN}
        ${SET_DOMAIN}
        ${SET_NODE_DOMAIN}
        ${SET_ITERATOR_DOMAIN}
        ${SET_TESTS_DOMAIN})

################
#  Executable  #
################

add_executable(lab_02
        src/main.cpp
        ${BASE_SRC}
        ${SET_SRC}
        ${SET_ITERATOR_SRC}
        ${SET_ITERATOR_SRC}
        ${SET_NODE_SRC}
        ${TESTS_SRC})
