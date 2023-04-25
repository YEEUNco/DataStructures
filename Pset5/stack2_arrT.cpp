#include <iostream>

using namespace std;

template <typename T>
struct Stack{
    T *item;
    int N;
    int capacity;
};

template <typename T>
using stack = Stack<T>*;

template <typename T>
stack<T> newStack(int capacity = 1){
    Stack<T>* s =new Stack<T>;
    s->item = new T[capacity];
    s-> N = 0;
    s->capacity = capacity;
    return s;
}

template <typename T>
void free(stack<T> s){
    delete[] s->item;
    delete s;
}

template <typename T>
int size(stack<T> s){
    return s->N;
}

template <typename T>
bool empty(stack<T> s){
    return s->N == 0;
}

template <typename T>
void pop(stack<T> s){
    s->N--;
    if((s->capacity)/4 == s->N){
        s->capacity = (s->capacity)/2;
        T* keep = new T[s->capacity];
        for(int i=0; i<s->N; i++){
            keep[i]=s->item[i];
        }
        delete[] s->item;
        s->item = keep;
    }
}

template <typename T>
T top(stack<T> s){
    return s->item[s->N-1];
}

template <typename T>
void push(stack<T> s, T item){
    if(s->capacity == s->N){
        s->capacity = 2*(s->capacity);
        T* keep = new T[s->capacity];
        for(int i=0; i<s->N; i++){
            keep[i] = s->item[i];
        }
        delete[] s->item;
        s->item = keep;
        
    }
    s->item[s->N++] = item;
    cout << "size:" << s->N << " capa:" << s->capacity << "\n";
}

template <typename T>
void printStack(stack<T> s){
    if(empty(s)) return;
    T keep=top(s);
    cout << top(s) << ' ';
    pop(s);
    printStack(s);
    push(s, keep);
}

template <typename T>
void printStack_fromBottom(stack<T> s){
    if(empty(s)) return;
    T keep=top(s);
    pop(s);
    printStack_fromBottom(s);
    cout << keep << ' ';
    push(s, keep);
}

int main(){
    //string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};
    int list[] = {1,2,3,4,5,0,6,0,0,7,0,0,0,8};
    stack<int> s = newStack<int>();
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