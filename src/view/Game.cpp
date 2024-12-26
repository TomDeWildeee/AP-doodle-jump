#include "../headers//view/Game.h"
namespace View {
Game::Game() : window(sf::VideoMode(800, 600), "Doodle Jump") {
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
    gameOverText.setPosition(400 - gameOverText.getGlobalBounds().width / 2,
                             300 - gameOverText.getGlobalBounds().height / 2);
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        //        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Game::render() {
    window.clear(sf::Color(135, 206, 235));

    window.draw(scoreText);
    if (isGameOver) {
        window.draw(gameOverText);
    }

    window.display();
}
} // namespace View