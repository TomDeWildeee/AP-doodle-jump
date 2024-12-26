#ifndef DOODLE_JUMP_GAME_H
#define DOODLE_JUMP_GAME_H

#include "SFML/Graphics.hpp"

namespace View {

class Game {
public:
    Game();
    void run();

private:
    // Predefined functions, not sure if they are needed
    void processEvents();
    void update();
    void render();
    void handleGameOver();

    sf::RenderWindow window;
    sf::Font font;
    sf::Text gameOverText;
    sf::Text scoreText;
    bool isGameOver = false;
};
} // namespace View

#endif // DOODLE_JUMP_GAME_H