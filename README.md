# AP-doodle-jump

Original Repository: [AP-doodle-jump](https://github.com/TomDeWildeee/AP-doodle-jump)

- #### Name: Tom De Wilde
- #### Student Number: 20230881

## Project Structure

- #### `logic/`:
    - Contains the logic of the game.
- #### `view/`:
    - Contains the view of the game.
- #### `docs/`:
    - Contains the documentation of the game.
- #### `CMakelists.txt`:
    - Contains the cmake configuration.

## FAQ

- #### How to run the game?
    - Run these commands:
        - `mkdir build && cd build`
        - `cmake ..`
        - `make`
        - `cd view`
        - `./DoodleJump`
- #### What if the game doesn't run?
    - Make sure you have [SFML 2.5.1](https://www.sfml-dev.org/download/sfml/2.5.1/) installed _(You can uncomment
      FetchContent_Declare in the CMakeLists.txt file if
      needed)_. Additionally, make sure you have the necessary dependencies
      installed. [SFML Dependencies](https://www.sfml-dev.org/faq/general/#dependencies)
    - Make sure you are in the directory `./build/view` when running the game.
- #### What if the game instantly kills me?
    - Make sure the game window is fully visible on your screen, if not the game will malfunction and instantly kill
      you.
- #### Where does the highscore get saved?
    - The highscore gets saved in a file called 'highscore.txt' in the directory where you ran this application.