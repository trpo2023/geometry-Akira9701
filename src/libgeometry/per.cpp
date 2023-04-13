#include "checkpoints.h"
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <typeinfo>
// using namespace std;

float* space(std::string* array, int n, std::string name)
{
    float* cord = new float[2];
    if (name.compare("circle") == 0) {
        float p1 = strtof(array[0].c_str(), nullptr);
        float p2 = strtof(array[1].c_str(), nullptr);
        float s = (p2 - p1) * (p2 - p1) * 3.14;
        float p = 2 * 3.14 * (p2 - p1);
        cord[0] = p;
        cord[1] = s;

    } else if (name.compare("triangle") == 0) {
        int count = n - 1;
        float points[count * 2];
        for (int i = 0; i < count; i++) {
            std::string p1 = "";
            std::string p2 = "";
            int status = 0;
            int len = array[i].size();

            for (int j = 0; j < len; j++) {
                if (array[i][j] == ' ') {
                    status = 1;
                    continue;
                }
                if (status == 0) {
                    p1 += array[i][j];

                } else {
                    p2 += array[i][j];
                }
            }
            points[2 * i] = strtof(p1.c_str(), nullptr);
            points[2 * i + 1] = strtof(p2.c_str(), nullptr);

            // std::cout << "x - " << points[2 * i] << " y - " << points[2 * i + 1] << std::endl;
            // std::cout << 2 * i << "," << 2 * i + 1 << std::endl;
        }

        float x1 = points[0];
        float x2 = points[2];
        float x3 = points[4];
        float y1 = points[1];
        float y2 = points[3];
        float y3 = points[5];
        float a1 = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
        float a2 = sqrt(((x3 - x2) * (x3 - x2)) + ((y3 - y2) * (y3 - y2)));
        float a3 = sqrt(((x1 - x3) * (x1 - x3)) + ((y1 - y3) * (y1 - y3)));
        float p = a1 + a2 + a3;
        float polP = p / 2;
        float s = sqrt(polP * (polP - a1) * (polP - a2) * (polP - a3));
        cord[0] = p;
        cord[1] = s;
    }
    std::cout << "\t"
              << "perimetr = " << cord[0] << std::endl;
    std::cout << "\t"
              << "area = " << cord[1] << std::endl;
    std::cout << "/* message */" << std::endl;
    return cord;
}