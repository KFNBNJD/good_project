/*
 * GraphicsComponent.h
 *
 *  Created on: Aug 17, 2015
 *      Author: y8m
 */

#ifndef SRC_GRAPHICSCOMPONENT_H_
#define SRC_GRAPHICSCOMPONENT_H_

#include "SFML/Graphics.hpp"

class GraphicsComponent {
public:
	GraphicsComponent();
	virtual ~GraphicsComponent();

	virtual void draw(sf::RenderWindow & window) = 0;

	void setLifeTime(sf::Time time);
	void update(sf::Time delta);
	bool isOver();
protected:
	sf::Time lifeTime, maxLifeTime;
};

#endif /* SRC_GRAPHICSCOMPONENT_H_ */
