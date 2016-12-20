cmake_minimum_required(VERSION 3.6)
project(TanksGame)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp Game.cpp Game.h Entity.cpp Entity.h GameWorld.cpp GameWorld.h Game.cpp Game.h Tank.cpp Tank.h Terrain.cpp Terrain.h)
set(RESOURCE_FILES image.png)
add_executable(TanksGame ${SOURCE_FILES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")



# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(TanksGame ${SFML_LIBRARIES})
endif()


# Install target
install(TARGETS TanksGame DESTINATION bin)