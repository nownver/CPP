cmake_minimum_required(VERSION 3.10)

project(3_2)

add_executable(3_2 3_2.cpp nse/html.cpp)

set(TARGETS 3_2)

set_target_properties(
    ${TARGETS}
    PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO)

# foreach(T ${TARGETS})
#     if (MSVC)
#         target_compile_options(${T} PRIVATE /Wall /WX)
#     else()
#         target_compile_options(${T} PRIVATE -Wall -Wextra)
#     endif()
# endforeach()
