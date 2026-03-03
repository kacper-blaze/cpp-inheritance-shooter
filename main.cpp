#include <iostream>
#include "engine.h"

int main()
{
    std::cout << "Game starting..." << std::endl;
    Engine engine(20, 15);
    
    std::cout << "Engine created with stage: " << engine.stageWidthCells() 
              << "x" << engine.stageHeightCells() << std::endl;
    std::cout << "Player position: (" << engine.playerPosition().x_ 
              << ", " << engine.playerPosition().y_ << ")" << std::endl;
    std::cout << "Player alive: " << (engine.isPlayerAlive() ? "Yes" : "No") << std::endl;
    
    return 0;
}
