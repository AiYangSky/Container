cmake_minimum_required(VERSION 3.0.0)

project(Container_example)
 
add_subdirectory(src)

add_executable(${PROJECT_NAME}  
    example/Container_example.c
)

target_link_libraries(${PROJECT_NAME}
    Container
)

target_include_directories(${PROJECT_NAME} 
    PUBLIC
    "${PROJECT_BINARY_DIR}"
)