cmake_minimum_required(VERSION 3.0.0)
project(3_debugging VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB PROJ_SRC "*.h" "*.cpp")
add_executable(3_debugging ${PROJ_SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
