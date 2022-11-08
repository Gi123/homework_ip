cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(homework_ip VERSION ${PROJECT_VESRION})

add_executable(homework_ip ip_filter.cpp)
set_target_properties(
    homework_ip PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)