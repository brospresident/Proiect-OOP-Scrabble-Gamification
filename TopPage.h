#ifndef _TOP_PAGE_H_
#define _TOP_PAGE_H_

#include "./AbstractPage.h"
#include <vector>
#include <filesystem>
#include "./Player.h"
#include "PlayerReader.h"
#include <fstream>

namespace fs = std::filesystem;

class TopPage : public AbstractPage {
public:
	std::vector<Player> players;
	sf::Font font;
	float startY = 250;
	float moveY = 25;
	TopPage(Window* window, std::vector<std::reference_wrapper<Texture>> textures, sf::Font& font);
	void readPlayersData();
	void setEvent(sf::Event ev);
	void displayContent();
};

#endif