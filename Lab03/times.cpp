#include<iostream> 
#include<vector> 
using namespace std;

#if 1
// mulitply even number elements in the list by 10 // without using reference variable.
int main(int argc, char *argv[]) {
    vector<int> list = { 0, 1, 2, 2, 4, 5, 6, 7, 8, 8, 10 }; 
    for (size_t i = 0; i < list.size(); i++) {
        if(list[i]%2==0) list[i]*=10;
    }
    for (auto x: list) cout << x << " "; 
    cout << endl;
    return 0;
}

#else
// mulitply even number elements in the list by 10 // using reference variable.
int main(int argc, char *argv[]) {
    vector<int> list = { 0, 1, 2, 2, 4, 5, 6, 7, 8, 8, 10 }; 
    cout << "your code here\n";
    for (auto x: list) cout << x << " ";
    return 0; 
}
#endif