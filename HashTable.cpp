#include "HashTable.hpp"
#include "Generator.cpp"
HashTable::HashTable(int buckets)
{
 this->buckets = buckets;
 table = new list<string>[buckets];
}

int HashTable::hash(string id)
{
 int x = 17;
 int hash = 0;

 for(int i = 0; i < id.length();i++)
 {
  hash = x * hash + id.at(i); 
 }
 return hash;
}

void HashTable::insert(string userID,string pw)
{
 //unique number gets you to location of stored pw
 int id = hash(userID);
 int bucket = id & this->buckets - 1;
 table[bucket].push_back(pw);
}


string HashTable::isMatch(string userID, string pw, string key)
{
 string password = pw;
 password = Generator::cipher(password, key);
 int id = hash(userID);
 int bucket = id & this->buckets - 1;
 string temp = ""; 
 list<string>::iterator it;
 for(it = table[bucket].begin(); it != table[bucket].end(); it++){
  if(password.compare(*it)==0) return "match";
 }
 return "no match";
}

void HashTable::fill(string filename)
{
 string line;
 string id;
 string pw;
 fstream myFile(filename.c_str());
 if(myFile.is_open())
 {
  while (myFile >> line)
  {
   id = line;
   myFile >> line;
   pw = line;
   insert(id,pw);
  }
 }
 myFile.close();
}
