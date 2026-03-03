#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"
#include "direction.h"

class Player : public Object
{
public:
    Player(Position position = Position(0, 0))
        : Object(ObjectType::OBJECT_PLAYER, position), direction_(Direction::RIGHT), isAlive_(true) {}
    Direction direction() const {return direction_;}
    void setDirection(Direction d){direction_=d;}
    bool isAlive() const {return isAlive_;}
    void setIsAlive(bool a){isAlive_ = a;}

private:
    Direction direction_;
    bool isAlive_;
};

#endif // PLAYER_H
