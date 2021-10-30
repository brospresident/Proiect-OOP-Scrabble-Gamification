#include <iostream>
#include <direct.h>

#include <SFML/Graphics.hpp>

// Imports
#include "Window.cpp"
#include "TextWriter.cpp"

int main() {
    // creez fereastra jocului
    Window *window = new Window(800, 600);

    // incarc fontul pe care il vom folosi in joc
    sf::Font gameFont;
    if (!gameFont.loadFromFile("lato.ttf")) {
        std::cout << "Failed to load the font... Check the path." << std::endl;
        return EXIT_FAILURE;
    }

    // gameloop
    while (window->isOpen()) {
        // definesc un event
        sf::Event event;

        // la fiecare event intampinat fac cate o actiune
        while (window->getWindow()->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->~Window();

            if (event.type == sf::Event::KeyPressed) {
                std::cout << "Key pressed: " << event.key.code << std::endl;
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                std::cout << "Mouse button clicked " << std::endl;
            }
        }

        // afisez ceva pe ecran
        window->getWindow()->clear();
        TextWriter* gameTitle = new TextWriter("Scrabble", 35, gameFont, window->getWidth() / 2, 5.0f);
        gameTitle->setColorRed();
        window->drawText(gameTitle->text);
        window->display();
        
        // bug fix cand se trece de o iteratie
        // practic la fiecare iteratie prin while era creat un nou obiect TextWriter unde scria scrabble
        // astfel memoria ocupata crestea exponential in cateva secunde 
        // textele se suprapuneau si ocupau memorie pana dadea crash
        // de retinut cand folosim TextWriter sa ii dam imediat delete dupa ce il afisam
        delete gameTitle;
    }

	return 0;
}