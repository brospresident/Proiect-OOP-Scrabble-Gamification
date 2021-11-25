#pragma once

#ifndef _WINDOW_
#define _WINDOW

#include <iostream>
#include <SFML/Graphics.hpp>

class Window {
private:
	// instanta de fereastra din SFML
	sf::RenderWindow* window;
	int width;
	int height;

public:
	Window(int width, int height);

	Window();

	~Window();

	// Metoda care primeste referinta catre un text si il scrie pe ecran
	void drawText(sf::Text x);

	// Metoda care primeste un sprite si il randeaza
	void drawSprite(sf::Sprite s);

	// Metoda care primeste un buton si il randeaza
	// void drawButton(Button& b);

	/*
	*	Metoda care verifica daca fereastra de SFML e inca deschisa
	*	@returns true daca e deschisa false daca nu mai e deschisa(folosim in gameloop)
	*/
	bool isOpen();

	// Metoda care apeleaza metoda display din SFML
	void display();

	void clear();

	// getters
	float getWidth();

	float getHeight();

	sf::RenderWindow* getWindow();

	// https://en.sfml-dev.org/forums/index.php?topic=21666.0
	/*
		Metoda care intoarce pozitia mouseului
		@returns mouse position as a Vector2f
	*/
	sf::Vector2f getMousePosition();
};

#endif // !_WINDOW_