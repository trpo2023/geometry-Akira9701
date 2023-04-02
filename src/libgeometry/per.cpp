#include <iostream>
#include <string>
#include <fstream>
#include "checkpoints.h"
#include <typeinfo>
#include <cmath>






int per(std::string* array, int n, std::string name){
    if(name.compare("circle") == 0){
        float p1 = strtof(array[0].c_str(), nullptr);
        float p2 = strtof(array[1].c_str(), nullptr);
        float perimetr = (p2 - p1) * (p2 - p1) * 3.14;
        std::cout << perimetr << std::endl;
        return perimetr;
        
    }else if(name.compare("triangle") == 0){
        int count = n - 1;
        float points [count * 2];
        for (size_t i = 0; i < count; i++)
        {
                        
        }
        
        // float p1 = strtof(array[0].c_str(), nullptr);
        // float p2 = strtof(array[1].c_str(), nullptr);
        // float p3 = strtof(array[2].c_str(), nullptr);
        std::cout << array[0] << std::endl;

    }
    return 0;
}