#include <iostream>

using namespace std;

template <typename T>
class List
{
    struct Item
    {
        T inf;
        Item *next;
        Item(T x, Item *ref = nullptr) : inf(x), next(ref) {}
    }
        *first = nullptr,
        *last = nullptr;
    unsigned int size = 0;

public:
    List() : first(nullptr), last(nullptr), size(0) {}
    List(const List &other)
    {
        this->add(other.first->inf);
        Item *t = other.first;
        t = t->next;
        while (t != nullptr)
        {
            this->add(t->inf);
            t = t->next;
        }
    }
    unsigned int getSize()
    {
        return this->size;
    }
    void add(T x)
    {
        Item *item = new Item(x);
        if (last != nullptr)
            last->next = item;
        last = item;
        if (first == nullptr)
            first = last;
        size++;
    }
    void pop_back()
    {
        if (first == nullptr)
            return;
        if (first == last)
        {
            delete first;
            first = nullptr;
            last = nullptr;
            size--;
            return;
        }
        Item *t = first;
        while (t->next != last)
            t = t->next;
        delete last;
        last = t;
        last->next = nullptr;
        size--;
    }
    void pop_head()
    {
        if (first == nullptr)
            return;
        Item *t = first;
        first = t->next;
        delete t;
        size--;
        if (first == nullptr)
            last = nullptr;
        size--;
    }

    void print()
    {
        for (Item *t = first; t != nullptr; t = t->next)
            cout << t->inf << " ";
        cout << endl;
    }
    void duplicateEven()
    {
        if (first == nullptr)
            return;
        Item *t = first;
        while (t != nullptr)
        {
            if (t->inf % 2 == 0)
            {
                size++;
                Item *newItem = new Item(t->inf, t->next);
                t->next = newItem;
                if (t == last)
                    last = newItem;
                t = t->next;
            }
            t = t->next;
        }
    }

    T &operator[](int index)
    {
        if (index < 0 || index >= size)
            cout << "Index out of range" << endl;
        Item *t = first;
        for (int i = 0; i < index; i++)
            t = t->next;
        return t->inf;
    }

    T get_first()
    {
        if (first != nullptr)
            return first->inf;
        cout << "Empty list";
    }

    T get_last()
    {
        if (last != nullptr)
            return last->inf;
        cout << "Empty list";
    }

    void insert(int index, T x)
    {
        if (index < 0 || index > size)
        {
            cout << "Index out of range";
            return;
        }
        if (index == size - 1)
        {
            add(x);
        }
        else
        {
            Item *t = first;
            for (int i = 0; i < index; i++)
            {
                t = t->next;
            }
            Item *newItem = new Item(x, t->next);
            t->next = newItem;
            size++;
        }
    }

    ~List()
    {
        while (first != nullptr)
        {
            this->pop_back();
        }
    }
};

int main(){

    List<int> lst;
    int t, n = 10;
    for (int i = 0; i < n; i++){
        cin >> t;
        lst.add(t);
    }
    List<int> newLst;
    for (int i = 0; i < n; i++){
        t = lst[i];
        if (t < 0)
            newLst.add(t);
    }
    for (int i = 0; i < n; i++){
        t = lst[i];
        if (t >= 0)
            newLst.add(t);
    }
    newLst.print();
    system("pause");
}
