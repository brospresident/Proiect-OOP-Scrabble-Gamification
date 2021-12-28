#include "Board.h"

Board::Board(Window* w, sf::Font& f, Texture& texture) {
	this->event = sf::Event();
	this->window = w;
	this->font = f;
	this->texture = texture;

	for (int i = 0; i < 7; ++i) {
		int id = 245 + i;
		Button* btn = new Button(id, "", "assets/buttons/1.jpg", this->startPosX / 0.75 + (i * this->rightMove), this->startPosY / 2 + 10.0f, 20.0f, 20.0f, Misc::ButtonTypes::BUTTON_RANDOM_CHAR, f, w, texture);
		this->randomChars[i] = btn;
	}

	this->setRandomCharList();

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

	for (int i = 0; i < 7; ++i) {
		this->randomChars[i]->handleEvents(this->event);
	}

	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 15; ++j) {
			this->board[i][j]->handleEvents(this->event);
		}
	}

	this->handleBoardEvents();
}

void Board::drawBoard() {
	for (int i = 0; i < 7; ++i) {
		this->randomChars[i]->drawButton();
	}

	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 15; ++j) {
			this->board[i][j]->drawButton();
		}
	}
}

Board::~Board() {
	for (int i = 0; i < 7; ++i) {
		delete this->randomChars[i];
	}

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

int Board::checkButtonClicked() {
	for (int i = 0; i < 15; ++i) {
		if (i < 7 && this->randomChars[i]->clicked()) return this->randomChars[i]->getId();
		for (int j = 0; j < 15; ++j) {
			if (this->board[i][j]->clicked()) {
				return this->board[i][j]->getId();
			}
		}
	}
	return -1;
}

void Board::handleBoardEvents() {
	if (this->event.type == sf::Event::MouseButtonPressed) {
		int id = this->checkButtonClicked();
		if (id == -1) return;

		Button* clicked = this->findButtonById(id);

		if (this->lastBoardButtonClicked == nullptr) {
			this->lastBoardButtonClicked = clicked;
			return;
		}

		if (clicked->getType() == misc.BUTTON_RANDOM_CHAR && clicked->getString() != "") {
			this->lastBoardButtonClicked = clicked;
		}

		if (clicked->getType() == misc.BUTTON_BOARD_SQUARE && this->lastBoardButtonClicked->getType() == misc.BUTTON_RANDOM_CHAR && clicked->getString() == "") {
			clicked->setString(this->lastBoardButtonClicked->getString());
			this->lastBoardButtonClicked->setString("");
			this->lastBoardButtonClicked = clicked;
		}
	}
}

void Board::setRandomCharList() {
	this->generateRandomCharList();

	for (int i = 0; i < 7; ++i) {
		this->randomChars[i]->setString(this->randomCharList[i]);
	}
}

Button* Board::findButtonById(int id) {
	if (id > 244) {
		for (int i = 0; i < 7; ++i) {
			if (id == this->randomChars[i]->getId()) return this->randomChars[i];
		}
	}

	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 15; ++j) {
			if (id == this->board[i][j]->getId()) return this->board[i][j];
		}
	}

	return nullptr;
}
