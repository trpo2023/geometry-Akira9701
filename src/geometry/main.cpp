#include <fstream>
#include <iostream>
#include <libgeometry/checkpoints.h>
#include <libgeometry/intersects.h>
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
            int pointsCount = 0;
            std::string str = "";
            std::string* pt = &str;
            std::getline(fin, str);
            int c = 0;
            int bracketsStatus = 0;
            std::string name = "";
            while (str[c] >= 'a' && str[c] <= 'z') {
                name = name + str[c];
                c++;
            }
            if (name.compare("circle") == 0) {
                str[c] == '(' ? bracketsStatus = 1 : bracketsStatus = 0;
                c++;
            } else if (name.compare("triangle") == 0) {
                str[c] == '(' && str[c + 1] == '(' ? bracketsStatus = 2 : bracketsStatus = 0;
                c += 2;
            } else {
                std::cout << str << std::endl;

                std::cout << "Error at column 0: expected 'circle', 'triangle'" << std::endl;
                exit(0);
            }

            if (bracketsStatus == 0) {
                std::cout << str << std::endl;

                std::cout << "Error at column " << c << ": expected '('" << std::endl;
                exit(0);
            }
            pointsCount = checkPoints(pt);

            std::string* pointsArray = new std::string[pointsCount + 1];
            for (int i = 0; i < pointsCount + 1; i++) {
                std::string item = "";
                do {
                    if (str[c] >= 'a' && str[c] <= 'z') {
                        std::cout << str << std::endl;
                        std::cout << "Error at column " << c << ": expected '<double>'" << std::endl;
                        exit(0);
                    }
                    if (!(str[c] == ' ' && str[c - 1] == ',')) {
                        item = item + str[c];
                    }
                    c++;
                } while (str[c] != ',' && str[c] != ')');
                c++;
                pointsArray[i] = item;
            }
            c--;
            for (int i = 0; i < bracketsStatus - 1; i++) {
                if (str[c] != ')') {
                    std::cout << str << std::endl;

                    std::cout << "Error at column " << c << ": expected ) " << std::endl;
                    exit(0);
                }
            }
            if (name.compare("triangle") == 0) {
                if (pointsArray[0].compare(pointsArray[pointsCount]) != 0) {
                    std::cout << str << std::endl;
                    std::cout << "Error at column " << c << " first and last points not same " << std::endl;
                    exit(0);
                }
            }

            std::cout << "\n";
            float* data = space(pointsArray, pointsCount + 1, name);
            figures[itemCount - 1].name = name;
            figures[itemCount - 1].pointsArray = pointsArray;
            figures[itemCount - 1].pointsCount = pointsCount;
            figures[itemCount - 1].perimetr = data[0];
            figures[itemCount - 1].area = data[1];
            figures[itemCount - 1].bracketsStatus = bracketsStatus;

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
            std::cout << "\tpointsCount - " << figures[j].pointsCount << std::endl;
            std::cout << "\tbracketsStatus - " << figures[j].bracketsStatus << std::endl;
            std::cout << std::endl;
        }

    } else {
        std::cout << "Error: wrong path file" << std::endl;
    }
    fin.close();

    return 0;
}