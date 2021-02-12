/************************************************
 * Andrew Mathis
 * HashTable.hpp
 * Project 1
 *
 * Class for making a hashtable and storing the userID and password 
 * *********************************************/
#include "HashTable.hpp"
HashTable::HashTable(int buckets)
{
 this->buckets = buckets;
 table = new list<string>[buckets];
}
//create a hash of each userID
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
//inerts passwords into buckets
void HashTable::insert(string userID,string pw)
{
 //unique number gets you to location of stored pw
 int id = hash(userID);
 int bucket = id & this->buckets - 1;
 table[bucket].push_back(pw);
}

//check if username/password is invalid
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
//takes a file of username and encrypted passwords and puts them all into the hashtable
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
