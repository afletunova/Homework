#pragma once

#include <array>

class Terrain
{
public:
    Terrain();
    ~Terrain();

    void draw();

private:
    const static int size = 1024;
    std::array<int, size> vertices;

    void generateHeights(const int step, const int middle);

    const int height = 300;
    const int minStep = 8;
    const int percent = 25;
};

