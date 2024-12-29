#include "../headers//view/Game.h"
#include "../headers/logic/Score.h"
#include "../headers/logic/Stopwatch.h"
#include "../headers/view/BGTileView.h"
#include "../headers/view/BonusView.h"
#include "../headers/view/PlatformView.h"
#include <iostream>
namespace View {
Game::Game() : window(sf::VideoMode(480, 800), "Doodle Jump") {
    window.setFramerateLimit(60);

    if (!font.loadFromFile("../../assets/DoodleJump.ttf")) {
        throw std::runtime_error("Could not load font");
    }

    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);

    gameOverText.setFont(font);
    gameOverText.setCharacterSize(48);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setString("Game Over!\nPress R to restart");
    gameOverText.setPosition(240 - gameOverText.getGlobalBounds().width / 2,
                             400 - gameOverText.getGlobalBounds().height / 2);

    factory = std::make_shared<ConcreteFactory>();
    world = std::make_shared<Logic::World>(480, 800, factory);

    gameController = std::make_unique<GameController>(world);

    Logic::Stopwatch::getInstance().start();
}

void Game::run() {
    while (window.isOpen()) {
        Logic::Stopwatch::getInstance().tick();
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::R && isGameOver) {
                world = std::make_shared<Logic::World>(480, 800, factory);
                gameController = std::make_unique<GameController>(world);
                isGameOver = false;
            }
        }

        if (!isGameOver) {
            gameController->handleInput(event);
        }
    }
}

void Game::update() {
    if (!isGameOver) {
        gameController->update();

        float cameraY = world->getCamera().getY();
        if (world->getPlayer()->getCoords().second > cameraY + window.getSize().y / 2) {
            isGameOver = true;
            handleGameOver();
            return;
        }
    }
}

void Game::handleGameOver() {
    Logic::Score& score = Logic::Score::getInstance();
    gameOverText.setString("Game Over!\nScore: " + std::to_string(score.getScore()) +
                           "\nHigh Score: " + std::to_string(score.getHighScore()) + "\nPress R to Restart");

    // Center the text
    gameOverText.setPosition(240 - gameOverText.getGlobalBounds().width / 2,
                             400 - gameOverText.getGlobalBounds().height / 2);
}

void Game::render() {
    window.clear(sf::Color(135, 206, 235));

    sf::View view = window.getDefaultView();
    Logic::Camera camera = world->getCamera();
    view.setCenter(240, camera.getY());
    window.setView(view);

    for (const auto& entityView : factory->getViews()) {
        entityView->draw(window);
    }

    window.setView(window.getDefaultView());

    window.draw(scoreText);
    if (isGameOver) {
        window.draw(gameOverText);
    }

    window.display();
}
} // namespace View