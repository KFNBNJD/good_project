/*
 * GraphicsComponent.cpp
 *
 *  Created on: Aug 17, 2015
 *      Author: y8m
 */

#include "GraphicsComponent.h"

GraphicsComponent::GraphicsComponent() {
	// TODO Auto-generated constructor stub
}

GraphicsComponent::~GraphicsComponent() {
	// TODO Auto-generated destructor stub
}

void GraphicsComponent::setLifeTime(sf::Time time) {
	maxLifeTime = time;
}

void GraphicsComponent::update(sf::Time delta) {
	lifeTime += delta;
}

bool GraphicsComponent::isOver() {
	return lifeTime >= maxLifeTime;
}
