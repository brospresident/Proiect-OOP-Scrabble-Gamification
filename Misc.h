#pragma once

#ifndef _MISC_
#define _MISC_

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

	std::string removeLastCharacter(std::string str);
};

#endif // !_MISC_

