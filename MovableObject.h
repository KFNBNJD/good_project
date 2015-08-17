//
// Created by y8m on 15.08.15.
//

#ifndef GOOD_PROJECT_MOVABLEOBJECT_H
#define GOOD_PROJECT_MOVABLEOBJECT_H


#include "IObject.h"

class MovableObject : public IObject {
public:
    MovableObject();
    virtual ~MovableObject();

    void jump(double vx, double vy);

public:
    double getX() const {
        return x;
    }

    void setX(double x) {
        MovableObject::x = x;
    }

    double getY() const {
        return y;
    }

    void setY(double y) {
        MovableObject::y = y;
    }

    double getSpeed_x() const {
        return speed_x;
    }

    void setSpeed_x(double speed_x) {
        MovableObject::speed_x = speed_x;
    }

    double getSpeed_y() const {
        return speed_y;
    }

    void setSpeed_y(double speed_y) {
        MovableObject::speed_y = speed_y;
    }

private:
    double x, y, speed_x, speed_y;
};


#endif //GOOD_PROJECT_MOVABLEOBJECT_H
