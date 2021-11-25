#include <iostream>
#include "./Button.h"
#include "Misc.h"

Button::Button() {
	this->type = 0;
	this->x = 0.0f;
	this->y = 0.0f;
}

Button::Button(const std::string str, const std::string path, const float x, const float y, const float w, const float h, const int type, sf::Font font, Window* window) {
	tw = new TextWriter(str, 10, font, x + 5, y + 5);
	this->x = x;
	this->y = y;
	this->type = type;

	this->setPath(path);
	this->setPosX(x);
	this->setPosY(y);
	this->setWidth(w);
	this->setHeight(h);

	this->loadTexture();
	this->initSprite();

	this->window = window;

	//this->handleEvents();

	this->drawButton();
	this->knownMousePos = sf::Vector2f(0, 0);
}

Button::~Button() {
	delete this->tw;
}

/*
	Ar trebui facut sa aiba handle de exceptii sa nu il initializeze aiurea
*/
void Button::setButtonPosition() {
	if (this->x && this->y) {
		this->sprite.setPosition(x, y);
		return;
	}

	std::cout << "Failed to init the button" << std::endl;
}

void Button::initSprite() {
	this->sprite = sf::Sprite(this->texture);
	this->setButtonPosition();
}

void Button::handleEvents() {
	sf::Event e;
	bool ev = this->window->getWindow()->pollEvent(e);
	if (e.type == sf::Event::MouseButtonPressed) {
		sf::Vector2f mousePos = this->window->getMousePosition();

		this->setKnownMousePos(mousePos);

		if (this->clicked()) {
			if (this->type == Misc::ButtonTypes::BUTTON_BOARD_SQUARE) {
				std::cout << "A board square was pressed!" << std::endl;
			}
			else if (this->type == Misc::ButtonTypes::BUTTON_FINISH_TURN) {
				std::cout << "The finish turn button was pressed" << std::endl;
			}
		}
	}
}

// getters
sf::Sprite Button::getSprite() {
	return this->sprite;
}

TextWriter* Button::getTextWriter() {
	return this->tw;
}

bool Button::clicked() {
	if (this->sprite.getGlobalBounds().contains(this->knownMousePos)) return true;
	return false;
}

// setters
void Button::setKnownMousePos(sf::Vector2f mousePos) {
	this->knownMousePos.x = mousePos.x;
	this->knownMousePos.y = mousePos.y;
}

void Button::drawButton() {
	this->window->drawSprite(this->getSprite());
	this->window->drawText(this->getTextWriter()->text);
}