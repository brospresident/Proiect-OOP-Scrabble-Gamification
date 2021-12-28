#include <iostream>

#include <SFML/Graphics.hpp>

// Imports
#include "Window.h"
#include "TextWriter.h"
#include "Misc.h"
#include "Player.h"
#include "Button.h"
#include "Board.h"

int main() {
    // Creating the game window
    Window *window = new Window(1024, 768);
    Misc misc;

    int gamePhase = -1;

    // incarc fontul pe care il vom folosi in joc
    sf::Font gameFont;
    if (!gameFont.loadFromFile("lato.ttf")) {
        std::cout << "Failed to load the font... Check the path." << std::endl;
        return EXIT_FAILURE;
    }

    gamePhase = misc.GamePhases::RegisteringPlayer1;

    std::string playerName;

    Player player1;
    Player player2;

    bool shouldBeUpper = false;

    Texture squareTexture("assets/buttons/1.jpg", 0, 0, 0, 0);

    Board* gameBoard = new Board(window, gameFont, squareTexture);
    gameBoard->initBoard();

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

            // Handle for mouse clicks
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = window->getMousePosition();
                std::cout << "Mouse position(x, y): " << mousePos.x << " " << mousePos.y << std::endl;
            }

            if (event.type == sf::Event::KeyPressed) {
                // Registering the 1st player into the game
                if (gamePhase == misc.GamePhases::RegisteringPlayer1) {
                    std::string key;
                    if (shouldBeUpper == true) {
                        key = misc.toUpperCase(event.key.code);
                        shouldBeUpper = false;
                    }
                    else {
                        key = misc.keyCodeToString(event.key.code);
                    }
                    if (key.compare(misc.UNKNOWN_CHARACTER)) {
                        playerName.append(key);
                    }
                }

                // Registering the 2nd player into the game (DISCONTINUED -> Should remove)
                if (gamePhase == misc.GamePhases::RegisteringPlayer2) {
                    std::string key = misc.keyCodeToString(event.key.code);
                    if (key.compare(misc.UNKNOWN_CHARACTER)) {
                        playerName.append(key);
                    }
                }

                if (event.key.code == 38 || event.key.code == 42) {
                    shouldBeUpper = true;
                }

                // On press ENTER
                if (event.key.code == sf::Keyboard::Enter) {
                    if (gamePhase == misc.GamePhases::RegisteringPlayer1) {
                        player1 = Player(playerName, 0);
                    }
                    else if (gamePhase == misc.GamePhases::RegisteringPlayer2) {
                        player2 = Player(playerName, 1);
                    }
                    playerName.clear();
                    gamePhase += 2; // skip the 2nd player registration
                }
                // BACKSPACE functionality to remove a character when typing name
                else if (event.key.code == sf::Keyboard::BackSpace) {
                    if (gamePhase == misc.GamePhases::RegisteringPlayer1 || gamePhase == misc.GamePhases::RegisteringPlayer2) {
                        playerName = misc.removeLastCharacter(playerName);
                    }
                }

                // Close the game using ESC
                if (event.key.code == sf::Keyboard::Escape) {
                    window->~Window();
                }
            }
        }

        if (gamePhase >= 0) {
            if (gamePhase == misc.GamePhases::RegisteringPlayer1) {
                TextWriter playerNameInput("Please type in your name: ", 15, gameFont, window->getWidth() / 2, window->getHeight() / 4.0f);
                TextWriter inputPreview(playerName, 15, gameFont, window->getWidth() / 2, window->getHeight() / 3.0f);
                window->drawText(playerNameInput.text);
                window->drawText(inputPreview.text);
            }
            else if (gamePhase == misc.GamePhases::RegisteringPlayer2) {
                TextWriter playerNameInput("Please type player 2 name: ", 15, gameFont, window->getWidth() / 2, window->getHeight() / 4.0f);
                TextWriter inputPreview(playerName, 15, gameFont, window->getWidth() / 2, window->getHeight() / 3.0f);
                window->drawText(playerNameInput.text);
                window->drawText(inputPreview.text);
            }
            else if (gamePhase == misc.GamePhases::Playing) {
                std::vector<TextWriter*> d1 = player1.dataToString(gameFont, window->getWidth(), window->getHeight());

                window->drawText(d1[0]->text);
                window->drawText(d1[1]->text);

                gameBoard->setEvent(event);
                gameBoard->drawBoard();

                // After each iteration I free the memory
                // If I dont free the memory then it will reach a situation where it doesnt fit into the ram...
                for (auto x : d1) {
                    delete x;
                }
            }
            TextWriter gameTitle("Scrabble", 35, gameFont, window->getWidth() / 2, 5.0f);
            gameTitle.setColorRed();
            window->drawText(gameTitle.text);

            window->display();
        }
    }

    delete window;
    // delete gameBoard;

	return 0;
}