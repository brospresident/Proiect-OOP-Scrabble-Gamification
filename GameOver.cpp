#include "./GameOver.h"

GameOver::GameOver(Window* window, std::vector<std::reference_wrapper<Texture>> textures, sf::Font& font, Player player) : AbstractPage(window, textures, font) {
	this->font = font;
	this->player = player;
}

void GameOver::setEvent(sf::Event ev) {
	this->backButton->handleEvents(ev);
}

void GameOver::displayContent() {
	this->backButton->drawButton();
	TextWriter* gOver = new TextWriter("Game Over!", 25, this->font, this->window->getWidth() / 2, 250);
	gOver->underline();

	std::string msg = "Congratulations " + this->player.getPlayerName() + "! You scored " + std::to_string(this->player.getPlayerScore()) + "!";
	TextWriter* message = new TextWriter(msg, 20, this->font, this->window->getWidth() / 2 - 50, 300);

	this->window->drawText(gOver->text);
	this->window->drawText(message->text);

	delete gOver, message;
}