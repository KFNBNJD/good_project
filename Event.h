//
// Created by y8m on 12.08.15.
//

#include "SFML/Window/Event.hpp"

#ifndef GOOD_PROJECT_IEVENT_H
#define GOOD_PROJECT_IEVENT_H

class Event {
public:
    Event();
    virtual ~Event();

    struct ObjectEvent {
        unsigned int objectId;
    };

    struct ObjectMoveEvent {
        unsigned int objectId;
        double vx, vy;
    };

    enum Type {
        ObjectMove,
        ObjectDestroy,

        Count
    };

public:
    union {
        ObjectEvent object;
        ObjectMoveEvent objectMoveEvent;
    };

    Type type;
};


#endif //GOOD_PROJECT_IEVENT_H
