#include <iostream>
#include "./Button.h"

Button::Button() {
	this->type = 0;
	this->x = 0.0f;
	this->y = 0.0f;
}

Button::Button(const std::string str, const std::string path, const float x, const float y, const float w, const float h, const int type, sf::Font font) {
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

	this->handleEvents();
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
	// std::cout << "To do the handle..." << std::endl;
}

// getters
sf::Sprite Button::getSprite() {
	return this->sprite;
}

TextWriter* Button::getTextWriter() {
	return this->tw;
}

bool Button::clicked() {

	return false;
}