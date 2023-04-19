#pragma once

#include <iostream>
#include <string>

struct figureType {
    std::string name;
    float perimetr;
    float area;
    std::string* pointsArray;
    int pointsCount;
    int bracketsStatus;
    std::string intersect;
};

int intersect(figureType* figures, int itemsCount);
