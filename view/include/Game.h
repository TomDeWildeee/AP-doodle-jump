#ifndef DOODLE_JUMP_GAME_H
#define DOODLE_JUMP_GAME_H

#include "ConcreteFactory.h"
#include "GameController.h"
#include "SFML/Graphics.hpp"
#include <memory>

namespace View {

class Game {
public:
    explicit Game(int frameRate);
    ~Game();
    void run();

private:
    void processEvents();
    void update();
    void render();
    void handleGameOver();

    int displayedScore = 0;

    sf::RenderWindow window;
    std::shared_ptr<Logic::World> world;
    std::unique_ptr<GameController> gameController;
    std::shared_ptr<ConcreteFactory> factory;
    std::shared_ptr<Logic::Score> score;

    sf::Font font;
    sf::Text gameOverText;
    sf::Text scoreText;

    sf::RectangleShape gameOverBackground;

    bool isGameOver = false;
};
} // namespace View

#endif // DOODLE_JUMP_GAME_H