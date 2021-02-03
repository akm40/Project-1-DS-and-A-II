#include "Generator.hpp"

Generator::Generator()
{

}
Generator::Generator(string nameFile)
{
 string line;
 ofstream newFile;
 newFile.open("raw.txt");
 fstream myFile(nameFile.c_str());
 if(myFile.is_open())
 {
  cout<<"opened file\n";
  int i = 0;
  while(myFile>>line)
  {
   if(i%4==0)
  newFile << line + '\n'; 
   i++;
  }
 
 myFile.close();
 
 }
 else
 {
  cout<<"file failed to open.\n";
 }
}
std::string Generator::getName(int key)
{
 return "fixme";

}

bool Generator::hasValidInputFile()
{
	return false;

}
