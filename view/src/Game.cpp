#include "../include/Game.h"
#include "../../logic/include/Stopwatch.h"
#include "../include/BGTileView.h"
#include "../include/PlatformView.h"
#include "GameException.h"

namespace View {
Game::Game(int frameRate) : window(sf::VideoMode(480, 800), "Doodle Jump") {

    // Set frame rate limit
    window.setFramerateLimit(frameRate);

    // Load font and throw exception if it fails
    if (!font.loadFromFile("../../assets/DoodleJump.ttf")) {
        throw Logic::ResourceLoadException("DoodleJump.ttf");
    }

    // Set score text properties
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::Red);

    // Set game over text properties and position
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(48);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setString("Game Over!\nPress R to restart");
    gameOverText.setPosition(window.getSize().x / 2 - gameOverText.getGlobalBounds().width / 2,
                             window.getSize().y / 2 - gameOverText.getGlobalBounds().height / 2);

    // Create factory, score, and world objects
    factory = std::make_shared<ConcreteFactory>();
    score = std::make_shared<Logic::Score>();
    world = std::make_shared<Logic::World>(480, 800, factory);

    // Attach score observer to player
    world->getPlayer()->attachScoreObserver(score);

    // Set score to right position
    scoreText.setString("Score: 0");
    scoreText.setPosition(window.getSize().x / 2 - scoreText.getGlobalBounds().width / 2, 0);

    // Create game controller object
    gameController = std::make_unique<GameController>(world);

    // Start the stopwatch
    Logic::Stopwatch::getInstance().start();
}

void Game::run() {
    // Main game loop that processes events, updates, and renders
    while (window.isOpen()) {
        // Tick the stopwatch
        Logic::Stopwatch::getInstance().tick();
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event{};

    // Process events
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::R && isGameOver) {

                // Reset game state if game is over and R is pressed
                world = std::make_shared<Logic::World>(480, 800, factory);
                world->getPlayer()->attachScoreObserver(score);
                gameController = std::make_unique<GameController>(world);
                isGameOver = false;
            }
        }

        // Handle input if game is not over
        if (!isGameOver) {
            gameController->handleInput(event);
        }
    }
}

void Game::update() {
    if (!isGameOver) {
        // Update game controller by updating the world
        gameController->update();

        // Get actual score
        int actualScore = score->getScore();
        float scoreSpeed = 1000.0f;

        // Linearly interpolate displayed score to actual score
        if (displayedScore < actualScore) {
            displayedScore += (int)(scoreSpeed * Logic::Stopwatch::getInstance().getDeltaTime());
            if (displayedScore > actualScore) {
                displayedScore = actualScore;
            }
        } else if (displayedScore > actualScore) {
            displayedScore -= (int)(scoreSpeed * Logic::Stopwatch::getInstance().getDeltaTime());
            if (displayedScore < actualScore) {
                displayedScore = actualScore;
            }
        }

        scoreText.setString("Score: " + std::to_string(displayedScore));

        // Handle game over if player is below camera view
        float cameraY = world->getCamera().getY();
        if (world->getPlayer()->getCoords().second > cameraY + window.getSize().y / 2) {
            isGameOver = true;
            handleGameOver();
            return;
        }
    }
}

void Game::handleGameOver() {

    // Set game over text properties and position

    gameOverText.setString("Game Over!\nScore: " + std::to_string(score->getScore()) +
                           "\nHigh Score: " + std::to_string(score->getHighScore()) + "\nPress R to Restart");

    gameOverText.setPosition(window.getSize().x / 2 - gameOverText.getGlobalBounds().width / 2,
                             window.getSize().y / 2 - gameOverText.getGlobalBounds().height / 2);

    gameOverBackground.setSize(
        sf::Vector2f(gameOverText.getGlobalBounds().width + 40, gameOverText.getGlobalBounds().height + 40));

    gameOverBackground.setPosition((window.getSize().x / 2 - 20) - gameOverText.getGlobalBounds().width / 2,
                                   (window.getSize().y / 2) - gameOverText.getGlobalBounds().height / 2);

    gameOverBackground.setOutlineColor(sf::Color::Black);
    gameOverBackground.setOutlineThickness(2.0f);
    gameOverBackground.setFillColor(sf::Color::White);

    // Reset displayed score and reset score
    displayedScore = 0;
    score->resetScore();
}

void Game::render() {

    // Clear window and set view to camera view
    window.clear();
    sf::View view = window.getDefaultView();

    // Get camera and set view center to camera y position
    Logic::Camera camera = world->getCamera();
    view.setCenter(window.getSize().x / 2, camera.getY());
    window.setView(view);

    // Draw views for each entity
    for (const auto& entityView : factory->getViews()) {
        entityView->draw(window);
    }

    // Set view back to default view and draw score text and game over text if game is over
    window.setView(window.getDefaultView());

    // Draw score text and game over text if game is game over
    window.draw(scoreText);
    if (isGameOver) {
        window.draw(gameOverBackground);
        window.draw(gameOverText);
    }

    // Finally display the window
    window.display();
}
Game::~Game() = default;

} // namespace View