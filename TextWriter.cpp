#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "TextWriter.h"

TextWriter::TextWriter(std::string message, unsigned int size, sf::Font font, float x, float y) {
	this->message = message;
	this->text.setCharacterSize(size);
	this->setFont(font);
	this->text.setFont(this->font);
	this->text.setString(this->message);
	this->setPosition(x, y);
}

TextWriter::TextWriter() {}

// setters
void TextWriter::setFont(sf::Font font) {
	this->font = font;
}

void TextWriter::setPosition(float x, float y) {
	this->text.setPosition(x, y);
}

void TextWriter::setCharacterSize(unsigned int size) {
	this->text.setCharacterSize(size);
}

void TextWriter::setColorRed() {
	this->text.setFillColor(sf::Color::Red);
}

void TextWriter::setColorBlue() {
	this->text.setFillColor(sf::Color::Blue);
}

void TextWriter::setColorGreen() {
	this->text.setFillColor(sf::Color::Green);
}

void TextWriter::setColorBlack() {
	this->text.setFillColor(sf::Color::Black);
}

void TextWriter::underline() {
	this->text.setStyle(sf::Text::Underlined);
}

void TextWriter::setItalic() {
	this->text.setStyle(sf::Text::Italic);
}

void TextWriter::move(float x, float y) {
	this->text.move(x, y);
}