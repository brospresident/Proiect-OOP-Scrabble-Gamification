#ifndef _ABSTRACT_PAGE_H_
#define _ABSTRACT_PAGE_H_

#include "Button.h"
#include <vector>
#include "Texture.h"
#include "Window.h"
#include "Misc.h"

class AbstractPage {
protected:
	Window* window;
	sf::Font font;
	int gamePhase;
public:
	Button* backButton;
	std::vector<std::reference_wrapper<Texture>> textures;
	AbstractPage(Window* window, std::vector<std::reference_wrapper<Texture>> textures, sf::Font& font);
	~AbstractPage();

	virtual void setEvent(sf::Event ev) = 0;
	int handleClick();

	virtual void displayContent() = 0;
};

#endif