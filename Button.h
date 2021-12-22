#pragma once

#ifndef _BUTTON_
#define _BUTTON_

#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "TextWriter.h"
#include "Texture.h"
#include "Window.h"

class Button {
private:
	int id;
	float x;
	float y;
	float h;
	float w;
	TextWriter* tw;
	sf::Sprite sprite;
	int type;
	sf::Vector2f knownMousePos;
	Window* window;
	Texture texture;
	std::string str;

public:
	Button();
	Button(const int, const std::string, const std::string, const float, const float, const float, const float, const int, const sf::Font, Window*, Texture);
	~Button();

	// getters
	sf::Sprite& getSprite();
	TextWriter* getTextWriter();
	int getId();
	std::string getString();
	void setButtonPosition();
	void initSprite();

	void handleEvents(sf::Event& e);

	bool clicked();

	void drawButton();

	// setters
	void setKnownMousePos(sf::Vector2f);
	void setId(int id);
	void setString(std::string str);
};

#endif