#include <iostream>
#include "engine.h"

int main()
{
    std::cout << "=== Game Test ===" << std::endl;
    Engine engine(20, 15);
    
    std::cout << "Initial state:" << std::endl;
    std::cout << "Stage: " << engine.stageWidthCells() << "x" << engine.stageHeightCells() << std::endl;
    std::cout << "Player position: (" << engine.playerPosition().x_ 
              << ", " << engine.playerPosition().y_ << ")" << std::endl;
    std::cout << "Player alive: " << (engine.isPlayerAlive() ? "Yes" : "No") << std::endl;
    std::cout << "Bullets: " << engine.bullets().size() << std::endl;
    std::cout << "Enemies: " << engine.enemies().size() << std::endl;
    
    std::cout << "\n=== Testing shooting ===" << std::endl;
    engine.playerShoots();
    std::cout << "After shooting - Bullets: " << engine.bullets().size() << std::endl;
    
    std::cout << "\n=== Testing updates ===" << std::endl;
    for (int i = 0; i < 5; i++) {
        engine.update();
        std::cout << "Update " << i+1 << " - Bullets: " << engine.bullets().size() 
                  << ", Enemies: " << engine.enemies().size() << std::endl;
    }
    
    std::cout << "\n=== Testing movement ===" << std::endl;
    Position oldPos = engine.playerPosition();
    engine.movePlayerUp();
    std::cout << "Moved up: (" << oldPos.x_ << "," << oldPos.y_ 
              << ") -> (" << engine.playerPosition().x_ 
              << "," << engine.playerPosition().y_ << ")" << std::endl;
    
    return 0;
}
