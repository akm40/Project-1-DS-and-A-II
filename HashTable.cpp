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

//void HashTable::getPw(string userID)
