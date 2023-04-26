#include <iostream>

using namespace std;

template <typename T>
class List
{
    struct Item
    {
        T inf;
        Item *next;
        Item *prev;
        Item(T x, Item *ref = nullptr, Item *prevRef = nullptr) : inf(x), next(ref), prev(prevRef) {}
    }
        *first = nullptr,
        *last = nullptr;
    unsigned int size = 0;

public:
    List() : first(nullptr), last(nullptr), size(0) {}
    unsigned int getSize()
    {
        return this->size;
    }
    void add(T x)
    {
        Item *t = new Item(x);
        if (size == 0)
        {
            first = t;
            last = t;
        }
        else
        {
            last->next = t;
            t->prev = last;
            last = t;
        }
        size++;
    }
    void pop_back()
    {
        if (size == 0)
        {
            return;
        }
        else if (size == 1)
        {
            delete last;
            first = nullptr;
            last = nullptr;
            size = 0;
        }
        else
        {
            Item *t = last->prev;
            t->next = nullptr;
            delete last;
            last = t;
            size--;
        }
    }
    ~List()
    {
        while (first != nullptr)
        {
            this->pop_back();
        }
    }

    void print()
    {
        for (Item *t = first; t != nullptr; t = t->next)
            cout << t->inf << " ";
        cout << endl;
    }
    T &operator[](int index)
    {
        Item *t = first;
        for (int i = 0; i < index; i++)
        {
            t = t->next;
        }
        return t->inf;
    }
};

int main()
{
    List<int> lst;
    int t, n = 10;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        lst.add(t);
    }
    List<int> newLst;
    for (int i = 0; i < n; i++)
    {
        t = lst[i];
        if (t < 0)
            newLst.add(t);
    }
    for (int i = 0; i < n; i++)
    {
        t = lst[i];
        if (t >= 0)
            newLst.add(t);
    }
    newLst.print();
    system("pause");
}
