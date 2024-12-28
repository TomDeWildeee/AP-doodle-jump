
if (WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")
    find_package(SFML 2.5 COMPONENTS graphics window main network audio REQUIRED)
elseif (UNIX)
    set(SFML_DIR "/usr/lib/cmake/SFML")
    find_package(SFML 2.5 COMPONENTS graphics window system network audio REQUIRED)
endif ()

SET(SRC main.cpp
        headers/logic/EntityFactory.h
        headers/logic/Observer.h
        view/Game.cpp
        logic/Subject.cpp
        logic/EntityModel.cpp
        logic/Player.cpp
        logic/Platform.cpp
        logic/BGTile.cpp
        logic/Bonus.cpp
        logic/Random.cpp
        logic/Stopwatch.cpp
        logic/Camera.cpp
        logic/Score.cpp
        view/EntityView.cpp
        view/PlayerView.cpp
        view/PlatformView.cpp
        view/BonusView.cpp
        view/BGTileView.cpp
        view/ConcreteFactory.cpp
        logic/World.cpp
)
ADD_EXECUTABLE(code ${SRC})

if (WIN32)
    target_link_libraries(code
            PRIVATE

            sfml-graphics
            sfml-window
            sfml-main
            sfml-network
            sfml-audio
    )
elseif (UNIX)
    target_link_libraries(code
            PRIVATE

            sfml-graphics
            sfml-window
            sfml-system
            sfml-network
            sfml-audio
    )
endif ()