#include "checkpoints.h"
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <typeinfo>
// using namespace std;

struct figureType {
    std::string name;
    float perimetr;
    float area;
    std::string* pointsArray;
    int pointsCount;
    int bracketsStatus;
    std::string intersect;
};

int intersect(figureType* figures, int itemsCount)
{
    int intersectsCount = 0;
    for (int i = 0; i < itemsCount; i++) {
        if (figures[i].name.compare("circle") == 0)
            for (int j = 0; j < itemsCount; j++) {
                if (j == i && figures[j].name.compare("circle") == 1) {
                    continue;
                } else if (figures[j].name.compare("circle") == 0 && j != i) {
                    float x1 = strtof(figures[i].pointsArray[0].c_str(), nullptr);
                    float y1 = strtof(figures[i].pointsArray[1].c_str(), nullptr);
                    float x2 = strtof(figures[j].pointsArray[0].c_str(), nullptr);
                    float y2 = strtof(figures[j].pointsArray[1].c_str(), nullptr);
                    float a1 = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
                    float b1 = fabs((y2 - y1) + (x2 - x1));
                    if (a1 <= b1) {
                        figures[i].intersect += ("\t\t" + std::to_string(j + 1) + ". " + figures[j].name + "\n");
                        intersectsCount++;
                    } else {
                        figures[i].intersect += "";
                    }
                }
            }
    }
    return intersectsCount;
}