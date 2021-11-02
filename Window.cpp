#include <iostream>
#include <SFML/Graphics.hpp>

#include "Window.h"

Window::Window(int width, int height) {
	this->width = width;
	this->height = height;
	this->window = new sf::RenderWindow(sf::VideoMode(this->width, this->height), "Scrabble Game");

	if (!this->window) {
		std::cout << "Failed to init the window... Terminating";
		exit(1);
	}
}

Window::Window() {
	this->width = 800;
	this->height = 600;
	this->window = new sf::RenderWindow(sf::VideoMode(this->width, this->height), "Scrabble Game");

	if (!this->window) {
		std::cout << "Failed to init the window... Terminating";
		exit(1);
	}
}

Window::~Window() {
	this->window->close();
}

void Window::drawText(sf::Text x) {
	this->window->draw(x);
}

bool Window::isOpen() {
	if (this->window->isOpen()) return true;
	return false;
}

void Window::display() {
	this->window->display();
}

void Window::clear() {
	this->window->clear();
}

float Window::getWidth() {
	return (float)this->width;
}

float Window::getHeight() {
	return (float)this->height;
}

sf::RenderWindow* Window::getWindow() {
	return this->window;
}
