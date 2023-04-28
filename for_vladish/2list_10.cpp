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

    void print()
    {
        for (Item *t = first; t != nullptr; t = t->next)
            cout << t->inf << " ";
        cout << endl;
    }
    void erase(int index)
    {
        if (index < 0 || index >= size)
        {
            return;
        }
        Item *t = first;
        if (index == 0)
        {
            first = t->next;
            if (first != nullptr)
            {
                first->prev = nullptr;
            }
            else
            {
                last = nullptr;
            }
            delete t;
            size--;
            return;
        }
        for (int i = 0; i < index - 1; i++)
        {
            t = t->next;
        }
        t->prev->next = t->next;
        if (t->next != nullptr)
        {
            t->next->prev = t->prev;
        }
        else
        {
            last = t->prev;
        }
        delete t;
        size--;
    }
    T &operator[](int index)
    {
        Item *t = first;
        for (int i = 0; i < index - 1; i++)
        {
            t = t->next;
        }
        return t->inf;
    }
    ~List()
    {
        while (first != nullptr)
        {
            this->pop_back();
        }
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
    int r, mn = lst[0];
    for (int i = 0; i < n; i++)
    {
        r = lst[i];
        if (r < mn)
        {
            mn = r;
        }
    }
    // 1 1 2 3 4 1 1 2 9 10
    int i = 0;
    while (i < lst.getSize())
    {
        if (lst[i] == mn)
        {
            lst.erase(i);
        }
        else
        {
            i++;
        }
    }
    lst.print();
    system("pause");
}
