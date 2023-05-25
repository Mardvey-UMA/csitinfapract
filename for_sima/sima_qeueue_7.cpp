#include <cstdlib>
#include <iostream>
#include <ctime>
#include "exception.cpp"

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
void removeDuplicates(Queue<int>& q) {
    if (q.isEmpty()) {
        return;
    }
    int prev = q.Get();
    Queue<int> tempQueu;
    while (!q.isEmpty()) {
        int curr = q.Get();
        if (curr != prev) {
            tempQueu.Push(prev);
            prev = curr;
        }
    }
    // Решение аналогично стеку, только с очередью
    tempQueu.Push(prev);
    while (!tempQueu.isEmpty())
        q.Push(tempQueu.Get());
}

int main(){
    Queue<int> q;
    int t, n = 14;
    cout << "Enter qeueue, size = " << n << endl;
    for (int i = 0; i < n; i++){
        cin >> t;
        q.Push(t);
    }
    removeDuplicates(q);
    cout << "Result\n";
    while (!q.isEmpty()){
        cout << q.Get() << " ";
    }
    cout << endl;
    system("pause");
        // 1 2 3 3 3 4 5 6 6 6 8 9 8 9 - test (14 чисел)
    //  1 2 3 4 5 6 8 9 8 9 - res
}