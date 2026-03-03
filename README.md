# C++ Inheritance Game Project

A 2D space shooter game implemented in C++ using Qt for the GUI. This project demonstrates object-oriented programming concepts including inheritance, polymorphism, and game engine architecture.

## Game Overview

You control a spaceship in a 20x15 grid battlefield, fighting against enemies that spawn at the edges. The game features fast-paced combat with strategic positioning and shooting mechanics.

## Game Instructions

### Controls
- **Arrow Keys** - Move your spaceship (UP/DOWN/LEFT/RIGHT)
- **Spacebar** - Shoot bullets in the direction you're facing
- **ESC** - Exit game

### Gameplay
1. **Movement**: Use arrow keys to move your spaceship around the battlefield
2. **Shooting**: Press spacebar to shoot bullets. Your spaceship faces the direction you last moved
3. **Combat**: Hit enemies 3 times to defeat them (7 damage per hit, enemies have 20 HP)
4. **Survival**: Avoid enemy contact - one touch ends the game!
5. **Enemy AI**: Enemies move every 1 second towards your position
6. **Objective**: Defeat as many enemies as possible before getting caught

### Game Features
- **Fast enemy movement** (1 second intervals)
- **Balanced combat** (3 hits to defeat enemies)
- **Collision detection** (bullets hit enemies, enemies hurt player)
- **Game over screen** with freeze-frame
- **Enemy health bars** showing damage
- **Sound effects and background music**
- **Smooth graphics** with sprite rotation

## How to Launch

### GUI Version (Recommended)
```bash
# Build and run Qt GUI
cd game
qmake
make
./game_gui
```

### Console Version
```bash
# Compile and run console test
g++ main.cpp engine.cpp enemy.cpp object.cpp stage.cpp bullet.cpp -o console_game
./console_game
```

### Using CMake
```bash
# Build with CMake
mkdir build && cd build
cmake ..
make
./bin/InheritanceGame  # Console version
./bin/game            # GUI version (if Qt is available)
```

## Requirements

- **C++17 or higher**
- **Qt6** (for GUI version)
- **CMake** (optional, for building with CMake)
- **Linux/Windows/macOS**

## Project Structure

```
pp-2-lab-3-inheritance1/
├── README.md                    # This file
├── main.cpp                     # Console test application
├── CMakeLists.txt               # Main CMake configuration
├── game/                        # Qt GUI application
│   ├── game.pro                 # QMake project file
│   ├── gameMain.cpp             # GUI main entry point
│   ├── mainwindow.cpp           # Main window implementation
│   ├── mainwindow.h             # Main window header
│   ├── mainwindow.ui            # Qt UI layout
│   ├── resources.qrc            # Qt resource file
│   ├── background.png           # Background sprite
│   ├── player.png              # Player spaceship sprite
│   ├── enemy.png               # Enemy sprite
│   ├── bullet.png              # Bullet sprite
│   └── music.mp3               # Background music
├── engine.h                     # Game engine header
├── engine.cpp                   # Game engine implementation
├── enemy.h                      # Enemy class header
├── enemy.cpp                    # Enemy class implementation
├── player.h                     # Player class header
├── object.h                     # Base object class header
├── object.cpp                   # Base object class implementation
├── bullet.h                     # Bullet class header
├── bullet.cpp                   # Bullet class implementation
├── position.h                   # Position structure header
├── direction.h                  # Direction enum header
├── stage.h                      # Game stage header
├── stage.cpp                    # Game stage implementation
└── unit_tests/                  # Unit tests
    ├── CMakeLists.txt
    ├── engineTests.cpp
    ├── objectTests.cpp
    ├── playerTests.cpp
    └── bulletTests.cpp
```

## Class Hierarchy

```
Object (base class)
├── Player
├── Bullet
└── Enemy
```

### Key Classes

- **Object**: Base class for all game entities with position and type
- **Player**: Player spaceship with movement, shooting, and health
- **Enemy**: Enemy entities with AI movement and health system
- **Bullet**: Projectile objects with direction and movement
- **Engine**: Main game loop and collision detection
- **Stage**: Game battlefield and boundary management

## Game Balance

- **Enemy Speed**: 1 second movement intervals
- **Enemy Health**: 20 HP
- **Bullet Damage**: 7 damage per hit
- **Hits to Kill**: 3 bullets per enemy
- **Enemy Count**: Maximum 3 enemies simultaneously
- **Battlefield Size**: 20x15 grid

## Technical Features

- **Inheritance**: Object-oriented design with base/derived classes
- **Polymorphism**: Virtual methods for different entity behaviors
- **Smart Pointers**: `std::shared_ptr` for memory management
- **STL Containers**: `std::vector` for entity management
- **Modern C++**: `constexpr`, `auto`, range-based for loops
- **Qt Integration**: GUI with signals/slots and resource management
- **Collision Detection**: Grid-based collision system
- **Game Loop**: 100ms update cycle with delta time

## Build Instructions

### Quick Start (Qt GUI)
```bash
cd game
qmake
make
./game_gui
```

### Using CMake (All Platforms)
```bash
mkdir build
cd build
cmake ..
make
# Run the game:
./bin/game
```

### Manual Compilation (Console Only)
```bash
g++ -std=c++17 -Wall -Wextra main.cpp engine.cpp enemy.cpp object.cpp stage.cpp bullet.cpp -o game
./game
```

## Troubleshooting

### Qt Installation Issues
- **Ubuntu/Debian**: `sudo apt install qt6-base-dev qt6-multimedia-dev`
- **Fedora**: `sudo dnf install qt6-qtbase-devel qt6-qtmultimedia-devel`
- **Arch**: `sudo pacman -S qt6-base qt6-multimedia`

### Compilation Errors
- Ensure C++17 or higher is supported
- Check that all required Qt modules are installed
- Verify that all source files are present

### Game Not Launching
- Check that Qt libraries are in your PATH
- Try running from the build directory
- Verify that game assets (PNG files, MP3) are present

## Development Notes

This project demonstrates practical application of C++ object-oriented programming concepts:
- Clean inheritance hierarchy
- Proper encapsulation and abstraction
- Efficient memory management with smart pointers
- Event-driven programming with Qt
- Game loop architecture
- Collision detection algorithms

The codebase is structured to be educational while maintaining good software engineering practices.
