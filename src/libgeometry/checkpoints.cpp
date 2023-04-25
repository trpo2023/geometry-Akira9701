#include "checkpoints.h"
#include <fstream>
#include <iostream>
#include <string>

int checkPoints(std::string str)
{
    int i = 0;
    int count = 0;
    while ((str)[i] != ')') {
        if ((str)[i] == ',')
            count++;
        i++;
    }
    return count;
}

void setPoint(int* c, std::string* pointsArray)
{
    (*pointsArray)[(*c)] = '0';
}
