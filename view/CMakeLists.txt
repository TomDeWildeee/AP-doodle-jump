# If needed, download SFML
#FetchContent_Declare(
#        sfml
#        GIT_REPOSITORY "https://github.com/SFML/SFML.git"
#        GIT_TAG        "2.5.1"
#)
#
#FetchContent_GetProperties(sfml)
#if(NOT sfml_POPULATED)
#    FetchContent_Populate(sfml)
#    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
#endif()

if (WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")
    find_package(SFML 2.5 COMPONENTS graphics window main network audio REQUIRED)
elseif (UNIX)
    set(SFML_DIR "/usr/lib/cmake/SFML")
    find_package(SFML 2.5 COMPONENTS graphics window system network audio REQUIRED)
endif ()


SET(VIEW_SOURCES
        src/main.cpp
        src/BGTileView.cpp
        src/BonusView.cpp
        src/ConcreteFactory.cpp
        src/EntityView.cpp
        src/Game.cpp
        src/GameController.cpp
        src/PlatformView.cpp
        src/PlayerView.cpp
        src/StartMenu.cpp
)
ADD_EXECUTABLE(DoodleJump ${VIEW_SOURCES})

if (WIN32)
    target_link_libraries(DoodleJump
            PRIVATE

            LogicLib
            sfml-graphics
            sfml-window
            sfml-main
            sfml-network
            sfml-audio
    )
elseif (UNIX)
    target_link_libraries(DoodleJump
            PRIVATE

            LogicLib
            sfml-graphics
            sfml-window
            sfml-system
            sfml-network
            sfml-audio
    )
endif ()

target_include_directories(DoodleJump
        PRIVATE
        include
)