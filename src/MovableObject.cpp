//
// Created by y8m on 15.08.15.
//

#include <iostream>
#include "MovableObject.h"
#include "EventSystem.h"

MovableObject::MovableObject() {
    x = y = 0;
    speed_x = speed_y = 0;
}

MovableObject::~MovableObject() {

}

void MovableObject::jump(double vx, double vy) {
    Event event;
    event.objectMoveEvent.objectId = getUniqueId();
    event.objectMoveEvent.vx = vx;
    event.objectMoveEvent.vy = vy;
    event.type = Event::Type::ObjectMove;

    EventSystem::get().push_event(event);
}
