#include <iostream> 
#include "Generator.hpp"
#include "HashTable.hpp"
int main(){
 //Generator gen("lastNames.txt");
 //gen.encrypt("jones");
 HashTable myHash(88799);
 myHash.fill("encrypted.txt");
 cout << myHash.isMatch("SMITH","rzptktzec");

return 0;	
}
