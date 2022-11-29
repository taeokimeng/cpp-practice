cmake_minimum_required(VERSION 3.0.0)
project(7_control_flow_and_error_handling VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB PROJ_SRC "*.h" "*.cpp")
add_executable(7_control_flow_and_error_handling ${PROJ_SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
