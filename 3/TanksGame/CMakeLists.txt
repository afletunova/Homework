cmake_minimum_required(VERSION 3.6)
project(TanksGame)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp Game.cpp Game.h Entity.cpp Entity.h GameWorld.cpp GameWorld.h Game.cpp Game.h KeyboardTank.cpp KeyboardTank.h Terrain.cpp Terrain.h KeyboardGun.cpp KeyboardGun.h Shell.cpp Shell.h NetworkManager.h Command.h ServerNetworkManager.cpp ServerNetworkManager.h NetworkManager.cpp ClientNetworkManager.cpp ClientNetworkManager.h RemoteTank.cpp RemoteTank.h RemoteGun.cpp RemoteGun.h
        vendor/easylogging++.cc vendor/easylogging++.h Tank.cpp Tank.h Gun.cpp Gun.h)
set(RESOURCE_FILES image.png)
add_executable(TanksGame ${SOURCE_FILES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(TanksGame ${SFML_LIBRARIES})
endif ()


# Install target
install(TARGETS TanksGame DESTINATION bin)

set(RESOURCES tank.png gun.png)

foreach (resource IN LISTS RESOURCES)
    add_custom_command(
            TARGET TanksGame POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/${resource}" "${CMAKE_CURRENT_BINARY_DIR}/${resource}"
            DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${resource}"
    )
endforeach ()
