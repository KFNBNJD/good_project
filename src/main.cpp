#include <iostream>
using namespace std;

#include "MovableObject.h"
#include "ObjectFactory.h"
#include "EventSystem.h"
#include "ObjectMovementHandler.h"

#include "SFML/Graphics.hpp"

int main() {
    ObjectFactory::get().registerClass("Object", new MovableObjectCreator());

    unsigned int objectId = ObjectFactory::get().create("Object");
    MovableObject *object = dynamic_cast<MovableObject*>(ObjectFactory::get().getObject(objectId));
    object->jump(100, 200);
    object->jump(200, 300);

    ObjectMovementHandler objectMovementHandler;
    objectMovementHandler.setObjects(ObjectFactory::get().getObjectMap());
    EventSystem::get().setHandler(Event::Type::ObjectMove, &objectMovementHandler);
    EventSystem::get().handle_events();

    ////////////////////////////////////////
    /// Creating window
    ////////////////////////////////////////

    sf::RenderWindow window(sf::VideoMode(800, 500), "Window title");

    while (window.isOpen()) {
    	sf::Event event;
    	while (window.pollEvent(event)) {
    		if (event.type == sf::Event::Closed) {
    			window.close();
    		}
    	}

    	window.clear();
    	window.display();
    }

    return 0;
}
