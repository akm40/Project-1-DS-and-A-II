#include <iostream> 
#include "../Generator.hpp"

int main(){
	Generator gen;
	if(gen.getName(0) == "SMITH"){
	std::cout << "generated name SMITH.\n";
	}
	else{
	std::cout << "did not generate name SMITH.\n";
	}
	return 0;	
}
