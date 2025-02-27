#pragma once

#include <vector>
#include <string>

class TextRenderer {
public:
    TextRenderer(); ~TextRenderer();
    void setText(const char* newText);
    void renderText(float x, float y, float scale, float r, float g, float b);

private:
    std::vector<float> vertexBuffer;
    int numQuads; char* text;
};