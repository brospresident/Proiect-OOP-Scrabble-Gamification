#include "AbstractPage.h"

AbstractPage::AbstractPage(Window* window, std::vector<std::reference_wrapper<Texture>> textures, sf::Font& font) {
	this->textures = textures;
	this->window = window;
	this->backButton = new Button(900, "BACK", this->window->getWidth() / 2 - 60.f, 600, 150.f, 30.f, Misc::ButtonTypes::BUTTON_BACK, font, this->window, this->textures[5]);
}

int AbstractPage::handleClick() {
	if (this->backButton->clicked()) {
		return Misc::GamePhases::Menu;
	}

	return Misc::GamePhases::ShowingHelp;
}

AbstractPage::~AbstractPage() {
	delete this->backButton;
}