#ifndef _GUIDE_H_
#define _GUIDE_H_

#include "./AbstractPage.h"
#include "./TextWriter.h"

class Guide : public AbstractPage {
public:
	float startPosX = 300.f;
	float startPosY = 200.f;
	float moveY = 25.f;
	sf::Font gameFont;
	std::vector<TextWriter*> messages;
	Guide(Window* window, std::vector<std::reference_wrapper<Texture>> textures, sf::Font& font);
	~Guide();
	void setEvent(sf::Event ev);
	void displayContent();
	void createTexts();
};

#endif