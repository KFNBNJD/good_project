/*
 * GraphicsText.cpp
 *
 *  Created on: Aug 17, 2015
 *      Author: y8m
 */

#include "GraphicsText.h"

GraphicsText::GraphicsText() {
	// TODO Auto-generated constructor stub
	font = nullptr;
}

GraphicsText::~GraphicsText() {
	// TODO Auto-generated destructor stub
}

void GraphicsText::draw(sf::RenderWindow& window) {
	if (font == nullptr) {
		throw std::runtime_error("Null font (GraphicsText)");
	}

	window.draw(sfText);
}

void GraphicsText::setText(const std::string& text) {
	sfText.setString(text);
}

void GraphicsText::setFont(sf::Font* font) {
	this->font = font;
	sfText.setFont(*font);
}

void GraphicsText::setPosition(double x, double y) {
	sfText.setPosition(x, y);
}

void GraphicsText::setSize(int size) {
	sfText.setCharacterSize(size);
}
