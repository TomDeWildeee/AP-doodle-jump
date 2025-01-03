/**
 * @file StartMenu.h
 * @brief Manages game start menu interface
 */

#ifndef DOODLE_JUMP_STARTMENU_H
#define DOODLE_JUMP_STARTMENU_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
namespace View {

/**
 * @class StartMenu
 * @brief Handles start menu display and interaction
 */
class StartMenu {
public:
    StartMenu();

    /**
     * @brief Gets selected framerate
     * @return Selected framerate value
     */
    int getSelectedFramerate() const;

    /**
     * @brief Checks if game should start
     * @return True if game should start
     */
    bool shouldStartGame() const;

private:
    sf::RenderWindow window;
    sf::Font font;
    int selectedFramerate = 60;
    int highScore = 0;
    bool startGame = false;

    /**
     * @struct Button
     * @brief Represents a clickable menu button
     */
    struct Button {
        sf::RectangleShape shape;
        sf::Text text;
        bool isFramerateButton = false;
        int framerate = 60;
    };

    std::vector<Button> buttons;

    /**
     * @brief Creates and initializes menu buttons
     */
    void createButtons();
};
} // namespace View

#endif // DOODLE_JUMP_STARTMENU_H
