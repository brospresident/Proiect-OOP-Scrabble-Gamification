#pragma once

#ifndef _BUTTON_
#define _BUTTON_

#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "TextWriter.h"
#include "Texture.h"

class Button : public Texture {
private:
	float x;
	float y;
	TextWriter* tw;
	sf::Sprite sprite;
	int type;

public:
	Button();
	Button(const std::string, const std::string, const float, const float, const float, const float, const int, const sf::Font);
	~Button();

	// getters
	sf::Sprite getSprite();
	TextWriter* getTextWriter();

	void setButtonPosition();
	void initSprite();

	void handleEvents();

	bool clicked();
};

#endif