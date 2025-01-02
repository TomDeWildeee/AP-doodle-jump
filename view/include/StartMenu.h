#ifndef DOODLE_JUMP_STARTMENU_H
#define DOODLE_JUMP_STARTMENU_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
namespace View {

class StartMenu {
public:
    StartMenu();
    int getSelectedFramerate() const;
    bool shouldStartGame() const;

private:
    sf::RenderWindow window;
    sf::Font font;
    int selectedFramerate = 60;
    bool startGame = false;

    struct Button {
        sf::RectangleShape shape;
        sf::Text text;
        bool isFramerateButton = false;
        int framerate = 60;
    };

    std::vector<Button> buttons;
    void createButtons();
};
} // namespace View

#endif // DOODLE_JUMP_STARTMENU_H
