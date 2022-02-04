#ifndef _GAME_OVER_H_
#define _GAME_OVER_H_

#include "./AbstractPage.h"
#include "./Player.h"
#include "./TextWriter.h"

class GameOver : public AbstractPage {
public:
	GameOver(Window* window, std::vector<std::reference_wrapper<Texture>> textures, sf::Font& font, Player player);
	void setEvent(sf::Event ev);
	void displayContent();
	Player player;
	sf::Font font;
	int handleClick();
};

#endif