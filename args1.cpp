// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
//
// Lab 2:
//	1. Using vector class in c++
//	2. ranged-for loop
//	3. function overloading
//	4. include file
//  5. not using `using namespace std;`

#include <iostream>
#include <vector>
#include <string>
//using namespace std;

void printfunc(int n, char *args[]);

int main(int argc, char *argv[]) {

	// pass one less of argc and argv. Do not change printfunc()."
	std::cout << "Invoke printfunc() to print *argv[] except 1st one \n";
	int n = argc-1;
	char *args[n];
	for(int i=0; i<n; i++){
		args[i] = argv[i+1];
	}
	
	printfunc(n, args);

	std::cout << "Copy *argv[] except 1st one into vector<string> names \n";
	// use push_back() method in the vector class
	std::vector<std::string> vnames;
	for(int i=1; i<argc; i++){
		vnames.push_back(argv[i]);
	}

	// print names only using for-loop and names
	// do not use argc/argv and ranged-for loop
	std::cout << "Print names using for-loop, but not argc/argv, ranged-for\n";
	for(int i=0; i<vnames.size(); i++){
		std::cout << "Hello " << vnames[i] << "!\n";
	}

	// print names using printfunc(vector<string>)
	// use ranged-for loop in printfunc(vector<string>)
	// do not use `using namespace std;` in printfunc.cpp 
	// cout << "Print names using printfunc(vector<string>)\n";
	// printfunc(names);

	return 0;
}
