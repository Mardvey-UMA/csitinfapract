#include <cstdlib>
#include <iostream>
#include <ctime>
#include "exception.cpp"
int rand_between(const int from, const int to) {
  if (to == from)
    return to;
  if (to < from)
    return rand_between(to, from);
  return from + rand() % (to-from+1);
}
template <class Item>
class Queue{
struct Element{
    Item value;
    Element *next;
    Element (Item x) : value(x), next(NULL) {}
};
    Element *head, *tail;
public:
    Queue() : head(NULL), tail(NULL) {}
    bool isEmpty(){
        return head == 0;
    }
    Item Get(){
        if (isEmpty()){
            throw QueueException("QueueException: get - qeueu empty");
        }else{
            Element *t = head;
            Item val = t -> value;
            head = t -> next;
            if (head == NULL){
                tail = NULL;
            }
            delete t;
            return val;
        }
    }
    void Push(Item data){
        Element *t = tail;
        tail = new Element(data);
        if (!head){
            head = tail;
        }else{
            t -> next = tail;
        }
    }
};

int main(){
    srand(time(NULL));
    Queue <int>OrQueue;
        for(int i = 0; i < 20; i++){
        OrQueue.Push(rand_between(-10, 10)); 
    }
    Queue <int>newQueue;
    Queue <int>tempQueue;
    int x;
    while(!OrQueue.isEmpty()){
        x = OrQueue.Get();
        if (x < 0){
            newQueue.Push(x);
        }else{
            tempQueue.Push(x);
        }
    }
    while(!tempQueue.isEmpty()){
        x = tempQueue.Get();
        newQueue.Push(x);
    }
    while(!newQueue.isEmpty())
        cout << newQueue.Get() << " ";
    cout << endl;
    system("pause");
}
