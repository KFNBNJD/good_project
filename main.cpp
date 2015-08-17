#include <iostream>
using namespace std;

#include "MovableObject.h"
#include "ObjectFactory.h"
#include "EventSystem.h"
#include "ObjectMovementHandler.h"

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
    return 0;
}