
if (WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")
elseif (UNIX)
    set(SFML_DIR "/usr/lib/cmake/SFML")
endif ()
find_package(SFML 2.5 COMPONENTS graphics window main network audio REQUIRED)

#include(FetchContent)
#FetchContent_Declare(SFML
#        GIT_REPOSITORY https://github.com/SFML/SFML.git
#        GIT_TAG 2.5.1
#        GIT_SHALLOW ON
#        EXCLUDE_FROM_ALL
#        SYSTEM)
#FetchContent_MakeAvailable(SFML)

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