cmake_minimum_required(VERSION 3.22)

project(align-g4)

add_library(align-g4 INTERFACE)

target_include_directories(align-g4 INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/cmsis-g4/Include
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/cmsis-5/CMSIS/Core/Include
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/stm32g4-hal/Inc
)

target_sources(align-g4 INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/align.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/stm32g4-hal/Src/
)