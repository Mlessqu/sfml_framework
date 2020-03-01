cmake_minimum_required(VERSION 3.15)
project(sfml_framework)
set(CMAKE_CXX_STANDARD 14)
set(SFML_DIR "./SFML-2.5.1/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)
include_directories(src)
add_executable(sfml_framework
    src/main.cpp
        src/statemanager.cpp src/statemanager.h src/state.cpp src/state.h src/mainmenu.cpp src/mainmenu.h)


target_link_libraries(sfml_framework sfml-audio sfml-graphics sfml-window sfml-system )