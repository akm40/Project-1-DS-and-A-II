#include <iostream> 
#include "Generator.hpp"
#include "HashTable.hpp"
int main(){
 Generator gen("lastNames.txt");
 gen.encrypt("jones");
 HashTable myHash(88799);
 myHash.fill("encrypted.txt");
// cout << myHash.isMatch("SMITH","rzptktzec");
 
 cout << "Legal:\nUserid	Password	Result\nSMITH	asdfvfrty	" << myHash.isMatch("SMITH", "ilcpsklry", "jones");
 

return 0;	
}
