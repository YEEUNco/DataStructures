

#include <iostream>
#include <string>

//using namespace std;
int main() {
  // if necessary, use setvbuf() to prevent the output from buffered on console.
  // setvbuf(stdout, NULL, _IONBF, 0);
  std::string name;
  
  while(true){
    std::cout << "Enter a name: ";
    std::getline(std::cin,name);
    if(name.length()==0) break;
    std::cout << "Hello " << name << "!\n";
  }
  std::cout << "Hello world!\n";
  
  // if necessary use system("pause") to prevent the terminal from disappearing
// as soon as the program terminates as in Visual Studio sometimes. // system("pause");
return EXIT_SUCCESS;
}