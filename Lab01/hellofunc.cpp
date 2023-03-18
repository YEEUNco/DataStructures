

#include <iostream>
#include <string>

//using namespace std;

void printfunc(int n, char *names[]);

int main(int argc, char *argv[]) {
 
  if(argc != 1){
      char *anames[argc];
      for(int i=0; i<argc-1; i++){
        anames[i]=argv[i+1];
      }
      printfunc(argc-1, anames);
  }

  else {
    std::string name;
  
    while(true){
      std::cout << "Enter a name: ";
      std::getline(std::cin,name);
      if(name.length()==0) break;
      std::cout << "Hello " << name << "!\n";
    }
  }
  std::cout << "Hello World!\n";
  
  // if necessary use system("pause") to prevent the terminal from disappearing
// as soon as the program terminates as in Visual Studio sometimes. // system("pause");
return EXIT_SUCCESS;
}