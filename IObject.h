//
// Created by y8m on 12.08.15.
//

#ifndef GOOD_PROJECT_IOBJECT_H
#define GOOD_PROJECT_IOBJECT_H

class IObject {
public:
    IObject();
    virtual ~IObject();

    unsigned int getUniqueId() const;

protected:
    unsigned int uniqueId;

private:
    static unsigned int globalId;
};


#endif //GOOD_PROJECT_IOBJECT_H
