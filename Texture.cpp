#pragma once

#include "Texture.h"

Texture::Texture() {
	this->height = 0.0f;
	this->width = 0.0f;
	this->posX = 0;
	this->posY = 0;
}

Texture::Texture(const std::string path, const float posX, const float posY, const float width, const float height) {
	this->height = height;
	this->width = width;
	this->posX = posX;
	this->posY = posY;

	this->loadTexture();
	this->setSmooth(true);
	this->setRepeated(false);
}

// getters
float Texture::getPosX() {
	return this->posX;
}

float Texture::getPosY() {
	return this->posY;
}

float Texture::getWidth() {
	return this->width;
}

float Texture::getHeight() {
	return this->height;
}

std::string Texture::getPath() {
	return this->path;
}

// setters
void Texture::setPosX(float x) {
	this->posX = x;
}

void Texture::setPosY(float y) {
	this->posY = y;
}

void Texture::setWidth(float w) {
	this->width = w;
}

void Texture::setHeight(float h) {
	this->height = h;
}

void Texture::setPath(std::string path) {
	this->path = path;
}

void Texture::setSmooth(bool flag) {
	this->texture.setSmooth(flag);
}

void Texture::setRepeated(bool flag) {
	this->texture.setRepeated(flag);
}

void Texture::loadTexture() {
	if (!this->texture.loadFromFile(this->getPath(), sf::IntRect(this->getPosX(), this->getPosY(), this->getWidth(), this->getHeight()))) {
		std::cout << "Failed to load texture..." << std::endl;
		return;
	}
}