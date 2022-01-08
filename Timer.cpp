#include "./Timer.h"

Timer::Timer(sf::Font& const renderFont, Window* window) {
	this->renderFont = renderFont;
	this->totalTime = 30 * 60000;
	this->window = window;
}

Timer::Timer() {
	this->totalTime = 0;
	this->window = nullptr;
}

//getters

long long int Timer::getTotalTime() {

	return this->totalTime;
}

sf::Clock Timer::getClock() {

	return this->clock;
}

void Timer::getMinutesAndSeconds(int& minutes, int& seconds) {
	long long remainingTime = this->getTotalTime() - this->clock.getElapsedTime().asMilliseconds();
	minutes = (remainingTime / 1000) / 60;
	seconds = (remainingTime / 1000) % 60;
}

//setters

void Timer::setTotalTime(long long int time) {

	this->totalTime += time;
}

bool Timer::isOver() {
	return this->totalTime < this->clock.getElapsedTime().asMilliseconds();
}

void Timer::renderTimer() {
	if (this->isOver()) return;
	int minutes = 0, seconds = 0;
	this->getMinutesAndSeconds(minutes, seconds);

	std::string text = std::to_string(minutes) + ":" + std::to_string(seconds) + "  left";

	this->scoreRender = new TextWriter(text, 18, this->renderFont, 100, 50);
	this->window->drawText(this->scoreRender->text);
}