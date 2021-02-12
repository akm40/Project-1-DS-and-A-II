/************************************************
 * Andrew Mathis
 * Generator.cpp
 * Project 1
 *
 * generate raw and encrypted files from lastNames.txt
 * *********************************************/
#include "Generator.hpp"

Generator::Generator(string nameFile)
{
 string line;
 //make and open raw.txt as well as open file passed to constructor
 ofstream newFile;
 newFile.open("raw.txt");
 fstream myFile(nameFile.c_str());
if(myFile.is_open())
 {
  cout<<"opened file\n";
  int i = 0;
  //Parse just the last name from lastname file into raw.txt
  while(myFile>>line)
  {
   if(i%4==0)
   {
    newFile << line << ' ' << makePw() + '\n'; 
   }
   i++;
  }
 
 myFile.close();
 newFile.close();
 
 }
 else
 {
  cout<<"file failed to open.\n";
 }
}
//Generate a random 9 character  password
string Generator::makePw(){
 string pw = ""; 
 for(int i = 0; i < 9; i++)
 {
  int num = rand() % 25  + 97;
  pw += (char)num;
 }

 return pw;
}
//put usernames and  encrypted passwords into new file encrypted.txt 
void Generator::encrypt(string key)
{
 string readLine;
 ofstream cryptFile;
 cryptFile.open("encrypted.txt");
 fstream rawFile("raw.txt"); 
 while(rawFile >> readLine)
 {
  cryptFile << readLine;
  cryptFile << " ";
  rawFile >> readLine;
  cryptFile << cipher(readLine, key);
  cryptFile << '\n';
 }
 cryptFile.close();
}
//encrypt password
string Generator::cipher(string pw, string key)
{
 string fullkey = key;
 string cipher = "";
 int value;
 if(pw.size() >  key.size() )
 {
  for(int i = 0; i < (pw.size() - key.size()); i++) 
   {
    fullkey += key.at(i);
   }
 }
 //go through each letter of the pass and swap letters with respect to key
 for(int i = 0; i < pw.size(); i++){
  //(char - 'a') + key if bigger than 122  - 26
  value = (pw.at(i) - 'a') + fullkey.at(i);
  if(value > 122 )
  {
   value -= 26;
  }
  char x = value; 
  cipher += x;
}
 
 return cipher; 
}
 
