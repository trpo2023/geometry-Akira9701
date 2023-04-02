#include <iostream>
#include <string>
#include <fstream>
#include "checkpoints.h"
#include <typeinfo>






int per(std::string* array, int n, std::string name){
    if(name.compare("circle") == 0){
        float p1 = strtof(array[0].c_str(), nullptr);
        float p2 = strtof(array[1].c_str(), nullptr);
        std::cout << (p2 - p1) * (p2 - p1) * 3.14 << std::endl;
        
    }
    return 0;
}