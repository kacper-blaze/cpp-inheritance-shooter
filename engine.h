#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <memory> // std::shared_ptr && std::unique_ptr

#include "bullet.h"
#include "direction.h"
#include "enemy.h"
#include "player.h"
#include "stage.h"

struct Position;
class Bullet;
class Enemy;


Position generateNewEnemyPosition(int width, int height);

class Engine
{
public:
    Engine(std::size_t stageWidth, std::size_t stageHeight);
    ~Engine();

    std::size_t stageWidthCells() const;
    std::size_t stageHeightCells() const;

    /// metody zwracające informacje na temat gracza
    Position playerPosition() const; /// domyslnie srodek planszy
    Direction playerDirection() const; /// domyślnie Direction::RIGHT
    bool isPlayerAlive() const;
    void setPlayerDirection(Direction direction);
    bool isGameOver() const { return gameOver_; }
    r

    /// metody obsługiwane z klawiatury
    void playerShoots();
    void movePlayerUp();
    void movePlayerDown();
    void movePlayerLeft();
    void movePlayerRight();


    /// metody zwracające informacje na temat obiektów w grze
    const std::vector<Bullet>& bullets() const
    {
        return bullets_;
    }

    /// metoda wywoływania kilka razy na sekundę, która ma za zadanie zaktualizowanie obiektów
    void update();

    const auto& enemies() const
    {
        return enemies_;
    }

protected:
    /// metoda, która doda określoną liczbę wrogów w miejscach zwróconych przez generator:
    void randEnemies(Position (*positionGenerator)(int, int)=generateNewEnemyPosition);
    /// metoda, która wpierw usunie zabitych wrogów, a następnie wykona ruch
    void updateEnemies();

    /// metoda, która powinna zaktualizować pociski, czyli przesunąć je,
    /// obsłużyć trafienie wroga lub wyjście poza scenę
    void updateBullets();
    
    /// metoda do sprawdzania kolizji i zadawania obrażeń
    void checkCollisions();

private:
    std::size_t width_;
    std::size_t height_;
    Player player_;
    Stage stage_;
    std::vector<Bullet> bullets_;

    constexpr static std::size_t maxEnemies_ = 3;
    std::vector<std::shared_ptr<Enemy>> enemies_;
    
    bool gameOver_ = false;
};

#endif // ENGINE_H
