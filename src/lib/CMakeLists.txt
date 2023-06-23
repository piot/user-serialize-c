cmake_minimum_required(VERSION 3.17)
project(guise_serialize C)

set(CMAKE_C_STANDARD 99)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(isDebug TRUE)
else ()
    message("no debug")
    set(isDebug FALSE)
endif ()

if (isDebug)
    message("Debug build detected")
    add_compile_definitions(CONFIGURATION_DEBUG TYRAN_CONFIGURATION_DEBUG)
    set(CONFIGURATION_DEBUG 1)
endif ()

set(DEPS ../../deps/)

file(GLOB lib_src FOLLOW_SYMLINKS "*.c")

add_library(guise_serialize STATIC ${lib_src})

target_compile_options(
        guise_serialize
        PRIVATE -Weverything
        -Wno-padded
        -Wno-declaration-after-statement # must be bug in clang? shows up even if std=c99
        -Werror
)

if (COMPILER_CLANG)
    target_compile_options(
            guise_serialize PRIVATE -Wmost -Weverything
            -Werror=missing-variable-declarations)
endif ()

target_include_directories(guise_serialize PUBLIC ${DEPS}piot/clog/src/include)

target_include_directories(guise_serialize
        PUBLIC ${DEPS}piot/tiny-libc/src/include)

target_include_directories(guise_serialize
        PUBLIC ${DEPS}piot/imprint/src/include)

target_include_directories(guise_serialize
        PUBLIC ${DEPS}piot/flood-c/src/include)

target_include_directories(guise_serialize PUBLIC ../include)
