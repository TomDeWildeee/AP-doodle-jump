#ifndef DOODLE_JUMP_GAME_H
#define DOODLE_JUMP_GAME_H

#include "../logic/Score.h"
#include "../logic/World.h"
#include "ConcreteFactory.h"
#include "GameController.h"
#include "SFML/Graphics.hpp"
#include <memory>

namespace View {

class Game {
public:
    Game();
    ~Game();
    void run();

private:
    // Predefined functions, not sure if they are needed
    void processEvents();
    void update();
    void render();
    void handleGameOver();

    sf::RenderWindow window;
    std::shared_ptr<Logic::World> world;
    std::unique_ptr<GameController> gameController;
    std::shared_ptr<ConcreteFactory> factory;
    std::shared_ptr<Logic::Score> score;

    sf::Font font;
    sf::Text gameOverText;
    sf::Text scoreText;
    bool isGameOver = false;
};
} // namespace View

#endif // DOODLE_JUMP_GAME_H