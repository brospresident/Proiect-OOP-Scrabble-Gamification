#include "./Timer.h"

Timer::Timer() {

	this->remainingTime = 30 * 60000;
}

//getters

long long int Timer::getRemainingTime() {

	return this->remainingTime;
}

sf::Clock Timer::getClock() {

	return this->clock;
}

//setters

void Timer::setRemainingTime(long long int time) {

	this->remainingTime += time;
}