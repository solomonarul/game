cmake_minimum_required(VERSION 3.20)

project(fbgl)

add_library(
    ${PROJECT_NAME}
    "src/bitmap.c"
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        "inc"
    PRIVATE
        "inc/fbgl"
)

install(
    TARGETS
    ${PROJECT_NAME}
)