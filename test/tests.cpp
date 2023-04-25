#include <cmath>
#include <ctest.h>
#include <fstream>
#include <iostream>
#include <libgeometry/checkpoints.h>
#include <libgeometry/intersects.h>
#include <libgeometry/parser.h>
#include <libgeometry/per.h>

#include <stdio.h>
#include <string>

CTEST(tesChekpoints, checkPoints)
{
    const int expected = 1;
    std::string str = "circle(0 0, 1.5)";
    int a = checkPoints(str);
    ASSERT_EQUAL(expected, a);
}

CTEST(parser_test, parser)
{
    std::string str = "circle(0 0, 1.5)";
    ParserData p1;
    p1.name = "circle";
    std::string x1 = "0 0";
    std::string x2 = "1.5";
    std::string array[2] = {x1, x2};
    p1.pointsArray = array;
    p1.bracketsStatus = 1;
    p1.pointsCount = 1;
    ParserData test = parser(str);
    ASSERT_EQUAL(p1.bracketsStatus, test.bracketsStatus);
    ASSERT_EQUAL(p1.pointsCount, test.pointsCount);
    ASSERT_TRUE(p1.pointsArray[0] == test.pointsArray[0]);
    ASSERT_TRUE(p1.pointsArray[1] == test.pointsArray[1]);
    ASSERT_TRUE(p1.name == test.name);
    // ASSERT_EQUAL(p1.pointsCount, test.pointsCount);
}

CTEST(data_of_circle, space)
{
    const float expectedPer = 9.42;
    const float expectedArea = 7.065;
    std::string str[2] = {"0 0", "1.5"};
    float* a = space(str, 2, "circle");
    ASSERT_DBL_NEAR_TOL(expectedPer, a[0], 0.001);
    ASSERT_DBL_NEAR_TOL(expectedArea, a[1], 0.001);
}
CTEST(data_of_triange, space)
{
    const float expectedPer = 9.657;
    const int expectedArea = 4;
    std::string str[4] = {"-3 -2", "-1 0", "-3 2", "-3 -2"};
    float* a = space(str, 4, "triangle");
    ASSERT_DBL_NEAR_TOL(expectedPer, a[0], 0.001);
    ASSERT_DBL_NEAR_TOL(expectedArea, a[1], 0.001);
}

CTEST(intersects_of_circles, intersect)
{
    const float expectedCount = 6;
    figureType p1;
    p1.name = "circle";
    std::string str1[2] = {"00", "1.5"};
    p1.pointsArray = str1;
    p1.perimetr = 9.42;
    p1.area = 7.065;
    p1.intersect = "";
    p1.pointsCount = 1;
    figureType p2;
    p2.name = "circle";
    std::string str2[2] = {"3.14", "4.64"};
    p2.pointsArray = str2;
    p2.perimetr = 9.42;
    p2.area = 7.065;
    p2.intersect = "";
    p2.pointsCount = 1;
    figureType p3;
    p3.name = "circle";
    std::string str3[2] = {"2.14", "3.64"};
    p3.pointsArray = str3;
    p3.perimetr = 9.42;
    p3.area = 7.065;
    p3.intersect = "";
    p3.pointsCount = 1;
    figureType figures[3] = {p1, p2, p3};
    int a = intersect(figures, 3);
    ASSERT_EQUAL(expectedCount, a);
}
