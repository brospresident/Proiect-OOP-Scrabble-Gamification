#ifndef _MENU_H_
#define _MENU_H_

#include "SFML/Graphics.hpp"
#include "Misc.h"
#include "Window.h"
#include "Button.h"
#include <vector>

class Menu {
private:
	sf::Event event;
	Window* window;
	sf::Font font;
	Button* buttons[4];
	
public:
	Menu(Window*, sf::Font&, std::vector<std::reference_wrapper<Texture>>);
	void setEvent(sf::Event& event);
	void renderMenu();
	int handleActions();

	~Menu();
};

#endif