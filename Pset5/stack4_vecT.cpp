#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct Stack{
    vector<T> item;
};

template <typename T>
using stack = Stack<T>*;

template <typename T>
void free(stack<T> s){
    delete s;
}

template <typename T>
int size(stack<T> s){
    return s->item.size();
}

template <typename T>
bool empty(stack<T> s){
    return s->item.empty();
}

template <typename T>
void pop(stack<T> s){
    return s->item.pop_back();
}

template <typename T>
T top(stack<T> s){
    return s->item.back();
}

template <typename T>
void push(stack<T> s, T item){
    cout << "size:" << s->item.size() << " capa:" << s->item.capacity() <<"\n";
    s->item.push_back(item);
    return;
}

template <typename T>
void printStack(stack<T> s){
    if(empty(s)) return;
    T keep = top(s);
    cout << top(s) << ' ';
    pop(s);
    printStack(s);
    push(s,keep);
}

template <typename T>
void printStack_fromBottom(stack<T> s){
    if(empty(s)) return;
    T keep = top(s);
    pop(s);
    printStack_fromBottom(s);
    cout << keep << ' ';
    push(s,keep);
}

int main(){
    //string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};
    int list[] = {1,2,3,4,5,0,6,0,0,7,0,0,0,8};
    stack<int> s = new Stack<int>();
    for(auto item : list){
        if(item != 0)
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
    cout << "\nHappy Coding\n"; 
}