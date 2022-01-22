cmake_minimum_required(VERSION 3.0.0)
project(game VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories ( src/logic/actor )
include_directories ( src/logic/actor/player )
include_directories ( src/logic/controller )
include_directories ( src/logic/logic_manager )
include_directories ( src/logic/physics_manager )
include_directories ( src/logic/static_actor )

add_executable(game src/main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
