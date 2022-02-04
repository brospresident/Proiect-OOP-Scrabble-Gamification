#include "Credits.h"

Credits::Credits(Window* window, std::vector<std::reference_wrapper<Texture>> textures, sf::Font& font) : AbstractPage(window, textures, font) {
	this->font = font;
	this->window = window;
}

int Credits::handleClick() {
	if (this->backButton->clicked()) {
		return Misc::GamePhases::Menu;
	}

	return Misc::GamePhases::Credits;
}

void Credits::setEvent(sf::Event ev) {
	this->backButton->handleEvents(ev);

	this->displayContent();
}

void Credits::displayContent() {
	TextWriter* credits = new TextWriter("Credits", 25, this->font, this->window->getWidth() / 2, 250);
	credits->underline();
	this->window->drawText(credits->text);

	this->backButton->drawButton();

	delete credits;
}