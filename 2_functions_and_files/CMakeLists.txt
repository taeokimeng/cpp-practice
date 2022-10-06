cmake_minimum_required(VERSION 3.0.0)
project(2_functions_and_files VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB PROJ_SRC "*.h" "*.cpp")
add_executable(2_functions_and_files ${PROJ_SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
