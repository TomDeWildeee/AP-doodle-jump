#ifndef DOODLE_JUMP_GAMECONTROLLER_H
#define DOODLE_JUMP_GAMECONTROLLER_H

#include "../logic/World.h"
#include <SFML/Window/Event.hpp>
namespace View {

class GameController {
public:
    GameController(std::shared_ptr<Logic::World> world);
    void update();
    void handleInput(const sf::Event& event);

private:
    std::shared_ptr<Logic::World> world;
    bool gameOver = false;
};

} // namespace View

#endif // DOODLE_JUMP_GAMECONTROLLER_H
