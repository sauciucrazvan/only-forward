# OnlyForward

[![Badge](https://img.shields.io/badge/version-1.0-dark_green?style=for-the-badge)](https://github.com/sauciucrazvan/only-forward/releases)
[![Badge](https://img.shields.io/github/stars/sauciucrazvan/only-forward?style=for-the-badge)](https://github.com/sauciucrazvan/only-forward/stargazers)
[![Badge](https://img.shields.io/github/issues/sauciucrazvan/only-forward?style=for-the-badge)](https://github.com/sauciucrazvan/only-forward/issues)
[![Badge](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](https://opensource.org/licenses/MIT)

The <b>OnlyForward</b> project is a puzzle game developed in C++ with OpenGL, where the player controls a snake that must navigate a maze to achieve the highest possible score. The goal of the game is to reach the end of the level without getting stuck, earning points by completing levels quickly and collecting bonus items.

The mazes are complex structures that challenge players' logic and strategy. The game <b>OnlyForward</b> introduces a unique mechanic where the player cannot move back onto a tile they have already stepped on, unless they reset the level.

## Technologies Used
- Programming Language: C++ (Compiler: MSVC)
- Graphics Library: OpenGL
- IDE: Visual Studio Community 2022
- Source Control: Git

![Technologies](https://skillicons.dev/icons?i=cpp,visualstudio,git,opengl)

## Launch and Runtime Requirements
The following packages are required to run the game:
- <a href="https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-170">Microsoft Visual C++ Redistributable</a>
- <a href="https://www.microsoft.com/en-us/download/details.aspx?id=35">DirectX Runtime</a>

All game files must be present in the same folder as the executable for proper functionality.

## Player Controls
- W, A, S, D – Move in the desired direction
- R – Reset level (will give a score penalty)
> [!CAUTION]
> The player cannot move back onto the path already traveled (this path is marked in light green, different from the other colors)

## Adding a custom level
1. <b>CTRL+R</b> – Generate a new level
2. The generated level must be manually checked to ensure it is completable
3. <b>V</b> – Save level
4. The file <b>'level.out'</b> contains the tile IDs of the level
5. To add a custom level, the contents of <b>'level.out'</b> must be copied into the Levels folder and saved as <b>X.leveldata</b>, where X is the number of the next level.

> [!NOTE]
> The finish tile (ID: 1) should be included and reachable in the leveldata file to be able to complete the level.

## Snapshots

<details>
  <summary>Expand to view snapshots</summary>
  <image src="https://i.imgur.com/Q9soIBa.png" width="175" />
  <image src="https://i.imgur.com/P5NggNf.png" width="300" />
  <image src="https://i.imgur.com/vIoe5ai.png" width="300" />
</details>
