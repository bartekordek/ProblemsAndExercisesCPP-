#cmake -DCMAKE_BUILD_TYPE=Debug
cmake_minimum_required(VERSION 3.0.0)

set( CMAKE_CXX_STANDARD 17 )
set( EXEC Problems )
project(${EXEC} LANGUAGES CXX)

if (MSVC)
    add_compile_options( /W4 /WX)
    add_compile_options( /MP )
    set( gtest_force_shared_crt ON CACHE BOOL "" FORCE )
else()
    add_compile_options( -Wall -Wextra -pedantic -Werror )
    add_definitions( -Wfatal-errors )
endif()

set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PAndE_OUTPUT_DIR} )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PAndE_OUTPUT_DIR} )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PAndE_OUTPUT_DIR} )

message( "[Problems] Searchng for cul..." )
find_package( cul REQUIRED )
if( cul_FOUND )
    message( "[Problems] cul found:" )
    message( "[Problems] inc: ${cul_INCLUDE_DIR}" )
    message( "[Problems] lib: ${cul_LIBRARY}" )
endif( cul_FOUND )

message( "[Problems] Searchng for cul... done." )

include_directories(src)
file( GLOB SOURCES src/*.cpp )
file( GLOB INCLUDES src/*.hpp )

add_executable( ${EXEC} ${SOURCES} ${INCLUDES} )

if (MSVC)
    set_target_properties(
        ${EXEC}
        PROPERTIES
            OUTPUT_NAME ${EXEC}
            SUFFIX ".exe"
    )
else()
    set_target_properties(
        ${EXEC}
        PROPERTIES
            OUTPUT_NAME ${EXEC}
            SUFFIX ".bin"
    )
endif()

target_link_libraries( ${EXEC} cul gtest gmock AdditionalDeps )

target_include_directories( ${EXEC} PRIVATE inc )
target_include_directories( ${EXEC} PRIVATE src )

if (MSVC)
    set_target_properties( ${EXEC} PROPERTIES LINK_FLAGS "/INCREMENTAL:NO" )
    message( "[Problems] Setting cul tests run dir to: ${PAndE_TESTS_RUN_DIR}" )
    set_target_properties( ${EXEC} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PAndE_TESTS_RUN_DIR}" )
    set_target_properties( ${EXEC} PROPERTIES VS_DEBUGGER_COMMAND_ARGUMENTS  "--gtest_break_on_failure" )

    CMakeToWindow( ${PAndE_TESTS_RUN_DIR} PAndE_TESTS_RUN_DIR_WINDOWS )
    CMakeToWindow( ${PAndE_OUTPUT_DIR} PAndE_OUTPUT_DIR_WINDOWS )
    CMakeToWindow( ${PAndE_DEPS} PAndE_DEPS_WINDOWS )

    add_custom_command(TARGET ${EXEC} POST_BUILD
        COMMAND ${PAndE_DEPS_WINDOWS}\\CUL\\deps\\helpers\\CopyLibraryBinaryAndSymbolsRecursive.bat ${PAndE_OUTPUT_DIR_WINDOWS} ${PAndE_TESTS_RUN_DIR_WINDOWS}
        COMMAND ${PAndE_DEPS_WINDOWS}\\CUL\\deps\\helpers\\CopyLibraryBinaryAndSymbolsRecursive.bat ${PAndE_DEPS_WINDOWS} ${PAndE_TESTS_RUN_DIR_WINDOWS}
    )
endif()