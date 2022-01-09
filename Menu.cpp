#include "Menu.h"

Menu::Menu(Window* window, sf::Font& font, std::vector<std::reference_wrapper<Texture>> textures) {
	this->window = window;
	this->font = font;

	buttons[0] = new Button(400, "Start Game", this->window->getWidth() / 2 - 30.0f, this->window->getHeight() / 2 - 160.0f, 200.0f, 40.0f, Misc::ButtonTypes::BUTTON_START_GAME, this->font, this->window, textures[7]);
	buttons[1] = new Button(400, "Guide", this->window->getWidth() / 2 - 30.0f, this->window->getHeight() / 2 - 90.0f, 200.0f, 40.0f, Misc::ButtonTypes::BUTTON_START_GAME, this->font, this->window, textures[7]);
}

void Menu::setEvent(sf::Event& event) {
	this->event = event;

	buttons[0]->handleEvents(this->event);
	buttons[1]->handleEvents(this->event);

	this->renderMenu();
}

void Menu::renderMenu() {
	buttons[0]->drawButton();
	buttons[1]->drawButton();
}

int Menu::handleActions() {
	if (this->event.type == sf::Event::MouseButtonPressed) {
		if (this->buttons[0]->clicked() && this->buttons[0]->getType() == Misc::ButtonTypes::BUTTON_START_GAME) {
			return Misc::GamePhases::RegisteringPlayer1;
		}
	}

	return Misc::GamePhases::Menu;
}

Menu::~Menu() {
	delete this->buttons[0], this->buttons[1];
}
