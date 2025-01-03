/**
 * @file GameController.h
 * @brief Handles game input and control
 */

#ifndef DOODLE_JUMP_GAMECONTROLLER_H
#define DOODLE_JUMP_GAMECONTROLLER_H

#include "../../logic/include/World.h"
#include <SFML/Window/Event.hpp>
namespace View {

/**
 * @class GameController
 * @brief Processes input and controls game state
 */
class GameController {
public:
    /**
     * @brief Constructs controller for game world
     * @param world Shared pointer to game world
     */
    explicit GameController(std::shared_ptr<Logic::World> world);

    /**
     * @brief Updates controller state
     */
    void update();

    /**
     * @brief Handles input events
     * @param event SFML event to process
     */
    void handleInput(const sf::Event& event);

private:
    std::shared_ptr<Logic::World> world;
    bool gameOver = false;
};

} // namespace View

#endif // DOODLE_JUMP_GAMECONTROLLER_H
