#include <iostream>
#include <map>
using namespace std;

int main() {
    cout << "declare a map variable called table\n"; 
    map<string, int> table;
    cout << "initialize table using array[], insert(), pair<>, make_pair()\n";
    table["Adam"]=11;
    table.insert(pair<string,int>("John", 21));
    table.insert(make_pair("Paul",15));
    table.insert(make_pair("Pete", 10));
    
    cout << "print table using range-based for loop\n"; 
    for(auto x: table){
        cout << "name: " << x.first << "\t";
        cout << "age: " << x.second << "\n";
    }
    cout << "print table using iterator\n"; 
    for(auto it=table.begin(); it != table.end(); ++it){
        cout << "name: " << it->first << "\t";
        cout << "age: " << it->second << "\n";
    }
    cout << "define and initialize chart using pair<> and make_pair() only\n"; 
    map<char, int> chart {pair<char,int>('A', 65),pair<char,int>('B',66), make_pair('C',67),make_pair('D',68)};
    cout << "print chart using range-based for loop\n"; 
    for(auto x : chart){
        cout << "ascii: " << x.first <<"\t";
        cout << "code: "<< x.second << "\n";
    }
   
    return 0;
}