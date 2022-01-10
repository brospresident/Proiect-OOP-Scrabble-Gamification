#ifndef _MISC_
#define _MISC_

#include <iostream>
#include <string>
#include <vector>
#include <time.h>

class Misc {
public:
	int vowels[5] = {0, 4, 8, 14, 20};
	int consonants[21] = {1, 2, 3, 5, 6, 7, 9, 10, 11, 12, 13, 15, 16, 17, 18, 19, 21, 22, 23, 24, 25};
	std::string const UNKNOWN_CHARACTER = "Unknown";
	enum GamePhases {
		Menu,
		ShowingHelp,
		RegisteringPlayer1,
		Playing,
		ShowingScore
	};

	enum ButtonTypes {
		BUTTON_BOARD_SQUARE,
		BUTTON_FINISH_TURN,
		BUTTON_RANDOM_CHAR,
		BUTTON_REROLL,
		BUTTON_START_GAME,
		BUTTON_HELP,
		BUTTON_BACK,
		BUTTON_SHOW_GUIDE
	};

	// TODO support pentru cifre
	std::string keyCodeToString (int key);

	std::string toUpperCase (int key);

	std::string removeLastCharacter(std::string str);

	std::vector<std::string> randomCharList();
};

#endif // !_MISC_

