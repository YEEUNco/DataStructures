#include<iostream> 
#include<vector> 
using namespace std;

// gets the max value in the list and returns the reference of the max value
// your code here - define getmax() here
int& getmax(vector<int> &vec) {
    assert(vec.size() > 0);
    auto max = vec[0];
    size_t idx = 0;
    for (size_t i = 0; i < vec.size(); i++) {
        if(max < vec[i]){
            max = vec[i];
            idx = i;
        } 
    }
    return vec[idx];
}

// sets the max value to 99
// your code here - define setmax() here
void setmax(vector<int> &vec) {
    getmax(vec) = 99;
    
}


// With a given list, find the max value, then set it to 99.
int main(int argc, char *argv[]) {
    vector<int> list1 = {43, 10, 20, 75, 22, 33};
    vector<int> list2 = {33, 13, 45, 19, 39, 22};

    cout << ">list1: "; 
    for (auto x: list1) cout << x << " ";   
    cout << endl; 
    setmax(list1);
    cout << "<list1: "; 
    for (auto x: list1) cout << x << " ";   
    cout << endl << endl;

    cout << ">list2: "; 
    for (auto x: list2) cout << x << " ";   
    cout << endl; 
    setmax(list2);
    cout << "<list2: "; 
    for (auto x: list2) cout << x << " ";   
    cout << endl; 

    return 0;
}