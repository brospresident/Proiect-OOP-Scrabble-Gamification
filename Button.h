#pragma once

#ifndef _BUTTON_
#define _BUTTON_

#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "TextWriter.h"
#include "Texture.h"
#include "Window.h"

class Button : public Texture {
private:
	float x;
	float y;
	TextWriter* tw;
	sf::Sprite sprite;
	int type;
	sf::Vector2f knownMousePos;
	Window* window;

public:
	Button();
	Button(const std::string, const std::string, const float, const float, const float, const float, const int, const sf::Font, Window*);
	~Button();

	// getters
	sf::Sprite getSprite();
	TextWriter* getTextWriter();

	void setButtonPosition();
	void initSprite();

	void handleEvents();

	bool clicked();

	void drawButton();

	// setters
	void setKnownMousePos(sf::Vector2f);
};

#endif