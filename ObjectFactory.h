//
// Created by y8m on 15.08.15.
//

#ifndef GOOD_PROJECT_OBJECTFACTORY_H
#define GOOD_PROJECT_OBJECTFACTORY_H

#include <string>
#include <set>
#include <map>

#include "IObject.h"
#include "MovableObject.h"

class ICreator {
public:
    virtual IObject * create() = 0;
};

class ObjectCreator : public ICreator {
public:
    IObject * create() {
        IObject *object = new IObject();
        return object;
    }
};

class MovableObjectCreator : public ICreator {
public:
    IObject *create() {
        IObject *object = new MovableObject();
        return object;
    }
};

class ObjectFactory {
public:
    static ObjectFactory & get();

    unsigned int create(const std::string & name);
    void registerClass(const std::string & name, ICreator *creator);

    IObject * getObject(unsigned int uniqueId);
    std::map<unsigned int, IObject*> * getObjectMap();
protected:
    std::map<std::string, ICreator*> factory_map;
    std::map<unsigned int, IObject*> objects;

private:
    ObjectFactory();
    virtual ~ObjectFactory();
};


#endif //GOOD_PROJECT_OBJECTFACTORY_H
