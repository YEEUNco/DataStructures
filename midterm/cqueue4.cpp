

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
  int capa;     //total capacity of the queue
  string dash;  // dash - a place holder string
  bool doubling;    // if true, increase capacity by2x, otherwise by 10
  int incr;         // if doubling is false, increase capacity by incr
  int shown;        // the max number of items to show
};

using cqueue = CircularQueue *;

cqueue newCircularQueue(int capa = 4, int shown=32){
  cqueue q = new CircularQueue;
  q->items = new string[capa];
  q->front = -1;
  q->back = -1;
  q->capa = capa;
  for(int i=0; i<capa; i++){
    q->items[i] = '-';
  }
  q->doubling = true;
  q->shown = shown;
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
    for(int i=0; i<new_capacity; i++){
        copied[i] = '-';
    }
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
    q->back = qsize-1;
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
        if(q->doubling == true){
            resize(q, (q->capa)*2);
        }
        else {
            resize(q, (q->capa)+q->incr);
        }
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
    q->items[q->front] = '-';
    if(q->front == q->back){
        q->front = -1;
        q->back = -1;
    } // q has only one item, we reset the q after deleting it.
    else {
        q->front=(q->front + 1) % q->capa;
    }
    
    if(q->doubling == true && q->capa/4== size(q)){
        resize(q,(q->capa)/2);
    }
    else if ( (q->capa)-size(q)==(q->incr)*2){
        resize(q,(q->capa)-(q->incr));
    }
    return item;
}

void show_queue(cqueue q) { // display cqueue status
    int i;
    if(empty(q))
        cout << endl << "Empty Queue" << endl;
    else {
        cout << "\tFront:Back = [" << q->front << ":" << q->back << "]\n";
        cout << "\tQueue:[ ";
        string temp[q->capa];
        int count=0;
        if(q->front < q->back){
            for( i = q->front; i <= q->back; i = i + 1){
                temp[count] = q->items[i];
                count++;
            }
        }
        else if(q->front == q->back){
            i = q->front;
            temp[count] = q->items[i];
        }
        else {
            for(i=q->front; i <q->capa; i++){
                temp[count]=q->items[i] ;
                count++;
             }
            for(i=0; i<=q->back; i++){
                temp[count] = q->items[i];
                count++;
            }
        }
        if(size(q) >= q->shown){
            for(int i=0; i<q->shown/2; i++){
                cout <<temp[i] <<" ";
            }
            cout << "...";
            if(q->shown%2==0){
                for(int i=count-(q->shown)/2; i<count; i++){
                    cout << temp[i] <<" ";
                }
            }
            else {
                for(int i=count-(q->shown)/2-1; i<count; i++){
                    cout << temp[i] <<" ";
                }
            }
        }
        else {
            for(int i=0; i<size(q); i++){
                cout << temp[i] <<" ";
            }
        }
         
    //cout << q->items[i];
    cout << "]\n";
    assert(i<=q->capa);
    }

}

void clear(cqueue q){
    delete[] q->items;
    q->items = new string[q->capa];
    q->front = -1;
    q->back = -1;
    for(int i=0; i<q->capa; i++){
        q->items[i] = '-';
    }
}

void reset(cqueue q, int new_capacity){
    delete[] q->items;
    q->items = new string[new_capacity];
    q->capa = new_capacity;
    q->front = -1;
    q->back = -1;
    for(int i=0; i<q->capa; i++){
        q->items[i] = '-';
    }

}

void free(cqueue q){
    delete q;
}

void show_setup(cqueue q){
    cout << "\tSetup: front:back = [" << q->front << ":" << q->back <<"], size=" << size(q) <<", capacity=" <<q->capa <<", resize by ";
    if(q->doubling == true) cout << "2X, ";
    else cout << q->incr<<", ";
    cout << "show n=" << q->shown <<"\n";
}

void show_items(cqueue q){
    cout << "\tItems: [ ";
    if(q->capa < q->shown){
        for(int i=0; i<q->capa; i++){
            cout << q->items[i] << " ";
        }
    }
    else {
        for(int i=0; i<q->shown/2; i++){
            cout << q->items[i] <<" ";
        }
        if(q->capa != q->shown){
            cout << "... ";
        }
        if(q->shown%2==0){
            for(int i=q->capa - q->shown/2; i<q->capa; i++){
                cout<< q->items[i]<<" ";
            }
        }
        else {
            for(int i=q->capa - q->shown/2; i<q->capa; i++){
                cout<< q->items[i]<<" ";
            }
        }
        
    }
    cout << "]";
}

