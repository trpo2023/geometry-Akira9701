#include <ctest.h>
#include <fstream>
#include <iostream>
#include <libgeometry/checkpoints.h>
#include <libgeometry/per.h>
#include <stdio.h>
#include <string>

CTEST(chekponts, checkPoints)
{
    const int expected = 1;
    std::string str[1] = {"circle(0 0, 1.5)"};
    int a = checkPoints(str);
    ASSERT_EQUAL(expected, a);
}
