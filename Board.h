#ifndef _BOARD_
#define _BOARD_

#include "Button.h"
#include "Misc.h"
#include <vector>

class Board {
private:
	double startPosX = 350;
	double startPosY = 120.0f;
	double rightMove = 28.0f;
	double downMove = 28.0f;
	Button* board[15][15];
	Window* window;
	sf::Event event;
	Texture texture;
	sf::Font font;
	std::vector<std::string> randomCharList;
	Misc misc;
	std::string boardData[15][15];

public:
	Board(Window*, sf::Font&, Texture&);
	~Board();

	void initBoard();

	//getters and setters
	void setEvent(sf::Event& event);
	void drawBoard();
	void generateRandomCharList();
	void setBoardData();
};

#endif