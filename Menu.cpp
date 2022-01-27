#include "Menu.h"

Menu::Menu(Window* window, sf::Font& font, std::vector<std::reference_wrapper<Texture>> textures) {
	this->window = window;
	this->font = font;

	this->buttons[0] = new Button(400, "Start Game", this->window->getWidth() / 2 - 100.0f, this->window->getHeight() / 2 - 60.0f, 200.0f, 40.0f, Misc::ButtonTypes::BUTTON_START_GAME, this->font, this->window, textures[5]);
	this->buttons[1] = new Button(400, "Guide", this->window->getWidth() / 2 - 100.0f, this->window->getHeight() / 2, 200.0f, 40.0f, Misc::ButtonTypes::BUTTON_SHOW_GUIDE, this->font, this->window, textures[5]);
	this->buttons[2] = new Button(400, "Top 5 players", this->window->getWidth() / 2 - 100.0f, this->window->getHeight() / 2 + 60.0f, 200.0f, 40.0f, Misc::ButtonTypes::BUTTON_SHOW_TOP, this->font, this->window, textures[5]);
}

void Menu::setEvent(sf::Event& event) {
	this->event = event;

	this->buttons[0]->handleEvents(this->event);
	this->buttons[1]->handleEvents(this->event);
	this->buttons[2]->handleEvents(this->event);

	this->renderMenu();
}

void Menu::renderMenu() {
	this->buttons[0]->drawButton();
	this->buttons[1]->drawButton();
	this->buttons[2]->drawButton();

}

int Menu::handleActions() {
	if (this->event.type == sf::Event::MouseButtonPressed) {
		if (this->buttons[0]->clicked() && this->buttons[0]->getType() == Misc::ButtonTypes::BUTTON_START_GAME) {
			return Misc::GamePhases::RegisteringPlayer1;
		}
		else if (this->buttons[1]->clicked() && this->buttons[1]->getType() == Misc::ButtonTypes::BUTTON_SHOW_GUIDE) {
			return Misc::GamePhases::ShowingHelp;
		}
		else if (this->buttons[2]->clicked() && this->buttons[2]->getType() == Misc::ButtonTypes::BUTTON_SHOW_TOP) {
			return Misc::GamePhases::ShowingTop;
		}
	}

	return Misc::GamePhases::Menu;
}

Menu::~Menu() {
	delete this->buttons[0], this->buttons[1], this->buttons[2];
}