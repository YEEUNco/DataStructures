// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
//
// Lab 2:
//	1. vector class in c++
//	2. ranged-for loop
//	3. function overloading
//	4. include file
//  5. not using `using namespace std;`
//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: 이예은 Student Number: 22200550
#include <iostream>
#include <vector>
#include <string>

//using namespace std;
void printfunc(int n, char *args[]);
void printfunc(std::vector<std::string> names);

int main(int argc, char **argv) {

	std::cout << "Print using printfunc(**argv) \n";
	int n = argc-1;
	char *args[n];
	for(int i=0; i<n; i++){
		args[i] = argv[i+1];
	}
	
	printfunc(n, args);

	std::cout << "Copy using vector<string> \n";
	// use push_back() method in the vector class
	std::vector<std::string> vnames;
	for(int i=1; i<argc; i++){
		vnames.push_back(argv[i]);
	}

	// print names only using for-loop and names
	// do not use argc/argv and ranged-for loop
	std::cout << "Print names using indexing, but not argc/argv, ranged-for\n";
	for(int i=0; i<vnames.size(); i++){
		std::cout << "Hello " << vnames[i] << "!\n";
	}
	
	std::cout << "Print names using printfunc(vector<string> n)" << std::endl;
	printfunc(vnames);
	return 0;
}
