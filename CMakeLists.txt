cmake_minimum_required(VERSION 3.20)

add_subdirectory(lib)

project(game)

add_executable(
    ${PROJECT_NAME}
    "src/main.c"
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        "inc"
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
        fbgl   
)

install(
    TARGETS
    ${PROJECT_NAME}
)