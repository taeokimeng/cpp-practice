cmake_minimum_required(VERSION 3.0.0)
project(8_implicit_type_conversion VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB PROJ_SRC "*.h" "*.cpp")
add_executable(8_implicit_type_conversion ${PROJ_SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
