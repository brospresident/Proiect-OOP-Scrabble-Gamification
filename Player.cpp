#include <iostream>
#include <string>

class Player {
private:
	std::string playerName;
	int score = 0;

public:
	Player(std::string playerName) {
		if (playerName.size() == 0) {
			this->playerName = "Player";
		}
		else this->playerName = playerName;
	}
	
	Player() {
		this->playerName = "";
	}

	// getters
	std::string getPlayerName() {
		return this->playerName;
	}

	int getPlayerScore() {
		return this->score;
	}

	// setters
	void setPlayerName(std::string playerName) {
		this->playerName = playerName;
	}

	void setPlayerScore(int score) {
		this->score = score;
	}


};