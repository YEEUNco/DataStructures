

#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
using namespace std;
// size of circular queue, a magic number
//const int SIZE = 5;
struct CircularQueue {
  string *items;
  int front;
  int back;
  int capa;
};

using cqueue = CircularQueue *;

cqueue newCircularQueue(int capa=1){
  cqueue q = new CircularQueue;
  q->items = new string[capa];
  q->front = -1;
  q->back = -1;
  q->capa = capa;
  return q;
}

int size(cqueue q){
    //cout << q->front << " " << q->back << "**\n";
    if(q->front == -1) return 0;
    if(q->front < q-> back) return (q->back)-(q->front)+1;
    else return (q->capa)-(q->front) + q->back +1;
    
}

void resize(cqueue q, int new_capacity){
    string *copied = new string[new_capacity];
    int qsize = size(q);
    //cout << qsize << "&&";
    int k=0;
    if(q->front < q->back){
        for(int i=0; i<qsize; i++){
            copied[i] = q->items[q->front+i];
        }
    }
    else {
        for(int i=0; i<qsize; i++){
            if(q->front+i < q->capa){
                copied[i] = q->items[i+q->front];

            }
            else {
                copied[i] = q->items[q->back+k];
                k++;
            }
        }
    }
    delete[] q->items;
    q->items = copied;
    q->back = q->capa-1;
    q->capa = new_capacity;
    q->front = 0;
   

}

bool full(cqueue q){
  if (q->front == 0 && q->back == q->capa - 1) return true;
  if (q->front == q->back + 1) return true;
  return false;
}

bool empty(cqueue q){
  if (q->front == -1) return true;
  return false;
}

void enqueue(cqueue q, string item){
    if(full(q)){
        resize(q, (q->capa)*2);
    }
    if(q->front == -1) q->front = 0;
    q->back = (q->back + 1) % q->capa;
    q->items[q->back] = item;
    cout << "enqueued: " << item << endl;

}

string dequeue(cqueue q){
    if (empty(q)){
        cout << "Queue is empty" << endl;
        return ""; 
    }
    string item = q->items[q->front];
    if(q->front == q->back){
        q->front = -1;
        q->back = -1;
    } // q has only one item, we reset the q after deleting it.
    else {
        q->front=(q->front + 1) % q->capa;
    }
    return item;
}

void display(cqueue q) { // display cqueue status
    int i;
    if(empty(q))
        cout << endl << "Empty Queue" << endl;
    else {
        cout << "Front:Back = [" << q->front << ":" << q->back << "]\n";
        cout << "Items:[ ";
        if(q->front < q->back){
            for( i = q->front; i ! q->back; i = i + 1){
                cout << q->items[i] << ' ';
            }
        }
        else {
            for(i=q->front; i <q->capa; i++){
                cout << q->items[i] << ' ';
        }
        for(i=0; i<q->back; i++){
            cout << q->items[i] << ' ';
        }
    }
   // cout << q->items[i];
    cout << "]\n";
    assert(i<=q->capa);
    } 

}


int main() {
    cqueue q = newCircularQueue();
    dequeue(q);
    enqueue(q, "a");
    enqueue(q, "b");
    enqueue(q, "c");
    enqueue(q, "d");
    enqueue(q, "e");
    enqueue(q, "f");
    display(q);
    string item = dequeue(q);
    cout << "dequeued: " << item << endl;
    display(q);
    enqueue(q, "g");
    display(q);
    enqueue(q, "h");
    dequeue(q);
    dequeue(q);
    display(q);
    
    return 0; 
}
