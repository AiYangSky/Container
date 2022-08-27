add_library(Container)

file(GLOB LIB_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.c)

target_sources(Container
    PRIVATE
    ${LIB_FILES}
)

target_include_directories(Container
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)