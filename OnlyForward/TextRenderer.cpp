#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "TextRenderer.h"
#include <GLFW/glfw3.h>
#include <cstring>

#define STB_EASY_FONT_IMPLEMENTATION
#include "stb_easy_font.h"

TextRenderer::TextRenderer() : numQuads(0), text(nullptr) {
    vertexBuffer.resize(9999);
    setText("Hello World");
}

TextRenderer::~TextRenderer() {
    if (text) {
        delete[] text;
    }
}

void TextRenderer::setText(const char* newText) {
    if (text) {
        delete[] text;
    }
    text = new char[strlen(newText) + 1];
    strcpy(text, newText);
    numQuads = stb_easy_font_print(0, 0, text, NULL, vertexBuffer.data(), vertexBuffer.size());
}

void TextRenderer::renderText(float x, float y, float scale, float r, float g, float b) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scale, scale, 1.0f);
    glColor3f(r, g, b);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 16, vertexBuffer.data());
    glDrawArrays(GL_QUADS, 0, numQuads * 4);
    glDisableClientState(GL_VERTEX_ARRAY);
    glPopMatrix();
}
