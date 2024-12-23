set(SFML_STATIC_LIBRARIES TRUE)

if (WIN32)
    set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")
elseif (UNIX)
    set(SFML_DIR "/usr/lib/x86_64-linux-gnu/cmake/SFML")
endif ()
find_package(SFML 2.5 COMPONENTS graphics window main network audio REQUIRED)

SET(SRC main.cpp)
ADD_EXECUTABLE(code ${SRC})
target_link_libraries(code
        PRIVATE

        sfml-graphics
        sfml-window
        sfml-main
        sfml-network
        sfml-audio
)