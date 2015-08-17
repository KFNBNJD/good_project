//
// Created by y8m on 12.08.15.
//

#include "IObject.h"

unsigned int IObject::globalId = 0;

IObject::IObject() {
    uniqueId = globalId++;
}

IObject::~IObject() {
    
}

unsigned int IObject::getUniqueId() const {
    return uniqueId;
}
