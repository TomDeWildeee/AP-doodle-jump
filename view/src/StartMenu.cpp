#include "../include/StartMenu.h"
#include <SFML/Window/Event.hpp>
#include <fstream>

namespace View {

StartMenu::StartMenu() : window(sf::VideoMode(400, 800), "Doodle Jump Menu") {
    if (!font.loadFromFile("../../assets/DoodleJump.ttf")) {
        throw std::runtime_error("Could not load font");
    }

    std::ifstream file("highscore.txt");
    if (file.is_open()) {
        file >> highScore;
        file.close();
    } else {
        highScore = 0;
    }

    createButtons();

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                for (const auto& button : buttons) {
                    if (button.shape.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        if (button.isFramerateButton) {
                            selectedFramerate = button.framerate;
                        } else {
                            startGame = true;
                            window.close();
                        }
                    }
                }
            }
        }

        window.clear(sf::Color::Yellow);

        sf::Text title;
        title.setFont(font);
        title.setString("DOODLE JUMP");
        title.setCharacterSize(48);
        title.setFillColor(sf::Color::Black);
        title.setPosition((400 - title.getLocalBounds().width) / 2, 50);
        window.draw(title);

        sf::Text currentFPS;
        currentFPS.setFont(font);
        currentFPS.setString("Current FPS: " + std::to_string(selectedFramerate));
        currentFPS.setCharacterSize(24);
        currentFPS.setFillColor(sf::Color::Black);
        currentFPS.setPosition((400 - currentFPS.getLocalBounds().width) / 2, 150);

        sf::Text highScoreText;
        highScoreText.setFont(font);
        highScoreText.setString("Highscore: " + std::to_string(highScore));
        highScoreText.setCharacterSize(24);
        highScoreText.setFillColor(sf::Color::Black);
        highScoreText.setPosition((400 - highScoreText.getLocalBounds().width) / 2, 115);

        window.draw(currentFPS);
        window.draw(highScoreText);

        for (const auto& button : buttons) {
            window.draw(button.shape);
            window.draw(button.text);
        }

        window.display();
    }
}

void StartMenu::createButtons() {
    std::vector<int> framerates = {30, 60, 120, 144, 240};
    float buttonWidth = 200;
    float buttonHeight = 50;
    float spacing = 20;
    float startY = 200;

    // auto/int gave me a warning
    for (size_t i = 0; i < framerates.size(); i++) {
        Button button;
        button.shape.setSize(sf::Vector2f(buttonWidth, buttonHeight));
        button.shape.setPosition(100, startY + i * (buttonHeight + spacing));
        button.shape.setFillColor(sf::Color::White);
        button.shape.setOutlineThickness(2);
        button.shape.setOutlineColor(sf::Color::Black);

        button.text.setFont(font);
        button.text.setString(std::to_string(framerates[i]) + " FPS");
        button.text.setCharacterSize(24);
        button.text.setFillColor(sf::Color::Black);

        auto bounds = button.text.getLocalBounds();
        button.text.setPosition(100 + (buttonWidth - bounds.width) / 2,
                                startY + i * (buttonHeight + spacing) + (buttonHeight - bounds.height) / 2);

        button.isFramerateButton = true;
        button.framerate = framerates[i];

        buttons.push_back(button);
    }

    Button startButton;
    startButton.shape.setSize(sf::Vector2f(buttonWidth, buttonHeight));
    startButton.shape.setPosition(100, startY + framerates.size() * (buttonHeight + spacing) + spacing * 2);
    startButton.shape.setFillColor(sf::Color::Green);
    startButton.shape.setOutlineThickness(2);
    startButton.shape.setOutlineColor(sf::Color::Black);

    startButton.text.setFont(font);
    startButton.text.setString("Start Game");
    startButton.text.setCharacterSize(24);
    startButton.text.setFillColor(sf::Color::Black);

    auto bounds = startButton.text.getLocalBounds();
    startButton.text.setPosition(100 + (buttonWidth - bounds.width) / 2,
                                 startY + framerates.size() * (buttonHeight + spacing) + spacing * 2 +
                                     (buttonHeight - bounds.height) / 2);

    buttons.push_back(startButton);
}

int StartMenu::getSelectedFramerate() const { return selectedFramerate; }
bool StartMenu::shouldStartGame() const { return startGame; }

} // namespace View