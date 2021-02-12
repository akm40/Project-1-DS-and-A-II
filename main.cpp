/************************************************
 * Andrew Mathis
 * main.cpp
 * Project 1
 *
 * Main class to run the app 
 * *********************************************/
#include <iostream> 
#include "Generator.hpp"
#include "HashTable.hpp"
int main(){
//open lastname.txt and create file raw.txt
 Generator gen("lastNames.txt");
//use raw.txt and encrypt passwords to encrypted.txt on key "jones"
 gen.encrypt("jones");
//make hashtable with 88799 buckets
 HashTable myHash(88799);
//fill the buckets with encrypted passwords on hash of userID
 myHash.fill("encrypted.txt");
//diplay isMatch function with a legal username/password and an illegal pair  
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
