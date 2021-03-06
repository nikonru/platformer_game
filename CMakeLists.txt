cmake_minimum_required(VERSION 3.0.0)
project(game VERSION 0.1.0)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

file(COPY content DESTINATION ${CMAKE_BINARY_DIR}/bin/)

find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} )

include_directories ( src/logic/actor )
include_directories ( src/logic/controller )
include_directories ( src/logic/game_clock )
include_directories ( src/logic/logic_manager )
include_directories ( src/logic/physics_manager )
include_directories ( src/logic/physics_manager/physic_body )
include_directories ( src/logic/world_generator )
include_directories ( src/util )
include_directories ( src/input_manager )

include_directories ( src/graphics )
include_directories ( src/graphics/content )

add_subdirectory ("3rdparty/sfml")
add_subdirectory ("3rdparty/box2d")

list ( APPEND SRC src/main.cpp )
list ( APPEND SRC src/util/b2GLDraw.cpp )
list ( APPEND SRC src/logic/actor/actor.cpp )
list ( APPEND SRC src/logic/actor/dynamic_actor.cpp )
list ( APPEND SRC src/logic/actor/static_actor.cpp )
list ( APPEND SRC src/logic/actor/player_actor.cpp )
list ( APPEND SRC src/logic/controller/controller.cpp )
list ( APPEND SRC src/logic/game_clock/game_clock.cpp )
list ( APPEND SRC src/logic/logic_manager/logic_manager.cpp )
list ( APPEND SRC src/logic/physics_manager/physics_manager.cpp )
list ( APPEND SRC src/logic/physics_manager/physic_body/physic_body.cpp )
list ( APPEND SRC src/logic/world_generator/world_generator.cpp )
list ( APPEND SRC src/graphics/graphics_manager.cpp )
list ( APPEND SRC src/graphics/content/content_manager.cpp )
list ( APPEND SRC src/input_manager/input_manager_observer.cpp )
list ( APPEND SRC src/input_manager/input_manager.cpp )

include_directories ( 3rdparty/sfml/include )
include_directories ( 3rdparty/box2d/include )

add_executable(game ${SRC})

target_link_libraries(game sfml-graphics sfml-audio sfml-window box2d)
target_link_libraries(game ${OPENGL_LIBRARIES}) 

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
