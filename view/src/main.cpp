#include "Game.h"
#include "GameException.h"
#include "StartMenu.h"
#include <iostream>

int main() {
    // Start the game loop and catch exceptions
    try {
        View::StartMenu menu;
        if (menu.shouldStartGame()) {
            View::Game game(menu.getSelectedFramerate());
            game.run();
        }
    } catch (const Logic::ResourceLoadException& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (const Logic::InvalidCoordinatesException& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (const Logic::NotInitializedException& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (const Logic::GameException& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
