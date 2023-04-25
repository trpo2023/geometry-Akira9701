#pragma once
#include <libgeometry/parser.h>
#include <string>

#include <iostream>
#include <string>

struct ParserData {
    int pointsCount;
    int bracketsStatus;
    std::string name;
    std::string* pointsArray;
};

ParserData parser(std::string str);
