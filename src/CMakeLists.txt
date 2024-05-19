cmake_minimum_required(VERSION 3.6.0)
project(homeden VERSION 0.1.0 LANGUAGES C CXX)

list(APPEND SOURCES "src/main.cpp" "src/comanda.hpp" "src/produs.hpp" "src/user.hpp" "src/listaProduse.h")

add_executable(homeden ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
