#include "./Guide.h"

Guide::Guide(Window* window, std::vector<std::reference_wrapper<Texture>> textures, sf::Font& font) : AbstractPage(window, textures, font) {
	this->gameFont = font;
	this->createTexts();
}

void Guide::setEvent(sf::Event ev) {
	this->backButton->handleEvents(ev);

	this->displayContent();
}

void Guide::displayContent() {
	this->backButton->drawButton();

	for (auto text : messages) {
		this->window->drawText(text->text);
	}
}

void Guide::createTexts() {
	TextWriter* tw1 = new TextWriter("Hello! This is a guide for you to understand how our game works!", 17, this->gameFont, this->window->getWidth() / 2 - 150, this->startPosY);
	TextWriter* tw2 = new TextWriter("First of all, you have to start from the middle of the board. That's the pink square.", 17, this->gameFont, this->window->getWidth() / 2 - 150, this->startPosY + this->moveY);
	TextWriter* tw3 = new TextWriter("If you don't do that, you won't be able to place any letter on the board.", 17, this->gameFont, this->window->getWidth() / 2 - 150, this->startPosY + 2 * this->moveY);
	TextWriter* tw4 = new TextWriter("Also, we have different colors on the board.", 17, this->gameFont, this->window->getWidth() / 2 - 150, this->startPosY + 3 * this->moveY);
	TextWriter* tw5 = new TextWriter("That colors represent a bonus and I will describe them below.", 17, this->gameFont, this->window->getWidth() / 2 - 150, this->startPosY + 4 * this->moveY);

	this->messages.push_back(tw1);
	this->messages.push_back(tw2);
	this->messages.push_back(tw3);
	this->messages.push_back(tw4);
	this->messages.push_back(tw5);
}

Guide::~Guide() {
	for (auto m : messages) {
		delete m;
	}
}