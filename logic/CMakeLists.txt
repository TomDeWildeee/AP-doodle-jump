set(LOGIC_SOURCES
        src/BGTile.cpp
        src/Bonus.cpp
        src/Camera.cpp
        src/EntityModel.cpp
        src/Platform.cpp
        src/Player.cpp
        src/Random.cpp
        src/Score.cpp
        src/Stopwatch.cpp
        src/Subject.cpp
        src/World.cpp
)

add_library(LogicLib STATIC
        ${LOGIC_SOURCES})

target_include_directories(LogicLib PUBLIC
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)