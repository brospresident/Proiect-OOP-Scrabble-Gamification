#include "Board.h"

Board::Board(Window* w, sf::Font& f, Texture& texture) {
	this->event = sf::Event();
	this->window = w;
	this->font = f;
	this->texture = texture;
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 15; ++j) {
			int id = 15 * i + j;
			Button* btn = new Button(id, "", "assets/buttons/1.jpg", this->startPosX + (j * this->rightMove), this->startPosY + (i * this->downMove), 20.0f, 20.0f, Misc::ButtonTypes::BUTTON_BOARD_SQUARE, f, w, texture);
			this->board[i][j] = btn;
		}
	}
}

void Board::initBoard() {
	
}

void Board::setEvent(sf::Event& event) {
	this->event = event;

	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 15; ++j) {
			this->board[i][j]->handleEvents(this->event);
		}
	}
}

void Board::drawBoard() {
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 15; ++j) {
			this->board[i][j]->drawButton();
		}
	}
}

Board::~Board() {
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 15; ++j) {
			delete this->board[i][j];
		}
	}
}

void Board::generateRandomCharList() {
	this->randomCharList = misc.randomCharList();
}

void Board::setBoardData() {
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 15; ++j) {
			this->boardData[i][j] = this->board[i][j]->getString();
		}
	}
}
