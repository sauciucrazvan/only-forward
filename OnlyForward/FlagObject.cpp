#include "FlagObject.h"
#include "World.h"

#include <GLFW/glfw3.h>
#include <iostream>

void FlagObject::draw(int _x, int _y) {
    float flagWidth = 16, flagHeight = 20, poleHeight = flagHeight * 1.5, poleWidth = 2;
    float centerX = _x + TILE_SIZE / 2, centerY = _y + TILE_SIZE / 2;

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(centerX - flagWidth / 2 - poleWidth, centerY - flagHeight / 2);
    glVertex2f(centerX - flagWidth / 2, centerY - flagHeight / 2);
    glVertex2f(centerX - flagWidth / 2, centerY - flagHeight / 2 + poleHeight);
    glVertex2f(centerX - flagWidth / 2 - poleWidth, centerY - flagHeight / 2 + poleHeight);
    glEnd();

    float squareSize = flagWidth / 5; //black or white
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            if ((row + col) % 2 == 0) 
                glColor3f(1.0f, 1.0f, 1.0f);
            else 
                glColor3f(0.0f, 0.0f, 0.0f);
            

            float xPos = centerX - flagWidth / 2 + col * squareSize,
                  yPos = centerY - flagHeight / 2 + row * squareSize;

            glBegin(GL_QUADS);
            glVertex2f(xPos, yPos);
            glVertex2f(xPos + squareSize, yPos);
            glVertex2f(xPos + squareSize, yPos + squareSize);
            glVertex2f(xPos, yPos + squareSize);
            glEnd();
        }
    }
}
