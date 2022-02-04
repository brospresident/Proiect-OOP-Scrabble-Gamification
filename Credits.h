#ifndef _CREDITS_H_
#define _CREDITS_H_

#include "AbstractPage.h"

class Credits : public AbstractPage {
public:
	sf::Font font;
	Window* window;
	Credits(Window* window, std::vector<std::reference_wrapper<Texture>> textures, sf::Font& font);
	void setEvent(sf::Event ev);
	void displayContent();
	int handleClick();
};

#endif