#ifndef OBJECT_H
#define OBJECT_H

#include "position.h"

enum class ObjectType
{
    OBJECT_PLAYER,
    OBJECT_BULLET,
    OBJECT_ENEMY,
    OBJECT_WALL,
    OBJECT_UNKNOWN
};


class Object
{
public:
    Object(ObjectType type, Position position = Position(0,0)) : objType(type), objPosition(position){}
    ObjectType type() const {return objType;}
    Position position() const {return objPosition;}
    void setPosition(Position position)
    {
        objPosition = position;
    }
    Object& moveUp(){objPosition.moveUp();return *this;}
    Object& moveDown(){objPosition.moveDown();return *this;}
    Object& moveLeft(){objPosition.moveLeft();return *this;}
    Object& moveRight(){objPosition.moveRight();return *this;}

protected:
    ObjectType objType;
    Position objPosition;
};

#endif // OBJECT_H
