#include "../headers//view/Game.h"
#include "../headers/logic/Score.h"
#include "../headers/logic/Stopwatch.h"
#include "../headers/view/BGTileView.h"
#include "../headers/view/BonusView.h"
#include "../headers/view/PlatformView.h"
#include <iostream>
namespace View {
Game::Game() : window(sf::VideoMode(480, 800), "Doodle Jump") {
    window.setFramerateLimit(144);

    if (!font.loadFromFile("../../assets/DoodleJump.ttf")) {
        throw std::runtime_error("Could not load font");
    }

    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::Red);

    gameOverText.setFont(font);
    gameOverText.setCharacterSize(48);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setString("Game Over!\nPress R to restart");
    gameOverText.setPosition(240 - gameOverText.getGlobalBounds().width / 2,
                             400 - gameOverText.getGlobalBounds().height / 2);

    factory = std::make_shared<ConcreteFactory>();
    score = std::make_shared<Logic::Score>();
    world = std::make_shared<Logic::World>(480, 800, factory, score);
    scoreText.setString("Score: 0");
    scoreText.setPosition(240 - scoreText.getGlobalBounds().width / 2, 0);

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
                world = std::make_shared<Logic::World>(480, 800, factory, score);
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
        int actualScore = score->getScore();
        float scoreSpeed = 1000.0f;

        if (displayedScore < actualScore) {
            displayedScore += static_cast<int>(scoreSpeed * Logic::Stopwatch::getInstance().getDeltaTime());
            if (displayedScore > actualScore) {
                displayedScore = actualScore;
            }
        }

        scoreText.setString("Score: " + std::to_string(displayedScore));

        float cameraY = world->getCamera().getY();
        if (world->getPlayer()->getCoords().second > cameraY + window.getSize().y / 2) {
            isGameOver = true;
            handleGameOver();
            return;
        }
    }
}

void Game::handleGameOver() {

    gameOverText.setString("Game Over!\nScore: " + std::to_string(score->getScore()) +
                           "\nHigh Score: " + std::to_string(score->getHighScore()) + "\nPress R to Restart");

    gameOverText.setPosition(240 - gameOverText.getGlobalBounds().width / 2,
                             400 - gameOverText.getGlobalBounds().height / 2);

    gameOverBackground.setSize(
        sf::Vector2f(gameOverText.getGlobalBounds().width + 40, gameOverText.getGlobalBounds().height + 40));

    gameOverBackground.setPosition(220 - gameOverText.getGlobalBounds().width / 2,
                                   400 - gameOverText.getGlobalBounds().height / 2);

    gameOverBackground.setOutlineColor(sf::Color::Black);
    gameOverBackground.setOutlineThickness(2.0f);
    gameOverBackground.setFillColor(sf::Color::White);

    displayedScore = 0;
    score->resetScore();
}

void Game::render() {
    window.clear();
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
        window.draw(gameOverBackground);
        window.draw(gameOverText);
    }

    window.display();
}
Game::~Game() = default;

} // namespace View