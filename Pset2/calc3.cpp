#include <iostream>
#include <sstream>
using namespace std;

int add(int a, int b){return a+b;}
int mul(int a, int b){return a*b;}
int sub(int a, int b){return a-b;}
int dvd(int a, int b){if(b!=0) return a/b; else return 0;}

int get_int(){
    int x;
    do {
        cout << "Enter an integer: ";
        string str;
        getline(cin,str);
        try{
            x = stoi(str);
            break;
        }
        catch (invalid_argument& e){
            cerr << e.what() << " error occured. Retry~" << endl;
        }
    }while(true);
    return x;
}

pair<char,int> get_op(string opstr){
    char op;
    size_t x;
    do{
        stringstream ss;
        string str;
        cout << "Enter an operator( " << opstr << "): ";
        getline(cin, str);
        ss << str;
        ss >> op;
        x = opstr.find(op);
    }while(x==string::npos);
    return pair<char,int>(op,x);
}

int main(){
    int (*fp[])(int, int)={add,sub,mul,dvd};
    string opstr{ "+-*/"};

    int a {get_int()};
    pair<char, int> op {get_op("{+-*/}")};
    int b {get_int()};
    
    cout  << a << " " <<op.first<<" " << b << " = " << fp[op.second-1](a,b) <<  "\n";

    return 0;
}
