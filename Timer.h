#ifndef _TIMER_H_
#define _TIMER_H_

#include "SFML/Graphics.hpp"

class Timer {
private:
	long long int remainingTime = 30 * 60000;
	sf::Clock clock;

public:
	Timer();
	
	// getters and setters
	long long int getRemainingTime();
	sf::Clock getClock();

	void setRemainingTime(long long int);
};

#endif