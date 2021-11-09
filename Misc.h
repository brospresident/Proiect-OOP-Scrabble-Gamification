#pragma once

#ifndef _MISC_
#define _MISC_

#include <iostream>
#include <string>
#include <vector>

class Misc {
public:
	std::string const UNKNOWN_CHARACTER = "Unknown";
	enum GamePhases {
		RegisteringPlayer1,
		RegisteringPlayer2,
		Playing,
		ShowingScore
	};

	enum ButtonTypes {
		BUTTON_BOARD_SQUARE,
		BUTTON_FINISH_TURN
	};

	// TODO support pentru cifre
	std::string keyCodeToString(int key);

	std::string removeLastCharacter(std::string str);

	std::vector<std::string> randomCharList();
};

#endif // !_MISC_

