cmake_minimum_required(VERSION 3.0.0)
project(game VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories ( src/graphics/ )

list(APPEND SRC src/main.cpp )
list(APPEND SRC src/graphics/graphics_manager.cpp )

add_compile_options("-lsfml-graphics" "-lsfml-window" "-lsfml-system")

add_executable(game ${SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
