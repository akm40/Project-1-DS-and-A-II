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
  Generator(string);
  void encrypt(string);
 private:
  string userID;	
  string pass;
  string makePw();
  string key;
  string cipher(string);
};
#endif // GENERATOR_H
