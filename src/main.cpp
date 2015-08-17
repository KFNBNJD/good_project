#include <iostream>
#include <set>
using namespace std;

#include "MovableObject.h"
#include "ObjectFactory.h"
#include "EventSystem.h"
#include "ObjectMovementHandler.h"
#include "GraphicsText.h"

#include "SFML/Graphics.hpp"

int main() {

    //////////////////////////////////////////
    /// Testing objects
    //////////////////////////////////////////

    ObjectFactory::get().registerClass("Object", new MovableObjectCreator());

    unsigned int objectId = ObjectFactory::get().create("Object");
    MovableObject *object = dynamic_cast<MovableObject*>(ObjectFactory::get().getObject(objectId));
    object->jump(100, 200);
    object->jump(200, 300);

    ObjectMovementHandler objectMovementHandler;
    objectMovementHandler.setObjects(ObjectFactory::get().getObjectMap());
    EventSystem::get().setHandler(Event::Type::ObjectMove, &objectMovementHandler);
    EventSystem::get().handle_events();

    //////////////////////////////////////////
    /// Creating window
    //////////////////////////////////////////

    sf::RenderWindow window(sf::VideoMode(800, 500), "Window title");

    //////////////////////////////////////////
    /// Testing text
    //////////////////////////////////////////

    /// Creating font
    sf::Font font;
    font.loadFromFile("arial.ttf");

    /// Setups text
    GraphicsText text;
    text.setFont(&font);
    text.setPosition(100, 100);
    text.setSize(12);
    text.setText("hello world");
    text.setLifeTime(sf::seconds(3)); // text will disappear after 3 second

    //////////////////////////////////////////
    /// Testing graphic stack
    //////////////////////////////////////////

    std::set<GraphicsComponent*> graphicStack;
    graphicStack.insert(&text);

    sf::Clock clock;
    while (window.isOpen()) {
    	clock.restart();

    	sf::Event event;
    	while (window.pollEvent(event)) {
    		if (event.type == sf::Event::Closed) {
    			window.close();
    		}
    	}

    	window.clear();

    	for (GraphicsComponent * gc : graphicStack) {
    		gc->update(clock.getElapsedTime());
    		gc->draw(window);
    		if (gc->isOver())
    			graphicStack.erase(gc);
    	}


    	window.display();
    }

    return 0;
}
