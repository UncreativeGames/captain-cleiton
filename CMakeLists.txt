cmake_minimum_required(VERSION 3.8)
project(captain-cleiton)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        examples/DrawingModule_exemplo_2/main.cpp
        include/Animation.hpp src/Animation.cpp
        include/AnimatedSprite.hpp src/AnimatedSprite.cpp
        include/Chao.hpp src/Chao.cpp
        include/ColisionModule.hpp src/ColisionModule.cpp
        include/Config.hpp
        include/DrawingModule.hpp src/DrawingModule.cpp
        include/DrawTransform.hpp src/DrawTransform.cpp
        include/Floor.hpp src/Floor.cpp
        include/Lista.hpp
        include/Listaestatica.hpp
        include/Obstacle.hpp src/Obstacle.cpp
        include/Rigidbody.hpp src/Rigidbody.cpp
        include/TileMap.hpp src/TileMap.cpp
        src/MapModule.cpp include/MapModule.hpp
        )
add_executable(captain-cleiton ${SOURCE_FILES})
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(SFML REQUIRED system window graphics network audio)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(captain-cleiton ${SFML_LIBRARIES})
endif()