//
// Created by y8m on 15.08.15.
//

#include "ObjectFactory.h"

ObjectFactory::ObjectFactory() {
}

ObjectFactory::~ObjectFactory() {
}

unsigned int ObjectFactory::create(const std::string &name) {
    IObject *object = factory_map[name]->create();
    objects[object->getUniqueId()] = object;
    return object->getUniqueId();
}

void ObjectFactory::registerClass(const std::string &name, ICreator *creator) {
    if (factory_map.find(name) == factory_map.end())
        factory_map[name] = creator;
    else
        delete creator;
}

IObject *ObjectFactory::getObject(unsigned int uniqueId) {
    std::map<unsigned int, IObject*>::iterator it;
    it = objects.find(uniqueId);
    if (it != objects.end())
        return it->second;
    return nullptr;
}

ObjectFactory &ObjectFactory::get() {
    static ObjectFactory objectFactory;
    return objectFactory;
}

std::map<unsigned int, IObject*> *ObjectFactory::getObjectMap() {
    return & objects;
}
