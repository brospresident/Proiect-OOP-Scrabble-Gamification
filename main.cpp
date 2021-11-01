#include <iostream>
#include <direct.h>

#include <SFML/Graphics.hpp>

// Imports
#include "Window.cpp"
#include "TextWriter.cpp"
#include "Misc.cpp"
#include "Player.cpp"

int main() {
    // creez fereastra jocului
    Window *window = new Window(800, 600);

    int gamePhase = -1;

    // incarc fontul pe care il vom folosi in joc
    sf::Font gameFont;
    if (!gameFont.loadFromFile("lato.ttf")) {
        std::cout << "Failed to load the font... Check the path." << std::endl;
        return EXIT_FAILURE;
    }

    gamePhase = GamePhases::RegisteringPlayer1;

    // gameloop
    while (window->isOpen()) {
        // fac clear la window. Trebuie facut clear la fiecare iteratie
        window->clear();
        // definesc un event
        sf::Event event;

        // la fiecare event intampinat fac cate o actiune
        while (window->getWindow()->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->~Window();

            if (event.type == sf::Event::KeyPressed) {
                std::cout << "Key pressed: " << event.key.code << std::endl;
                if (gamePhase == GamePhases::RegisteringPlayer1) {

                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                std::cout << "Mouse button clicked " << std::endl;
            }
        }

        if (gamePhase >= 0) {
            Player player1;
            Player player2;
            TextWriter playerNameInput("Please type your name: ", 15, gameFont, window->getWidth() / 2, window->getHeight() / 4);

            if (gamePhase == GamePhases::RegisteringPlayer1) {
                window->drawText(playerNameInput.text);
                
            }

            TextWriter gameTitle("Scrabble", 35, gameFont, window->getWidth() / 2, 5.0f);
            gameTitle.setColorRed();
            window->drawText(gameTitle.text);

            window->display();
        }
    }

    delete window;

	return 0;
}