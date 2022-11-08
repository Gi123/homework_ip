cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(homework_ip VERSION ${PROJECT_VESRION})

add_executable(homework_ip_cli ip_filter.cpp)

set_target_properties(homework_ip_cli homework_ip PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(homework_ip
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(homework_ip_cli PRIVATE
    homework_ip
)

if (MSVC)
    target_compile_options(homework_ip_cli PRIVATE
        /W4
    )
    target_compile_options(homework_ip PRIVATE
        /W4
    )
else ()
    target_compile_options(homework_ip_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(homework_ip PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS homework_ip_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)