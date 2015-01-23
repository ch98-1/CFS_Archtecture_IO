cmake_minimum_required (VERSION 2.6)
project (CFS_CPU_IO)
include_directories(${PROJECT_SOURCE_DIR})
add_library(CFS_CPU_IO CPU.c)
add_executable(CFS_CLI_IO Main.c)

#Lookup and add sdl2 for input and output
set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake"
  )
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})

target_link_libraries(CFS_CLI_IO CFS_CPU)
