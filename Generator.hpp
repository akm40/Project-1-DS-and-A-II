#ifndef GENERATOR_H
#define GENERATOR_H
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;
class Generator{

 public:
  Generator();
  Generator(string nameFile);
  string getName(int key);
  bool hasValidInputFile(); 
 private:
  string userID;	
  string pass;
  int rand;
};
#endif // GENERATOR_H
