#include "./PlayerWriter.h"

void PlayerWriter::writeData(Player player) {
	std::ofstream file("users/" + player.getPlayerName() + ".txt");
	if (file.good()) {
		int bestScore = player.getPlayerBestScore();
		int score = player.getPlayerScore();

		if (bestScore > score) {
			file << bestScore;
		}
		else {
			file << score;
		}
	}
}