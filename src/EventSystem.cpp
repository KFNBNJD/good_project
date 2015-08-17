//
// Created by y8m on 13.08.15.
//

#include "EventSystem.h"

EventSystem &EventSystem::get() {
    static EventSystem eventSystem;
    return eventSystem;
}

EventSystem::EventSystem() {

}

EventSystem::~EventSystem() {

}

void EventSystem::setHandler(Event::Type eventType, IEventHandler *eventHandler) {
    handlersMap[eventType] = eventHandler;
}

void EventSystem::push_event(const Event &event) {
    events.push_back(event);
}

void EventSystem::handle_events() {
    for (Event event : events) {
        if (handlersMap.find(event.type) != handlersMap.end())
            handlersMap[event.type]->handle(&event);
    }
    events.clear();
}
