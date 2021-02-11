#ifndef HASHTABLE_H 
#define HASHTABLE_H
#include <iostream>
#include <fstream>
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
  string isMatch(string, string, string);
  void fill(string);
};

#endif // HASHTABLE_H
