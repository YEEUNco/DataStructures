#include <iostream>

using namespace std;

struct Stack{
    int *item;
    int N;
    int capacity;
};

using stack = Stack *;

stack newStack(int capacity){
    stack s = new Stack;
    s -> item = new int[capacity];
    s -> N = 0;
    s -> capacity = capacity;
    return s;
}

void free(stack s){
    delete[] s ->item;
    delete s;
}

int size(stack s){
    return s->N;
}

bool empty(stack s){
    return s->N == 0;
}

void pop(stack s){
    s->N --;
    return;
}

int top(stack s){
    return s -> item[s->N-1];
}

void push(stack s, int item){
    s->item[s->N++] = item;
}

void printStack(stack s){
    if(empty(s)) return;
    int keep=top(s);
    cout << top(s) << ' ';
    pop(s);
    printStack(s);
    push(s, keep);
}

void printStack_fromBottom(stack s){
    if(empty(s)) return;
    int keep=top(s);
    pop(s);
    printStack_fromBottom(s);
    cout << keep << ' ';
    push(s, keep);
}

int main(){
    //string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};
    int list[] = {1,2,3,4,5,0,6,0,0,7,0,0,0,8};
    stack s = newStack(sizeof(list)/sizeof(int));
    for(auto item : list){
        if(item != 0)
            push(s,item);
        else {
            cout << top(s) << ' ';
            pop(s);
        }
    }
    cout << "\nsize: " << size(s);
    cout << "\ntop: " << top(s);
    cout << "\nstack T: " ;
    printStack(s);
    cout << "\nstack B: " ;
    printStack_fromBottom(s);
    cout << "\nHappy coding\n"; 
}