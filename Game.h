#pragma once
#ifndef _GAME_
#define _GAME_

#include "Board.h"
#include "SFML/Graphics.hpp"

class Game {
private:
	Board* board;
	int turn = 0;


public:
	Game(sf::Event&);
};

#endif