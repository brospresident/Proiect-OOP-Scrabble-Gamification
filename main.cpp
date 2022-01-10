#include <iostream>

#include <SFML/Graphics.hpp>

// Imports
#include "Window.h"
#include "TextWriter.h"
#include "Misc.h"
#include "Player.h"
#include "Button.h"
#include "Game.h"
#include "Menu.h"

int main() {
    // Creating the game window
    Window *window = new Window(1024, 768);
    Misc misc;

    int gamePhase = -1;

    // Loading the font that we will use in the game
    sf::Font gameFont;
    if (!gameFont.loadFromFile("lato.ttf")) {
        std::cout << "Failed to load the font... Check the path." << std::endl;
        return EXIT_FAILURE;
    }

    gamePhase = misc.GamePhases::Menu;

    std::string playerName;

    Player player1;

    bool shouldBeUpper = false;

    // Loading the textures
    Texture middle("assets/buttons/1.jpg", 0, 0, 0, 0);

    Texture randomLetter("assets/textures/5.jpg", 0, 0, 0, 0);
    Texture doubleLetterTexture("assets/textures/1.jpg", 0, 0, 0, 0);
    Texture tripleLetterTexture("assets/textures/2.jpg", 0, 0, 0, 0);
    Texture doubleWordTexture("assets/textures/3.jpg", 0, 0, 0, 0);
    Texture classicTexture("assets/textures/4.jpg", 0, 0, 0, 0);
    Texture tripleWordsTexture("assets/textures/6.jpg", 0, 0, 0, 0);

    Texture gray("assets/textures/gray.jpg", 0, 0, 0, 0);

    Texture background("assets/textures/game_background.jpg", 0, 0, 0, 0);
    sf::Sprite backgroundSprite(background.texture);

    std::vector<std::reference_wrapper<Texture>> textures;
    textures.push_back(randomLetter);
    textures.push_back(doubleLetterTexture);
    textures.push_back(tripleLetterTexture);
    textures.push_back(doubleWordTexture);
    textures.push_back(classicTexture);
    textures.push_back(middle);
    textures.push_back(tripleWordsTexture);
    textures.push_back(gray);

    // Creating a game instance
    Game* gameInstance = new Game(window, gameFont, textures);

    Menu gameMenu = Menu(window, gameFont, textures);

    // gameloop
    while (window->isOpen()) {
        // Clear the window, should happen on every iteration of the gameloop
        window->clear();

        // Here I set the background for the background for the game.
        // Should be done on phases and depending on the menu rerender what background is needed
        backgroundSprite.setTextureRect(sf::IntRect(0, 0, window->getWidth(), window->getHeight()));
        window->drawSprite(backgroundSprite);
        // dDefining the event
        sf::Event event;

        // Do an action every time there happens an event
        while (window->getWindow()->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->~Window();

            // Handle for mouse clicks
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = window->getMousePosition();
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

                if (event.key.code == 38 || event.key.code == 42) {
                    shouldBeUpper = true;
                }

                // On press ENTER
                if (event.key.code == sf::Keyboard::Enter) {
                    if (gamePhase == misc.GamePhases::RegisteringPlayer1) {
                        player1 = Player(playerName, 0);
                    }
                    playerName.clear();
                    if (gamePhase == misc.GamePhases::RegisteringPlayer1) 
                        gamePhase = misc.GamePhases::Playing;
                }
                // BACKSPACE functionality to remove a character when typing name
                else if (event.key.code == sf::Keyboard::BackSpace) {
                    if (gamePhase == misc.GamePhases::RegisteringPlayer1) {
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
            if (gamePhase == misc.GamePhases::Menu) {
                gameMenu.setEvent(event);
                gamePhase = gameMenu.handleActions();

                gameInstance->resetTimer();
            }
            else if (gamePhase == misc.GamePhases::RegisteringPlayer1) {
                TextWriter playerNameInput("Please type in your name: ", 15, gameFont, window->getWidth() / 2, window->getHeight() / 4.0f);
                TextWriter inputPreview(playerName, 15, gameFont, window->getWidth() / 2, window->getHeight() / 3.0f);
                window->drawText(playerNameInput.text);
                window->drawText(inputPreview.text);
                gameInstance->resetTimer();
            }
            else if (gamePhase == misc.GamePhases::Playing) {
                std::vector<TextWriter*> d1 = player1.dataToString(gameFont, window->getWidth(), window->getHeight());

                window->drawText(d1[0]->text);
                window->drawText(d1[1]->text);

                int score = 0;
                gameInstance->setEvent(event, score);
                player1.setPlayerScore(score);

                // After each iteration I free the memory
                // If I dont free the memory then it will reach a situation where it doesnt fit into the ram...
                for (auto x : d1) {
                    delete x;
                }
            }
            TextWriter gameTitle("Scrabble", 35, gameFont, window->getWidth() / 2 - 15.0f, 5.0f);
            gameTitle.setColorRed();
            window->drawText(gameTitle.text);

            window->display();
        }
    }

    delete window;
    delete gameInstance;
    // delete gameBoard;

	return 0;
}