cmake_minimum_required(VERSION 3.1)
project(fin-in)
add_executable(${PROJECT_NAME} src/main.cpp )
install(TARGETS ${PROJECT_NAME} DESTINATION bin)