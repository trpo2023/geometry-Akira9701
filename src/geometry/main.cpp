#include <fstream>
#include <iostream>
#include <libgeometry/checkpoints.h>
#include <libgeometry/intersects.h>
#include <libgeometry/parser.h>
#include <libgeometry/per.h>
#include <string>

int main()
{
    std::ifstream fin;

    fin.open("data.txt");

    if (fin.is_open()) {
        int itemCount = 1;
        figureType figures[10];
        while (!fin.eof()) {
            std::string str = "";
            std::string* pt = &str;
            std::getline(fin, str);
            ParserData textData = parser(str);
            std::cout << str << " " << *pt << std::endl;
            // std::cout << textData.name << "\n";

            std::cout << "\n";
            float* data = space(textData.pointsArray, textData.pointsCount + 1, textData.name);
            figures[itemCount - 1].name = textData.name;
            figures[itemCount - 1].pointsArray = textData.pointsArray;
            figures[itemCount - 1].pointsCount = textData.pointsCount;
            figures[itemCount - 1].perimetr = data[0];
            figures[itemCount - 1].area = data[1];
            figures[itemCount - 1].bracketsStatus = textData.bracketsStatus;

            itemCount++;
        }

        intersect(figures, itemCount - 1);

        for (int j = 0; j < itemCount - 1; j++) {
            std::cout << j + 1 << " - ";
            std::cout << figures[j].name;
            for (int i = 0; i < figures[j].bracketsStatus; i++) {
                std::cout << "(";
            }
            for (int i = 0; i < figures[j].pointsCount + 1; i++) {
                if (i == figures[j].pointsCount - 1) {
                    std::cout << figures[j].pointsArray[i] << ",";
                } else {
                    std::cout << figures[j].pointsArray[i];
                }
            }
            for (int i = 0; i < figures[j].bracketsStatus; i++) {
                std::cout << ")";
            }
            std::cout << std::endl;
            std::cout << "\tperimetr - " << figures[j].perimetr << std::endl;
            std::cout << "\tarea - " << figures[j].area << std::endl;
            std::cout << "\tintersects" << std::endl;
            std::cout << figures[j].intersect << std::endl;
            // std::cout << "\tpointsCount - " << figures[j].pointsCount << std::endl;
            // std::cout << "\tbracketsStatus - " << figures[j].bracketsStatus << std::endl;
            std::cout << std::endl;
        }

    } else {
        std::cout << "Error: wrong path file" << std::endl;
    }
    fin.close();

    return 0;
}