#ifndef ENEMY_H
#define ENEMY_H

#include <chrono>
#include <iostream>

#include "object.h"

class Enemy : public Object {
public:
    Enemy(Position current_position, int max_life = 20): Object(ObjectType::OBJECT_ENEMY, current_position), life_points_(max_life), max_life_(max_life), lastMoveTime_(std::chrono::steady_clock::now()){}
    int lifePercent() const {return static_cast<int>((static_cast<float>(life_points_) / max_life_) * 100);}
    bool isAlive() const {if (life_points_ > 0){return true;}return false;}
    void decreaseLife(int damage){life_points_-= damage;}

    bool shouldIMoveThisTime() const;
    void updateLastMoveTime();
private:
    static constexpr std::chrono::milliseconds moveInterval_{1000};

    mutable std::chrono::steady_clock::time_point lastMoveTime_;

    int life_points_;
    int max_life_;
};

#endif // ENEMY_H
