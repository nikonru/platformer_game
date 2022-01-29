cmake_minimum_required(VERSION 3.0.0)
project(game VERSION 0.1.0)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

include_directories ( src/logic/actor )
include_directories ( src/logic/controller )
include_directories ( src/logic/game_clock )
include_directories ( src/logic/logic_manager )
include_directories ( src/logic/physics_manager )
include_directories ( src/logic/static_actor )
include_directories ( src/util )
include_directories ( src/input_manager )

include_directories ( src/graphics )
include_directories ( src/util )
include_directories ( src/input_manager)

list ( APPEND SRC src/main.cpp )
list ( APPEND SRC src/logic/actor/actor.cpp )
list ( APPEND SRC src/logic/controller/controller.cpp )
list ( APPEND SRC src/logic/game_clock/game_clock.cpp )
list ( APPEND SRC src/logic/logic_manager/logic_manager.cpp )
list ( APPEND SRC src/logic/physics_manager/physics_manager.cpp )
list ( APPEND SRC src/logic/static_actor/static_actor.cpp )
list ( APPEND SRC src/graphics/graphics_manager.cpp )
list ( APPEND SRC src/input_manager/input_manager.cpp )
list ( APPEND SRC src/input_manager/input_manager_observer.cpp )

include_directories ( 3rdparty/sfml/include )

add_compile_options("-lsfml-graphics" "-lsfml-window" "-lsfml-system")

add_executable(game ${SRC})
target_link_libraries(game sfml-graphics sfml-audio)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
