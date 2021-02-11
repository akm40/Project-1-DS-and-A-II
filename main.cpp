#include <iostream> 
#include "Generator.hpp"
#include "HashTable.hpp"
int main(){
 //Generator gen("lastNames.txt");
 //gen.encrypt("jones");
 HashTable myHash(10);
 myHash.insert("test","one");
 cout << myHash.isMatch("test","one");
 cout << myHash.isMatch("test","two");
 //myHash.fill("encrypted.txt");
return 0;	
}
