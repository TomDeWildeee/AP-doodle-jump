#include <utility>

#include "../../logic/include/Player.h"
#include "../include/GameController.h"

namespace View {

GameController::GameController(std::shared_ptr<Logic::World> world) : world(std::move(world)) {}

void GameController::update() { world->update(); }

void GameController::handleInput(const sf::Event& event) {

    // Get player and check if player exists
    std::shared_ptr<Logic::Player> player = world->getPlayer();
    if (!player)
        return;

    // Handle input based on key pressed and move player left or right or stop player movement if no key is pressed
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A) {
            player->moveLeft();
        } else if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D) {
            player->moveRight();
        } else {
            std::pair<float, float> newVelocity = {0, player->getVelocity().second};
            player->setVelocity(newVelocity);
        }
    }
}

} // namespace View