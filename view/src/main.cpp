#include "Game.h"
#include "StartMenu.h"

int main() {
    View::StartMenu menu;
    if (menu.shouldStartGame()) {
        View::Game game(menu.getSelectedFramerate());
        game.run();
    }

    return 0;
}
