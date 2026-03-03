#ifndef BULLET_H
#define BULLET_H

#include <iostream>

#include "object.h"
#include "direction.h"

class Bullet : public Object
{
    private:
        Direction direction_;
        Position start_position_;
        static float speed_;
    public:
        Bullet(Direction dir, Position startPos) : Object(ObjectType::OBJECT_BULLET, startPos),
                                                        direction_(dir),start_position_(startPos) {}

        Direction direction() const {return direction_;}
        void setDirection(Direction direction){direction_ = direction;}
        Position getStartPosition(){return start_position_;}
        static float speed(){return speed_;}
};
#endif // BULLET_H
