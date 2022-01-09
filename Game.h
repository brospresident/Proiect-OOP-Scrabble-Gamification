#ifndef _GAME_
#define _GAME_

#include "Board.h"
#include "SFML/Graphics.hpp"
#include "Texture.h"
#include "Window.h"
#include "Scrabblegame.h"
#include "Timer.h"
#include <vector>

class Game {
private:
	Board* board;
	std::vector<std::reference_wrapper<Texture>> textures;
	sf::Event ev;
	sf::Font font;
	Window* w;
	ScrabbleGame sgInstance;
	Timer* timer;

public:
	Game(Window*, sf::Font&, std::vector<std::reference_wrapper<Texture>>);
	~Game();

	void setEvent(sf::Event&, int&);
	void resetTimer();
};

#endif