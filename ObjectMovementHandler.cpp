//
// Created by y8m on 13.08.15.
//

#include <iostream>
#include "ObjectMovementHandler.h"
#include "ObjectFactory.h"

ObjectMovementHandler::ObjectMovementHandler() : IEventHandler() {
    objects = nullptr;
}

ObjectMovementHandler::~ObjectMovementHandler() {

}

void ObjectMovementHandler::handle(const Event *event) {
    if (objects == nullptr) return;

    MovableObject *object = dynamic_cast<MovableObject*>(ObjectFactory::get().getObject(event->objectMoveEvent.objectId));

    object->setX(object->getX() + event->objectMoveEvent.vx);
    object->setY(object->getY() + event->objectMoveEvent.vy);

    std::cout << "Object " << object->getUniqueId() << " is moving!" << std::endl;
    std::cout << "Object is now in " << object->getX() << ", " << object->getY() << std::endl;
}

void ObjectMovementHandler::setObjects(std::map<unsigned int, IObject*> *objects) {
    this->objects = objects;
}
