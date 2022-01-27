#include <iostream>
#include <string>
#include <vector>

#include "Player.h"

Player::Player(std::string playerName, int id) {
	if (playerName.size() == 0) {
		this->playerName = "Player";
	}
	else this->playerName = playerName;
	this->id = id;
}

Player::Player() {
	this->playerName = "";
}

// getters
std::string Player::getPlayerName() {
	return this->playerName;
}

int Player::getPlayerScore() {
	return this->score;
}

int Player::getPlayerBestScore() {
	return this->score;
}

int Player::getPlayerId() {
	return this->id;
}

// setters
void Player::setPlayerName(std::string playerName) {
	this->playerName = playerName;
}

void Player::setPlayerScore(int score) {
	this->score += score;
}

void Player::setPlayerBestScore(int score) {
	this->score = score;
}

void Player::setPlayerId(int id) {
	this->id = id;
}

void Player::updateScore(int score1) {
	this->score += score1;
}

std::vector<TextWriter*> Player::dataToString(const sf::Font& font, const float width, const float height) {
	std::vector<TextWriter*> res;
	if (this->id == 0) {
		TextWriter* playerName = new TextWriter(this->getPlayerName(), 25, font, 20.0f, height / 5.0f);
		playerName->underline();
		std::string scoreString = "Score: ";
		scoreString.append(std::to_string(this->getPlayerScore()));

		TextWriter* playerScore = new TextWriter(scoreString, 15, font, 20.0f, height / 4.0f);
		
		res.push_back(playerName);
		res.push_back(playerScore);
	}
	else {
		TextWriter* playerName = new TextWriter(this->getPlayerName(), 25, font, width - (this->getPlayerName().size() * 17.0f), height / 5.0f);
		playerName->underline();
		std::string scoreString = "Score: ";
		scoreString.append(std::to_string(this->getPlayerScore()));

		TextWriter* playerScore = new TextWriter(scoreString, 15, font, width - (scoreString.size() * 11.0f), height / 4.0f);

		res.push_back(playerName);
		res.push_back(playerScore);
	}

	return res;
}

