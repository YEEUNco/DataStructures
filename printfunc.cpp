// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com

#include <iostream>
#include <string>
#include <vector>
//using namespace std;

void printfunc(int n, char *names[]) {
	for (int i = 0; i < n; i++)      // do not change i = 0 to i = 1.
		std::cout << "Hello " << names[i] << "!" << std::endl;
}

// Add another printfunc() for function overloading 
void printfunc(std::vector<std::string> names){
	for(int i=0; i<names.size(); i++){
		std::cout << "Hello " << names[i] << "!" << std::endl;
	}
}