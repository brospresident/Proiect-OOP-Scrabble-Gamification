#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class TextWriter {
private:
	std::string message;
	sf::Font font;

public:
	sf::Text text;
	TextWriter(std::string message, unsigned int size, sf::Font font, float x, float y) {
		this->message = message;
		this->text.setCharacterSize(size);
		this->setFont(font);
		this->text.setFont(this->font);
		this->text.setString(this->message);
		this->setPosition(x, y);
	}

	// setters
	void setFont(sf::Font font) {
		this->font = font;
	}

	void setPosition(float x, float y) {
		this->text.setPosition(x, y);
	}

	void setCharacterSize(unsigned int size) {
		this->text.setCharacterSize(size);
	}

	void setColorRed() {
		this->text.setFillColor(sf::Color::Red);
	}
};