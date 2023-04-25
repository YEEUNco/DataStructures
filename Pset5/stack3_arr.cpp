#include <iostream>

using namespace std;

struct Stack{
    string *item;
    int N;
    int capacity;
};

using stack = Stack*;

stack newStack(int capacity = 1){
    stack s =new Stack;
    s->item = new string[capacity];
    s-> N = 0;
    s->capacity = capacity;
    return s;
}

void free(stack s){
    delete[] s->item;
    delete s;
}

int size(stack s){
    return s->N;
}

bool empty(stack s){
    return s->N == 0;
}

void pop(stack s){
    s->N--;
    if((s->capacity)/4 == s->N){
        s->capacity = (s->capacity)/2;
        string* keep = new string[s->capacity];
        for(int i=0; i<s->N; i++){
            keep[i]=s->item[i];
        }
        delete[] s->item;
        s->item = keep;
    }
}

string top(stack s){
    return s->item[s->N-1];
}

void push(stack s, string item){
    if(s->capacity == s->N){
        s->capacity = 2*(s->capacity);
        string* keep = new string[s->capacity];
        for(int i=0; i<s->N; i++){
            keep[i] = s->item[i];
        }
        delete[] s->item;
        s->item = keep;
        
    }
    s->item[s->N++] = item;
    cout << "size:" << s->N << " capa:" << s->capacity << "\n";
}

void printStack(stack s){
    if(empty(s)) return;
    string keep=top(s);
    cout << top(s) << ' ';
    pop(s);
    printStack(s);
    push(s, keep);
}

void printStack_fromBottom(stack s){
    if(empty(s)) return;
    string keep=top(s);
    pop(s);
    printStack_fromBottom(s);
    cout << keep << ' ';
    push(s, keep);
}

int main(){
    string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};
    stack s = newStack();
    for(auto item : list){
        if(item != "-")
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