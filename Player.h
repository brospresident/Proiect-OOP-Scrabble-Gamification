#ifndef _PLAYER_
#define _PLAYER_

#include <iostream>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>
#include "TextWriter.h"

class Player {
private:
	int id;
	std::string playerName;
	int score = 0;

public:
	Player(std::string playerName, int id);

	Player();

	// getters
	std::string getPlayerName();

	int getPlayerScore();

	int getPlayerId();

	// setters
	void setPlayerName(std::string playerName);

	void setPlayerScore(int score);

	void setPlayerId(int id);

	void updateScore(int score1);

	std::vector<TextWriter*> dataToString(const sf::Font& font, const float width, const float height);
};

#endif // !_PLAYER_
