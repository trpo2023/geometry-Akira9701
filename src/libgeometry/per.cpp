#include "checkpoints.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <typeinfo>

int per(std::string* array, int n, std::string name)
{
    if (name.compare("circle") == 0) {
        float p1 = strtof(array[0].c_str(), nullptr);
        float p2 = strtof(array[1].c_str(), nullptr);
        float perimetr = (p2 - p1) * (p2 - p1) * 3.14;
        std::cout << perimetr << std::endl;
        return perimetr;

    } else if (name.compare("triangle") == 0) {
        int count = n - 1;
        float points[count * 2];
        for (size_t i = 0; i < count; i++) {
            std::string p1 = "";
            std::string p2 = "";
            int status = 0;
            for (size_t j = 0; j < array[i].length(); j++) {
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
            points[i] = strtof(p1.c_str(), nullptr);
            points[i + 1] = strtof(p2.c_str(), nullptr);

            // std::cout << points[i] << " " << points[i + 1] << std::endl;
        }
        float s = sqrt((points[2] - points[0]) * (points[2] - points[0]) + (points[3] - points[1]) * (points[3] - points[1]))
                // + sqrt((points[4] - points[0]) * (points[4] - points[0]) + (points[5] - points[1]) * (points[5] - points[1]))
                // + +sqrt((points[4] - points[2]) * (points[4] - points[2]) + (points[5] - points[3]) * (points[5] - points[3]))
                ;
        std::cout << s << std::endl;
    }
    return 0;
}