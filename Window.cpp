#include <iostream>
#include <SFML/Graphics.hpp>

class Window {
private:
	// instanta de fereastra din SFML
	sf::RenderWindow* window;
	int width;
	int height;

public:
	Window(int width, int height) {
		this->width = width;
		this->height = height;
		this->window = new sf::RenderWindow(sf::VideoMode(this->width, this->height), "Scrabble Game");

		if (!this->window) {
			std::cout << "Failed to init the window... Terminating";
			exit(1);
		}
	}

	~Window() {
		this->window->close();
	}

	// Metoda care primeste referinta catre un text si il scrie pe ecran
	void drawText(sf::Text& x) {
		this->window->draw(x);
	}

	/*
	*	Metoda care verifica daca fereastra de SFML e inca deschisa
	*	@returns true daca e deschisa false daca nu mai e deschisa(folosim in gameloop)
	*/
	bool isOpen() {
		if (this->window->isOpen()) return true;
		return false;
	}

	// Metoda care apeleaza metoda display din SFML
	void display() {
		this->window->display();
	}

	void clear() {
		this->window->clear();
	}

	// getters
	float getWidth() {
		return (float)this->width;
	}

	float getHeight() {
		return (float)this->height;
	}

	sf::RenderWindow* getWindow() {
		return this->window;
	}
};