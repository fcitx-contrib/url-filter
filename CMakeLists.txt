cmake_minimum_required(VERSION 3.27)

project(url-filter VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

option(ENABLE_TEST "Build Test" On)

add_custom_command(
    OUTPUT ${PROJECT_SOURCE_DIR}/src/url-json.hpp
    COMMAND ${PROJECT_SOURCE_DIR}/transform_json.py
    COMMAND xxd -n JSON_RULE -i "${PROJECT_SOURCE_DIR}/url.json" > "${PROJECT_SOURCE_DIR}/src/url-json.hpp"
    DEPENDS ${PROJECT_SOURCE_DIR}/Rules/data.min.json
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMENT "Generating ClearURLs Rules header..."
)
add_custom_target(TransformJSON ALL
    DEPENDS ${PROJECT_SOURCE_DIR}/src/url-json.hpp
)

add_library(url-filter
    src/url-filter.cpp
)

if (ENABLE_TEST)
    enable_testing()
    add_subdirectory(test)
endif()
