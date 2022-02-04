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
	TextWriter* tw2 = new TextWriter("First of all, you have to start from the middle of the board. That's the PINK square.", 17, this->gameFont, this->window->getWidth() / 2 - 150, this->startPosY + this->moveY);
	TextWriter* tw3 = new TextWriter("If you don't do that, you won't be able to place any letter on the board.", 17, this->gameFont, this->window->getWidth() / 2 - 150, this->startPosY + 2 * this->moveY);
	TextWriter* tw4 = new TextWriter("Also, we have different colors on the board.", 17, this->gameFont, this->window->getWidth() / 2 - 150, this->startPosY + 3 * this->moveY);
	TextWriter* tw5 = new TextWriter("That colors represent a bonus and I will describe them below.", 17, this->gameFont, this->window->getWidth() / 2 - 150, this->startPosY + 4 * this->moveY);
	TextWriter* tw6 = new TextWriter("The CYAN color will multiply the word's points by three.", 17, this->gameFont, this->window->getWidth() / 2 - 150, this->startPosY + 5 * this->moveY);
	TextWriter* tw7 = new TextWriter("The PINK color is the starting position.", 17, this->gameFont, this->window->getWidth() / 2 - 150, this->startPosY + 6 * this->moveY);
	TextWriter* tw8 = new TextWriter("The MAUVE color will multiply the word's points by two.", 17, this->gameFont, this->window->getWidth() / 2 - 150, this->startPosY + 7 * this->moveY);
	TextWriter* tw9 = new TextWriter("The LIGHT BLUE color will multiply the letter's points by two.", 17, this->gameFont, this->window->getWidth() / 2 - 150, this->startPosY + 8 * this->moveY);
	TextWriter* tw10 = new TextWriter("The NAVY BLUE color will multiply the letter's points by three.", 17, this->gameFont, this->window->getWidth() / 2 - 150, this->startPosY + 9 * this->moveY);

	this->messages.push_back(tw1);
	this->messages.push_back(tw2);
	this->messages.push_back(tw3);
	this->messages.push_back(tw4);
	this->messages.push_back(tw5);
	this->messages.push_back(tw6);
	this->messages.push_back(tw7);
	this->messages.push_back(tw8);
	this->messages.push_back(tw9);
	this->messages.push_back(tw10);
}

Guide::~Guide() {
	for (auto m : messages) {
		delete m;
	}
}