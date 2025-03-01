#include <GLFW/glfw3.h>

#include "World.h"
#include "Exception.h"

#include <iostream>
#include <stack>
#include <vector>
#include <random>

World::World() {
    this->generateMaze();
}

void World::drawTileMap() {
    glClear(GL_COLOR_BUFFER_BIT);
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            Tile* tile = tileMap[y][x];

            float xPos = x * TILE_SIZE;
            float yPos = y * TILE_SIZE;

            glColor3f(tile->red, tile->green, tile->blue);

            glBegin(GL_QUADS);
            glVertex2f(xPos, yPos);
            glVertex2f(xPos + TILE_SIZE, yPos);
            glVertex2f(xPos + TILE_SIZE, yPos + TILE_SIZE);
            glVertex2f(xPos, yPos + TILE_SIZE);
            glEnd();

            if (tile->object != nullptr) {
                glPushMatrix();
                tile->object->draw(xPos, yPos);
                glPopMatrix();
            }
        }
    }
}

bool World::collideCheckOnTile(int x, int y) {
    char buf[256];
    try {
        if (x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT) {
            sprintf_s(buf, "Out-of-bounds tile access at (%d, %d)", x, y);
            throw Exception((char*) "OUT-OF-BOUNDS", (char*) buf);
            return false;
        }

        if (!tileMap[y][x]) {
            sprintf_s(buf, "Trying to access uninitialized tile at (%d, %d)", x, y);
            throw Exception((char*) "UNINITIALIZED", (char*) buf);
            return false;
        }

        tileMap[y][x]->onCollide();

        return tileMap[y][x]->collidable;
    }
    catch (Exception e) {
        e.Print();
        return false;
    }
}

/* dfs algorithm, should be used to generate the static levels and the random ones, later on */
void World::generateMaze() {
    srand(time(0));

    bool visited[MAP_HEIGHT][MAP_WIDTH] = { false };

    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            tileMap[y][x] = new BarrierTile();
        }
    }

    int startX = (MAP_WIDTH / 2 - 1), 
        startY = (MAP_HEIGHT / 2 - 1);

    int endY = rand() % MAP_HEIGHT,
        endX = (rand() % 2 == 0) ? 0 : (MAP_WIDTH - 1);

    visited[startY][startX] = true;
    visited[endY][endX] = true;

    tileMap[startY][startX] = new GrassTile();
    tileMap[endY][endX] = new FlagTile();

    std::vector<std::pair<int, int>> stack;
    stack.push_back({ startY, startX });

    while (!stack.empty()) {
        int cy = stack.back().first;
        int cx = stack.back().second;
        stack.pop_back();

        int directions[4][2] = { {0, -2}, {2, 0}, {0, 2}, {-2, 0} };
        std::shuffle(std::begin(directions), std::end(directions), std::default_random_engine(rand()));

        for (int d = 0; d < 4; ++d) {
            int ny = cy + directions[d][1];
            int nx = cx + directions[d][0];

            if (nx >= 0 && nx < MAP_WIDTH && ny >= 0 && ny < MAP_HEIGHT && !visited[ny][nx]) {
                visited[cy][cx] = true;
                visited[ny][nx] = true;

                tileMap[(cy + ny) / 2][(cx + nx) / 2] = new GrassTile();
                tileMap[ny][nx] = new GrassTile();

                stack.push_back({ cy, cx });
                stack.push_back({ ny, nx });
                break;
            }
        }
    }

    int patchSize = 1;
    int patches = MAP_WIDTH * MAP_HEIGHT / 100;
    for (int i = 1; i < patches; ++i) {
        int x = rand() % (MAP_WIDTH - patchSize);
        int y = rand() % (MAP_HEIGHT - patchSize);

        for (int py = y; py < y + patchSize; ++py) {
            for (int px = x; px < x + patchSize; ++px) {
                GrassTile* grassTile = dynamic_cast<GrassTile*>(tileMap[py][px]);
                if (grassTile) {
                    tileMap[py][px] = new StarTile();
                }
            }
        }
    }
}