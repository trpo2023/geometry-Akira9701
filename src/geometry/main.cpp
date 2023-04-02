#include <iostream>
#include <string>
#include <fstream>
#include <libgeometry/checkpoints.h>
#include <libgeometry/per.h>

// using namespace std;



int main()
{
  std::ifstream fin;
  fin.open("data.txt");
  if (fin.is_open())
  {

    int itemCount = 1;
    while (!fin.eof())
    {
      int pointsCount = 0;

      std::string str = "";
      std::string *pt = &str;
      std::getline(fin, str);
      int c = 0;
      int bracketsStatus = 0;
      std::string name = "";
      while (str[c] >= 'a' && str[c] <= 'z')
      {
        name = name + str[c];
        c++;
      }
      if (name.compare("circle") == 0)
      {
        str[c] == '(' ? bracketsStatus = 1 : bracketsStatus = 0;
        c++;
      }
      else if (name.compare("triangle") == 0)
      {
        str[c] == '(' && str[c + 1] == '(' ? bracketsStatus = 2 : bracketsStatus = 0;
        c += 2;
      }
      else
      {
        std::cout << str << std::endl;

        std::cout << "Error at column 0: expected 'circle', 'triangle'" << std::endl;
        exit(0);
      }

      if (bracketsStatus == 0)
      {
        std::cout << str << std::endl;

        std::cout << "Error at column " << c << ": expected '('" << std::endl;
        exit(0);
      }
      pointsCount = checkPoints(pt);

      std::string *pointsArray = new std::string[pointsCount + 1];
      for (int i = 0; i < pointsCount + 1; i++)
      {
        std::string item = "";
        do
        {
          if (str[c] >= 'a' && str[c] <= 'z')
          {
            std::cout << str << std::endl;
            std::cout << "Error at column " << c << ": expected '<double>'" << std::endl;
            exit(0);
          }
          if (!(str[c] == ' ' && str[c - 1] == ','))
          {
            item = item + str[c];
          }
          c++;
        } while (str[c] != ',' && str[c] != ')');
        c++;
        pointsArray[i] = item;
      }
      c--;
      for (int i = 0; i < bracketsStatus - 1; i++)
      {
        if (str[c] != ')')
        {
          std::cout << str << std::endl;

          std::cout << "Error at column " << c << ": expected ) " << std::endl;
          exit(0);
        }
      }
      if (name.compare("triangle") == 0)
      {
        if (pointsArray[0].compare(pointsArray[pointsCount]) != 0)
        {
          std::cout << str << std::endl;
          std::cout << "Error at column " << c << " first and last points not same " << std::endl;
          exit(0);
        }
      }
      std::cout << itemCount << " - ";
      std::cout << name;
      for (int i = 0; i < bracketsStatus; i++)
      {
        std::cout << "(";
      }
      for (int i = 0; i < pointsCount + 1; i++)
      {
        if (i == pointsCount - 1)
        {
          std::cout << pointsArray[i] << ",";
        }
        else
        {
          std::cout << pointsArray[i];
        }
      }
      for (int i = 0; i < bracketsStatus; i++)
      {
        std::cout << ")";
      }
      std::cout << "\n";
      itemCount++;

      per(pointsArray, pointsCount+1, name);
      
    }
  }
  else
  {
    std::cout << "Error: wrong path file" << std::endl;
  }
  fin.close();

  return 0;
}