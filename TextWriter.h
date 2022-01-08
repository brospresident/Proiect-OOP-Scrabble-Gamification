#ifndef _TEXT_WRITER_
#define _TEXT_WRITER_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class TextWriter {
private:
	std::string message;
	sf::Font font;

public:
	sf::Text text;
	TextWriter(std::string message, unsigned int size, sf::Font font, float x, float y);

	TextWriter();

	// setters
	void setFont(sf::Font font);

	void setPosition(float x, float y);

	void setCharacterSize(unsigned int size);

	void setColorRed();

	void setColorBlue();

	void setColorGreen();

	void setColorBlack();

	void underline();

	void setItalic();

	void move(float x, float y);
};

#endif // !_TEXT_WRITER_