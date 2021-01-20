#cmake -DCMAKE_BUILD_TYPE=Debug
cmake_minimum_required(VERSION 3.0.0)

project( ProblemsAndExercisesCPP )

set( CMAKE_POSITION_INDEPENDENT_CODE ON )
set( PAndE_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR} )
set( PAndE_TESTS_RUN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/runDir" )
set( PAndE_DEPS ${PAndE_ROOT_DIR}/deps )

if( MSVC )
    set( PAndE_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Build-Windows )
else()
    set( PAndE_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Build-Linux )
endif()


set( CUL_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/deps/CUL )
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CUL_ROOT}/cmake_modules" )

add_subdirectory( ${CUL_ROOT} )
add_subdirectory( Problems )