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
string Generator::makePw(){
 string pw = ""; 
 for(int i = 0; i < 9; i++)
 {
  int num = rand() % 25  + 97;
  pw += (char)num;
 }

 return pw;
}

void Generator::encrypt(string key)
{
 string readLine;
 ofstream cryptFile;
 cryptFile.open("encrypted.txt");
 this->key = key;
 fstream rawFile("raw.txt"); 
 while(rawFile >> readLine)
 {
  cryptFile << readLine;
  cryptFile << " ";
  rawFile >> readLine;
  cryptFile << cipher(readLine);
  cryptFile << '\n';
 }
 cryptFile.close();
}
string Generator::cipher(string pw)
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
 
