#ifndef _TIMER_H_
#define _TIMER_H_

#include "SFML/Graphics.hpp"
#include "TextWriter.h"
#include "Window.h"
#include <string>
#include <iostream>

class Timer {
private:
	long long int totalTime = 30 * 60000;
	sf::Clock clock;
	sf::Font renderFont;
	Window* window;

public:
	Timer(sf::Font&, Window*);
	Timer();
	
	TextWriter* scoreRender;

	// getters and setters
	long long int getTotalTime();
	sf::Clock getClock();
	TextWriter& getTextRender();

	void getMinutesAndSeconds(int&, int&);

	void setTotalTime(long long int);

	void renderTimer();

	bool isOver();
};

#endif