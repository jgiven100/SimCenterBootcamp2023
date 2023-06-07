cmake_minimum_required (VERSION 2.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

project (C-DAY-1)

add_executable(solveQuadratic solveQuadratic.c)
target_link_libraries(solveQuadratic m)

add_executable(pi pi.c)

add_executable(transformStress transformStress.c)
target_link_libraries(transformStress m)


