//
// Created by y8m on 13.08.15.
//

#ifndef GOOD_PROJECT_OBJECTMOVEMENTHANDLER_H
#define GOOD_PROJECT_OBJECTMOVEMENTHANDLER_H

#include <map>

#include "IEventHandler.h"
#include "IObject.h"

class ObjectMovementHandler : public IEventHandler {
public:
    ObjectMovementHandler();
    virtual ~ObjectMovementHandler();

    void handle(const Event * event);
    void setObjects(std::map<unsigned int, IObject*> *objects);

private:
    std::map<unsigned int, IObject*> *objects;
};


#endif //GOOD_PROJECT_OBJECTMOVEMENTHANDLER_H
