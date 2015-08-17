//
// Created by y8m on 13.08.15.
//

#ifndef GOOD_PROJECT_IEVENTHANDLER_H
#define GOOD_PROJECT_IEVENTHANDLER_H

#include "Event.h"

class IEventHandler {
public:
    IEventHandler();
    virtual ~IEventHandler();

    virtual void handle(const Event * event) = 0;
protected:
};


#endif //GOOD_PROJECT_IEVENTHANDLER_H
