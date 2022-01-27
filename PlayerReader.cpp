#include "./PlayerReader.h"

bool PlayerReader::readData(std::string name, Player& player) {
	std::ifstream file("users/" + name + ".txt");

	if (file.good()) {
		std::string line;
		file >> line;
		int score = std::stoi(line);
		player.setPlayerBestScore(score);
		return true;
	}
	else {
		player.setPlayerBestScore(0);
		return false;
	}
}