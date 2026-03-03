#include "enemy.h"

bool Enemy::shouldIMoveThisTime() const
{
    auto currentTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastMoveTime_);
    return elapsedTime >= moveInterval_;
}

void Enemy::updateLastMoveTime()
{
    lastMoveTime_ = std::chrono::steady_clock::now();
}
