#pragma once

#include <iostream>
#include <string>

class Misc {
public:
	std::string const UNKNOWN_CHARACTER = "Unknown";
	enum GamePhases {
		RegisteringPlayer1,
		RegisteringPlayer2,
		Playing,
		ShowingScore
	};

	// TODO support pentru cifre
	std::string keyCodeToString(int key);
};
