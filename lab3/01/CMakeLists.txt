cmake_minimum_required(VERSION 3.10)

project(lab3)

add_executable(shifting shifting.cpp)
add_executable(printing printing.cpp)
add_executable(drawing drawing.cpp)

set(TARGETS shifting printing drawing)

set_target_properties(
    ${TARGETS} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO)

foreach(T ${TARGETS})
    if (MSVC)
        target_compile_options(
            ${T} PRIVATE /Wall /WX)
    else()
        target_compile_options(
            ${T} PRIVATE -Wall -Wextra)
    endif()
endforeach()
