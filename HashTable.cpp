#include "HashTable.hpp"

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
 int bucket = id % this->buckets;

 table[bucket].push_back(pw);
}


string HashTable::isMatch(string userID, string pw)
{
 int id = hash(userID);
 int bucket = id % this->buckets;
 string temp = ""; 
 list<string>::iterator it;
 for(it = table[bucket].begin(); it != table[bucket].end(); it++){
  if(pw.compare(*it)==0) return "match";
 }
 return "no match";
}
