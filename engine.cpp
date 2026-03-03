#include <algorithm>
#include <iostream>
#include "engine.h"
#include "player.h"
#include "stage.h"
#include "bullet.h"
#include "enemy.h"


namespace
{
inline auto signum(int x)
{
    return (x > 0) - (x < 0);
}

Direction randDirection()
{
    auto randEdge = rand() % static_cast<uint8_t>(Direction::UPPER_LEFT);
    return static_cast<Direction>(randEdge);
}
}


Position generateNewEnemyPosition(int width, int height)
{
    Position position2Generate = Position(rand() % width, rand() % height);

    switch (randDirection()) {
        case Direction::UP:
            position2Generate.y_ = height-1;
            break;
        case Direction::DOWN:
            position2Generate.y_ = 0;
            break;
        case Direction::LEFT:
            position2Generate.x_ = 0;
            break;
        case Direction::RIGHT:
            position2Generate.x_ = width-1;
            break;
        default:
            break;
    }
    return position2Generate;
}


Engine::~Engine() = default;


Engine::Engine(std::size_t stageWidth, std::size_t stageHeight):
     width_(stageWidth), height_(stageHeight), stage_(stageWidth, stageHeight)
{
    const decltype(Position::x_) middleX = stage_.width() / 2;
    const decltype(Position::y_) middleY = stage_.height() / 2;

    {
        player_.setPosition(Position(middleX, middleY));
    }
}

void Engine::update()
{
    updateBullets();
    updateEnemies();
    randEnemies();
    checkCollisions();
}

void Engine::updateBullets()
{
    for (auto it = bullets_.begin(); it != bullets_.end(); ) {
        Position currentPos = it->position();

        switch (it->direction()) {
            case Direction::UP:    currentPos.y_--; break;
            case Direction::DOWN:  currentPos.y_++; break;
            case Direction::LEFT:  currentPos.x_--; break;
            case Direction::RIGHT: currentPos.x_++; break;
            default: break;
        }

        if (stage_.isInside(currentPos)) {
            it->setPosition(currentPos);
            ++it;
        } else {
            it = bullets_.erase(it);
        }
    }
}

void Engine::updateEnemies()
{
    enemies_.erase(
        std::remove_if(enemies_.begin(), enemies_.end(),
            [](const std::shared_ptr<Enemy>& enemy) {
                return !enemy->isAlive();
            }),
        enemies_.end()
    );

    for (auto& enemy : enemies_) {
        if (enemy->shouldIMoveThisTime()) {
            Position enemyPos = enemy->position();
            Position playerPos = player_.position();

            if (enemyPos.x_ < playerPos.x_) {
                enemyPos.moveRight();
            } else if (enemyPos.x_ > playerPos.x_) {
                enemyPos.moveLeft();
            } else if (enemyPos.y_ < playerPos.y_) {
                enemyPos.moveUp();
            } else if (enemyPos.y_ > playerPos.y_) {
                enemyPos.moveDown();
            }
            
            // Only move if new position is inside stage
            if (stage_.isInside(enemyPos)) {
                enemy->setPosition(enemyPos);
                enemy->updateLastMoveTime();
                std::cout << "Enemy moved to position: " << enemyPos.x_ << "," << enemyPos.y_ << std::endl;
            }
        }
    }
}

void Engine::movePlayerUp()
{
    Position newPos = player_.position();
    newPos.moveUp();
    if (stage_.isInside(newPos)) {player_.setPosition(newPos);}
}

void Engine::movePlayerDown()
{
    Position newPos = player_.position();
    newPos.moveDown();
    if (stage_.isInside(newPos)) {player_.setPosition(newPos);}
}

void Engine::movePlayerLeft()
{
    Position newPos = player_.position();
    newPos.moveLeft();
    if (stage_.isInside(newPos)) { player_.setPosition(newPos); }
}
void Engine::movePlayerRight()
{
    Position newPos = player_.position();
    newPos.moveRight();
    if (stage_.isInside(newPos)) {player_.setPosition(newPos);}
}

void Engine::playerShoots()
{
    if (!player_.isAlive()) return;
    Position bulletPos = player_.position();
    switch (player_.direction())
    {
        case Direction::UP:    bulletPos.y_--; break;  // Move up on screen = decrease y
        case Direction::DOWN:  bulletPos.y_++; break;  // Move down on screen = increase y
        case Direction::LEFT:  bulletPos.x_--; break;
        case Direction::RIGHT: bulletPos.x_++; break;
        default: break;
    }

    bullets_.emplace_back(player_.direction(), bulletPos);
}

Position Engine::playerPosition() const
{
    if (!player_.isAlive()) {
        return Position{};
    }
    return player_.position();
}

Direction Engine::playerDirection() const
{
    if (!player_.isAlive()) {
        return Direction::RIGHT;
    }
    return player_.direction();
}

void Engine::setPlayerDirection(Direction direction)
{
    if (player_.isAlive()) {
        player_.setDirection(direction);
    }
}

bool Engine::isPlayerAlive() const
{
    return player_.isAlive();
}

std::size_t Engine::stageWidthCells() const
{
    return width_;
}
std::size_t Engine::stageHeightCells() const
{
    return height_;
}

void Engine::randEnemies(Position (*positionGenerator)(int,int))
{
    if (enemies_.size() < maxEnemies_)
    {
        Position newEnemyPos = positionGenerator(stage_.width(), stage_.height());
        enemies_.emplace_back(std::make_shared<Enemy>(newEnemyPos));
        std::cout << "Spawned enemy at position: " << newEnemyPos.x_ << "," << newEnemyPos.y_ 
                  << " (total enemies: " << enemies_.size() << "/" << maxEnemies_ << ")" << std::endl;
    }
}

void Engine::checkCollisions()
{
    for (auto bulletIt = bullets_.begin(); bulletIt != bullets_.end(); ) {
        bool bulletRemoved = false;
        
        for (auto enemyIt = enemies_.begin(); enemyIt != enemies_.end(); ) {
            if (bulletIt->position().x_ == (*enemyIt)->position().x_ &&
                bulletIt->position().y_ == (*enemyIt)->position().y_) {

                (*enemyIt)->decreaseLife(7);
                std::cout << "Enemy hit! Health: " << (*enemyIt)->lifePercent() << "%" << std::endl;

                bulletIt = bullets_.erase(bulletIt);
                bulletRemoved = true;

                if (!(*enemyIt)->isAlive()) {
                    std::cout << "Enemy defeated!" << std::endl;
                    enemyIt = enemies_.erase(enemyIt);
                } else {
                    ++enemyIt;
                }
                break;
            } else {
                ++enemyIt;
            }
        }
        
        if (!bulletRemoved) {
            ++bulletIt;
        }
    }

    if (player_.isAlive()) {
        for (const auto& enemy : enemies_) {
            if (enemy->position().x_ == player_.position().x_ &&
                enemy->position().y_ == player_.position().y_) {

                player_.setIsAlive(false);
                gameOver_ = true;
                std::cout << "Player hit by enemy! Game Over!" << std::endl;
                break;
            }
        }
    }
}