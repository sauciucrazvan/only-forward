#include "StarObject.h"
#include "World.h"

#include <GLFW/glfw3.h>
#include <iostream>

void StarObject::draw(int _x, int _y) {
    float radius = 16;
    float centerX = _x + TILE_SIZE / 2;
    float centerY = _y + TILE_SIZE / 2;

    glBegin(GL_TRIANGLE_FAN);

    glColor3f(255 / 255.0f, 219 / 255.0f, 131 / 255.0f);
    glVertex2f(centerX, centerY);

    for (int i = 0; i <= 10; i++) {
        float angle = (i * 3.14159265358979323846 / 5.0) - (3.14159265358979323846 / 2);
        float r = (i % 2 == 0) ? radius : radius * 0.5;
        float x = centerX + r * cos(angle);
        float y = centerY + r * sin(angle) + 2;
        glVertex2f(x, y);
    }

    glEnd();
}

