#include <cstdlib>
#include <iostream>
#include <ctime>
#include "exception.cpp"
template <class Item>
class Queue
{
    struct Element
    {
        Item value;
        Element *next;
        Element(Item x) : value(x), next(NULL) {}
    };
    Element *head, *tail;

public:
    Queue() : head(NULL), tail(NULL) {}
    bool isEmpty()
    {
        return head == 0;
    }
    Item Get()
    {
        if (isEmpty())
        {
            throw QueueException("QueueException: get - qeueu empty");
        }
        else
        {
            Element *t = head;
            Item val = t->value;
            head = t->next;
            if (head == NULL)
            {
                tail = NULL;
            }
            delete t;
            return val;
        }
    }
    void Push(Item data)
    {
        Element *t = tail;
        tail = new Element(data);
        if (!head)
        {
            head = tail;
        }
        else
        {
            t->next = tail;
        }
    }
};

int main()
{
    Queue<int> OrQueue;
    int t, n = 10;
    for (int i = 0; i < n; i++)
    {   cin >> t;
        OrQueue.Push(t);
    }
    int min = 100000;
    Queue<int> OrQueueCopy;
    while (!OrQueue.isEmpty())
    {
        int current = OrQueue.Get();
        if (current < min)
        {
            min = current;
        }
        OrQueueCopy.Push(current);
    }

    while (!OrQueueCopy.isEmpty())
    {
        int current = OrQueueCopy.Get();
        if (current != min)
        {
            OrQueue.Push(current);
        }
    }
    //1 1 2 3 4 1 1 2 9 10
    while(!OrQueue.isEmpty()){
        cout << OrQueue.Get() << " ";
    }
    cout << endl;
    system("pause");
}
