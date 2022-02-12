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
	TextWriter* credits = new TextWriter("This application was developed by the following students from University POLITEHNICA Bucharest /", 15, this->font, this->window->getWidth() / 2 - 450, 300);
	TextWriter* credits1 = new TextWriter("Automatic Control & Computer Science Faculty within the Erasmus+ Project 2020-1-CZ01-KA226-HE-094408 :", 15, this->font, this->window->getWidth() / 2 - 450, 320);
	TextWriter* credits2 = new TextWriter("Radu Andrei", 15, this->font, this->window->getWidth() / 2 - 400, 350);
	TextWriter* credits3 = new TextWriter("Badoi Iulia-Bianca", 15, this->font, this->window->getWidth() / 2 - 400, 370);
	TextWriter* credits4 = new TextWriter("Popescu David", 15, this->font, this->window->getWidth() / 2 - 400, 390);
	TextWriter* credits5 = new TextWriter("Iordache Elena-Alexandra", 15, this->font, this->window->getWidth() / 2 - 400, 410);
	TextWriter* credits6 = new TextWriter("Apostolescu Mihnea", 15, this->font, this->window->getWidth() / 2 - 400, 430);
	TextWriter* credits7 = new TextWriter("Raceanu Andrei", 15, this->font, this->window->getWidth() / 2 - 400, 450);
	TextWriter* credits8 = new TextWriter("Teachers: M. Caramihai & Daniel Chis", 15, this->font, this->window->getWidth() / 2 - 450, 470);
	TextWriter* credits9 = new TextWriter("Project title: BOOSTING SUSTAINABLE DIGITAL EDUCATION FOR EUROPEAN UNIVERSITIES", 17, this->font, this->window->getWidth() / 2 - 400, 250);
	TextWriter* credits10 = new TextWriter("CREDITS", 100, this->font, this->window->getWidth() / 2 - 200, 100);

	
	this->window->drawText(credits->text);
	this->window->drawText(credits1->text);
	this->window->drawText(credits2->text); 
	this->window->drawText(credits3->text); 
	this->window->drawText(credits4->text);
	this->window->drawText(credits5->text);
	this->window->drawText(credits6->text);
	this->window->drawText(credits7->text);
	this->window->drawText(credits8->text);
	this->window->drawText(credits9->text); 
	this->window->drawText(credits10->text);

	this->backButton->drawButton();

	delete credits;
}