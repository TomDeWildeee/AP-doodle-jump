#include <utility>

#include "../headers/view/GameController.h"

namespace View {

GameController::GameController(std::shared_ptr<Logic::World> world) : world(std::move(world)) {}

void GameController::update() {
    if (gameOver)
        return;

    world->update();
    std::shared_ptr<Logic::Player> player = world->getPlayer();
    if (player && player->getCoords().second > 600) {
        gameOver = true;
    }
}

void GameController::handleInput(const sf::Event& event) {
    if (gameOver)
        return;

    std::shared_ptr<Logic::Player> player = world->getPlayer();
    if (!player)
        return;

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