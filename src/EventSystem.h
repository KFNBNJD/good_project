//
// Created by y8m on 13.08.15.
//

#ifndef GOOD_PROJECT_EVENTSYSTEM_H
#define GOOD_PROJECT_EVENTSYSTEM_H

#include <map>
#include <vector>

#include "IEventHandler.h"

class EventSystem {
public:
    static EventSystem & get();

    void setHandler(Event::Type eventType, IEventHandler * eventHandler);
    void push_event(const Event & event);
    void handle_events();
private:
    std::vector<Event> events;
    std::map<Event::Type, IEventHandler*> handlersMap;

    EventSystem();
    virtual ~EventSystem();
};


#endif //GOOD_PROJECT_EVENTSYSTEM_H
