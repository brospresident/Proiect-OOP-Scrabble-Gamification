#include <iostream>

#include <SFML/Graphics.hpp>

// Imports
#include "Window.h"
#include "TextWriter.h"
#include "Misc.h"
#include "Player.h"

int main() {
    // creez fereastra jocului
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
                // Registering the 1st player into the game
                if (gamePhase == misc.GamePhases::RegisteringPlayer1) {
                    std::string key = misc.keyCodeToString(event.key.code);
                    if (key.compare(misc.UNKNOWN_CHARACTER)) {
                        playerName.append(key);
                    }
                }

                // Registering the 2nd player into the game
                if (gamePhase == misc.GamePhases::RegisteringPlayer2) {
                    std::string key = misc.keyCodeToString(event.key.code);
                    if (key.compare(misc.UNKNOWN_CHARACTER)) {
                        playerName.append(key);
                    }
                }

                // On press ENTER
                if (event.key.code == sf::Keyboard::Enter) {
                    if (gamePhase == misc.GamePhases::RegisteringPlayer1) {
                        player1 = Player(playerName, 0);
                    }
                    else if (gamePhase == misc.GamePhases::RegisteringPlayer2) {
                        player2 = Player(playerName, 1);
                        std::cout << "DEBUG: Player2 name: " << player2.getPlayerName() << "\n";
                    }
                    playerName.clear();
                    gamePhase++;
                }

                // Close the game using ESC
                if (event.key.code == sf::Keyboard::Escape) {
                    window->~Window();
                }

                // Handle for mouse clicks
                if (event.type == sf::Event::MouseButtonPressed) {
                    std::cout << "Mouse button clicked " << std::endl;
                }
            }
        }

        if (gamePhase >= 0) {
            if (gamePhase == misc.GamePhases::RegisteringPlayer1) {
                TextWriter playerNameInput("Please type player 1 name: ", 15, gameFont, window->getWidth() / 2, window->getHeight() / 4.0f);
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
                std::vector<TextWriter*> d2 = player2.dataToString(gameFont, window->getWidth(), window->getHeight());

                window->drawText(d1[0]->text);
                window->drawText(d1[1]->text);
                window->drawText(d2[0]->text);
                window->drawText(d2[1]->text);

                // After each iteration I free the memory
                // If I dont free the memory then it will reach a situation where it doesnt fit into the ram...
                for (auto x : d1) {
                    delete x;
                }

                for (auto x : d2) {
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

	return 0;
}