#include "Game.h"

Game::Game(Window* w, sf::Font& font, std::vector<std::reference_wrapper<Texture>> textures) {
	this->w = w;
	this->font = font;
	this->textures = textures;

	this->board = new Board(this->w, this->font, textures);

	this->timer = new Timer(font, w);
}

void Game::setEvent(sf::Event& ev, int& score) {
	this->ev = ev;

	this->board->setEvent(this->ev);
	this->board->drawBoard();

	score = this->sgInstance.checkBoard(this->board->boardData);

	this->timer->renderTimer();
}

void Game::resetTimer() {
	this->timer->getClock().restart();
}

Game::~Game() {
	delete this->timer;
}

