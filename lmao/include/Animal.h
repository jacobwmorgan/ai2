#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>

class Animal
{
  public:
    Animal();
    std::string name;
    std::string noise;
    std::string getName(); 
    void setName(std::string name);
    std::string getNoise();
    void setNoise(std::string noise);
};
