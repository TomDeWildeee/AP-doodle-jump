/**
 * @file Game.h
 * @brief Main game class managing game loop and state
 */

#ifndef DOODLE_JUMP_GAME_H
#define DOODLE_JUMP_GAME_H

#include "ConcreteFactory.h"
#include "GameController.h"
#include "SFML/Graphics.hpp"
#include <memory>

namespace View {

/**
 * @class Game
 * @brief Manages main game loop, rendering and state
 */
class Game {
public:
    /**
     * @brief Constructs game with specified frame rate
     * @param frameRate Target frames per second
     */
    explicit Game(int frameRate);
    ~Game();

    /**
     * @brief Starts game loop
     */
    void run();

private:
    /**
     * @brief Processes input events
     */
    void processEvents();

    /**
     * @brief Updates game state
     */
    void update();

    /**
     * @brief Renders game state
     */
    void render();

    /**
     * @brief Handles game over state
     */
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