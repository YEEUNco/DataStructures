#include <iostream>
#include <stack>

using namespace std;

void printStack(stack<string> s){
    if(s.empty()) return;
    string keep=s.top();
    cout << s.top() << ' ';
    s.pop();
    printStack(s);
    s.push(keep);
}


void printStack_fromBottom(stack<string> s){
    if(s.empty()) return;
    string keep=s.top();
    s.pop();
    printStack_fromBottom(s);
    cout << keep << ' ';
    s.push(keep);
}


int main(){
    //int list[] = {1,2,3,4,5,0,6,0,0,7,0,0,0,8};
    string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};

    stack<string> s;
    for(auto item : list){
        if(item != "-")
            s.push(item);
        else {
            cout << s.top() << ' ';
            s.pop();
        }
    }
    cout << "\nsize: " << s.size();
    cout << "\ntop: " << s.top();
    cout << "\nstack T: " ;
    printStack(s);
    cout << "\nstack B: " ;
    printStack_fromBottom(s);
    cout << "\nHappy coding\n"; 
}

