/*
 * GraphicsText.h
 *
 *  Created on: Aug 17, 2015
 *      Author: y8m
 */

#ifndef SRC_GRAPHICSTEXT_H_
#define SRC_GRAPHICSTEXT_H_

#include <stdexcept>
#include <string>

#include "GraphicsComponent.h"

class GraphicsText: public GraphicsComponent {
public:
	GraphicsText();
	virtual ~GraphicsText();

	virtual void draw(sf::RenderWindow & window);

	void setText(const std::string & text);
	void setFont(sf::Font * font);
	void setPosition(double x, double y);
	void setSize(int size);
private:
	sf::Font * font;
	sf::Text sfText;
};

#endif /* SRC_GRAPHICSTEXT_H_ */
