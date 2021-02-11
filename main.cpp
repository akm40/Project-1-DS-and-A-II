#include <iostream> 
#include "Generator.hpp"
#include "HashTable.hpp"
int main(){
 Generator gen("lastNames.txt");
 gen.encrypt("jones");
 HashTable myHash(88799);
 myHash.fill("encrypted.txt");
// cout << myHash.isMatch("SMITH","rzptktzec");
 
 cout << "Legal:";
 cout << "\nUserid  	Password	        Result";
 cout << "\nSMITH		asdfvfrty		" << myHash.isMatch("SMITH", "ilcpsklry", "jones");
 cout << "\nJOHNSON		vmcpjnbpb		" << myHash.isMatch("JOHNSON", "vmcpjnbpb", "jones");
 cout << "\nWILLIAMS        wllsrehfm		" << myHash.isMatch("WILLIAMS", "wllsrehfm","jones");
 cout << "\nJONES		xrkecwitr		" << myHash.isMatch("JONES","xrkecwitr","jones");
 cout << "\nBROWN		sglrexvtj		" << myHash.isMatch("BROWN","sglrexvtj","jones");
 cout << "\nDAVIS		mxypunbqf		" << myHash.isMatch("DAVIS","mxypunbqf","jones");
 cout << "\n\nILLegal:";
 cout << "\nUserid  	Password                 Result";
 cout << "\nSMITH	        xsdfvfrty		" << myHash.isMatch("SMITH","xsdfvfrty","jones");
 cout << "\nJOHNSON		xmcpjnbpb		" << myHash.isMatch("JOHNSON", "xmcpjnbpb", "jones");
 cout << "\nWILLIAMS        xllsrehfm		" << myHash.isMatch("WILLIAMS", "xllsrehfm","jones");
 cout << "\nJONES		xxkecwitr		" << myHash.isMatch("JONES","xxkecwitr","jones");
 cout << "\nBROWN		xglrexvtj		" << myHash.isMatch("BROWN","xglrexvtj","jones");
 cout << '\n';
return 0;	
}
