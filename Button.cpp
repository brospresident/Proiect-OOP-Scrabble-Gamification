#include <iostream>
#include "./Button.h"
#include "Misc.h"

Button::Button() {
	this->type = -1;
	this->x = 0.0f;
	this->y = 0.0f;
}

Button::Button(const int id, const std::string str, const std::string path, const float x, const float y, const float w, const float h, const int type, sf::Font font, Window* window, Texture texture) {
	this->id = id;
	this->tw = new TextWriter(str, 12, font, x + 5, y + 2);
	this->x = x;
	this->y = y;
	this->h = h;
	this->w = w;
	this->type = type;
	this->texture = texture;
	this->str = str;

	this->texture.setPosX(x);
	this->texture.setPosX(y);
	this->texture.setHeight(h);
	this->texture.setWidth(w);

	this->initSprite();

	this->window = window;

	//this->handleEvents();

	//this->drawButton();
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
	this->sprite = sf::Sprite(this->texture.texture);
	this->sprite.setTextureRect(sf::IntRect(this->x, this->y, this->w, this->h));
	this->setButtonPosition();
}

void Button::handleEvents(sf::Event& e) {
	if (e.type == sf::Event::MouseButtonPressed) {
		sf::Vector2f mousePos = this->window->getMousePosition();

		this->setKnownMousePos(mousePos);
	}
	else if (e.type == sf::Event::MouseMoved) {

	}
}

// getters
sf::Sprite& Button::getSprite() {
	return this->sprite;
}

TextWriter* Button::getTextWriter() {
	return this->tw;
}

bool Button::clicked() {
	if (this->sprite.getGlobalBounds().contains(this->knownMousePos)) return true;
	return false;
}

int Button::getId() {
	return this->id;
}

std::string Button::getString() {
	return this->str;
}

int Button::getType() {
	return this->type;
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

void Button::setId(int id) {
	this->id = id;
}

void Button::setString(std::string str) {
	this->str = str;
	this->tw->text.setString(this->str);
}

bool Button::isEmpty() {
	return this->str == "";
}