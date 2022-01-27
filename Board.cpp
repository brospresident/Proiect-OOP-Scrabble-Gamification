#include "Board.h"

Board::Board(Window* w, sf::Font& f, std::vector<std::reference_wrapper<Texture>>& textures) {
	this->event = sf::Event();
	this->window = w;
	this->font = f;
	this->textures = textures;

	for (int i = 0; i < 7; ++i) {
		int id = 245 + i;
		Button* btn = new Button(id, "", this->startPosX / 0.75 + (i * this->rightMove), this->startPosY / 2 + 550.0f, 20.0f, 20.0f, Misc::ButtonTypes::BUTTON_RANDOM_CHAR, f, w, textures[9]);
		this->randomChars[i] = btn;
	}

	this->setRandomCharList();

	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 15; ++j) {
			int id = 15 * i + j;
			Button* btn;
			if ((i == 0 && j == 3) || (i == 0 && j == 0) || (i == 2 && j == 6) || (i == 2 && j == 8) || (i == 3 && j == 0) || (i == 3 && j == 7) || (i == 3 && j == 14)
				|| (i == 6 && j == 2) || (i == 6 && j == 6) || (i == 6 && j == 8) || (i == 6 && j == 12) || (i == 7 && j == 3) || (i == 7 && j == 11) || (i == 8 && j == 2)
				|| (i == 8 && j == 6) || (i == 8 && j == 8) || (i == 8 && j == 12) || (i == 11 && j == 0) || (i == 11 && j == 7) || (i == 11 && j == 14)
				|| (i == 12 && j == 6) || (i == 12 && j == 8) || (i == 14 && j == 3) || (i == 14 && j == 11)) {
				btn = new Button(id, "", this->startPosX + (j * this->rightMove), this->startPosY + (i * this->downMove), 20.0f, 20.0f, Misc::ButtonTypes::BUTTON_BOARD_SQUARE, f, w, textures[1]);
			}
			else if ((i == 1 && j == 5) || (i == 1 && j == 9) || (i == 5 && j == 1) || (i == 5 && j == 5) || (i == 5 && j == 9) || (i == 5 && j == 13) || (i == 9 && j == 1)
				|| (i == 9 && j == 5) || (i == 9 && j == 9) || (i == 9 && j == 13) || (i == 13 && j == 5) || (i == 13 && j == 9)) {
				btn = new Button(id, "", this->startPosX + (j * this->rightMove), this->startPosY + (i * this->downMove), 20.0f, 20.0f, Misc::ButtonTypes::BUTTON_BOARD_SQUARE, f, w, textures[2]);
			}
			else btn = new Button(id, "", this->startPosX + (j * this->rightMove), this->startPosY + (i * this->downMove), 20.0f, 20.0f, Misc::ButtonTypes::BUTTON_BOARD_SQUARE, f, w, textures[4]);
			this->board[i][j] = btn;
		}
	}

	for (int i = 0; i < 5; ++i) {
		this->board[i][i]->setTexture(textures[3]);
		this->board[14 - i][i]->setTexture(textures[3]);
	}
	for (int j = 10; j < 14; j++) {
		this->board[j][j]->setTexture(textures[3]);
		this->board[14 - j][j]->setTexture(textures[3]);
	}

	this->board[7][7]->setTexture(textures[5]);

	for (int i = 0; i < 15; i += 7)
		for (int j = 0; j < 15; j += 7)
			this->board[i][j]->setTexture(textures[6]);

	this->board[7][7]->setTexture(textures[5]);

	this->rerollButton = new Button(300, "REROLL", 820, 150, 140.0f, 30.0f, Misc::ButtonTypes::BUTTON_REROLL, f, w, textures[5]);
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

	this->rerollButton->handleEvents(this->event);

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

	this->rerollButton->drawButton();
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

	delete this->rerollButton;
}

void Board::generateRandomCharList() {
	this->randomCharList = misc.randomCharList();
}

void Board::setBoardData() {
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 15; ++j) {
			char letter = this->board[i][j]->getString().c_str()[0];
			this->boardData[i][j] = letter;
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

	if (this->rerollButton->clicked()) {
		return this->rerollButton->getId();
	}
	return -1;
}

void Board::handleBoardEvents() {
	if (this->event.type == sf::Event::MouseButtonPressed) {
		int id = this->checkButtonClicked();
		if (id == -1) return;

		Button* clicked = this->findButtonById(id);

		if (this->firstLetter == true && id == 112) this->firstLetter = false;
		if (this->firstLetter == true && id != 112 && clicked->getType() == misc.BUTTON_BOARD_SQUARE) return;

		// REROLL
		if (clicked->getType() == misc.BUTTON_REROLL) {
			this->setRandomCharList();
			return;
		}

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
			this->setBoardData();
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

	if (id == 300) return this->rerollButton;

	return nullptr;
}

void Board::printData() {
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 15; ++j) {
			std::cout << this->boardData[i][j] << " ";
		}
		std::cout << std::endl;
	}
}