#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include "Animal.h"

Animal::Animal()
{
  std::string name;
  std::cout << "Name:";
  std::cin >> name;
  Animal::setName(name);
  std::string noise;
  std::cout << "\nNoise :";
  std::cin >> noise ;
  Animal::setNoise(noise);
}

std::string Animal::getName(){return name;}

void Animal::setName(std::string _name){name = _name;}

std::string Animal::getNoise(){return noise;}

void Animal::setNoise(std::string _noise){noise = _noise;}
