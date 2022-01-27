#ifndef _PLAYER_READER_H_
#define _PLAYER_READER_H_

#include "Player.h"
#include <fstream>

class PlayerReader {
public:
	bool readData(std::string name, Player& player);
};

#endif