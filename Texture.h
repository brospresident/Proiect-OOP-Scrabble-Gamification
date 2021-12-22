#ifndef _TEXTURE_
#define _TEXTURE_

#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>

class Texture {
private:
	float posX;
	float posY;
	float width;
	float height;
	std::string path;
public:
	sf::Texture texture;
	sf::IntRect rect;
	Texture();
	Texture(const std::string, const float, const float, const float, const float);

	// getters
	float getPosX();
	float getPosY();
	float getWidth();
	float getHeight();
	std::string getPath();

	// setters
	void setPosX(float);
	void setPosY(float);
	void setWidth(float);
	void setHeight(float);
	void setPath(std::string);
	void setSmooth(bool);
	void setRepeated(bool);

	void loadTexture();
	void unLoadTexture();
};

#endif // !_TEXTURE_
