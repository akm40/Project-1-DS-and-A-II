#ifndef HASHTABLE_H 
#define HASHTABLE_H
#include <iostream>
#include <list>


using namespace std;
class HashTable
{
 private:
  int buckets;
  list<string>*table;
  int hash(string);
 public:
  HashTable(int);
  void insert(string, string);
};

#endif // HASHTABLE_H
