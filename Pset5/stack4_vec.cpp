#include <iostream>
#include <vector>

using namespace std;

struct Stack{
    vector<string> item;
};

using stack = Stack*;

void free(stack s){
    delete s;
}

int size(stack s){
    return s->item.size();
}

bool empty(stack s){
    return s->item.empty();
}

void pop(stack s){
    return s->item.pop_back();
}

string top(stack s){
    return s->item.back();
}

void push(stack s, string item){
    cout << "size:" << s->item.size() << " capa:" << s->item.capacity() <<"\n";
    s->item.push_back(item);
    return;
}

void printStack(stack s){
    if(empty(s)) return;
    string keep = top(s);
    cout << top(s) << ' ';
    pop(s);
    printStack(s);
    push(s,keep);
}

void printStack_fromBottom(stack s){
    if(empty(s)) return;
    string keep = top(s);
    pop(s);
    printStack_fromBottom(s);
    cout << keep << ' ';
    push(s,keep);
}

int main(){
    string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};
    stack s = new Stack();
    for(auto item : list){
        if(item != "-")
            push(s,item);
        else {
            cout << top(s) << ' ';
            pop(s);
        }
    }
    cout << "\ns.size: " << size(s);
    cout << "\ns.top: " << top(s);
    cout << "\nThe stack is: " ;
    printStack(s);
    cout << "\nstack B: " ;
    printStack_fromBottom(s);
    cout << "\nHappy coding\n"; 
}