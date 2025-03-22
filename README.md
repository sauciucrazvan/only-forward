# OnlyForward

The "OnlyForward" project is a puzzle game developed in C++, where the player controls a snake that must navigate a maze to achieve the highest possible score. The goal of the game is to reach the end of the level without getting stuck, earning points by completing levels quickly and collecting bonus items.

The mazes are complex structures that challenge players' logic and strategy. The game "OnlyForward" introduces a unique mechanic where the player cannot move back onto a tile they have already stepped on, unless they reset the level.

## Technologies Used
- Programming Language: C++ (Compiler: MSVC)
- Graphics Library: OpenGL
- IDE: Visual Studio Community 2022

## Launch and Runtime Requirements
The following packages are required to run the game:
- Microsoft Visual C++ Redistributable
- DirectX Runtime
- Standard C++ Libraries

All game files must be present in the same folder as the executable for proper functionality.

## Player Controls
- W, A, S, D – Move in the desired direction
- R – Reset level (will give a score penalty)
- Important rule: The player cannot move back onto the path already traveled (this path is marked in light green, different from the other colors)

## Adding a custom level
• <b>CTRL+R</b> – Generate a new level
• The generated level must be manually checked to ensure it is completable
• <b>V</b> – Save level
• The file <b>'level.out'</b> contains the tile IDs of the level
• To add a custom level, the contents of <b>'level.out'</b> must be copied into the Levels folder and saved as <b>X.leveldata</b>, where X is the number of the next level.
