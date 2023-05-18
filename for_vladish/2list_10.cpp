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
    List(const List &other) : first(nullptr), last(nullptr), size(0)
    {
        for (Item *t = other.first; t != nullptr; t = t->next)
        {
            this->add(t->inf);
        }
    }
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
    List get_all_positive()
    {
        List *tmp_lst = new List;
        for (Item *t = first; t != nullptr; t = t->next)
            if (t->inf > 0)
                tmp_lst->add(t->inf);
        return *tmp_lst;
    }
    List get_all_negative(bool with_null = false)
    {
        List *tmp_lst = new List;
        for (Item *t = first; t != nullptr; t = t->next)
        {
            if (with_null)
            {
                if (t->inf <= 0)
                    tmp_lst->add(t->inf);
            }
            else
            {
                if (t->inf < 0)
                    tmp_lst->add(t->inf);
            }
        }
        return *tmp_lst;
    }
    void add_list(const List &other)
    {
        for (Item *t = other.first; t != nullptr; t = t->next)
        {
            this->add(t->inf);
        }
    }
    ~List()
    {
        while (first != nullptr)
        {
            this->pop_back();
        }
    }
    void erase(Item *t)
    {
        if (t == nullptr)
        {
            return;
        }
        if (t == first)
        {
            this->pop_head();
            return;
        }

        if (t == last)
        {
            this->pop_back();
            return;
        }
        t->prev->next = t->next;
        t->next->prev = t->prev;
        delete t;
        size--;
    }
    T get_min()
    {
        T mn = this->first->inf;
        for (Item *t = first; t != nullptr; t = t->next)
        {
            if (t->inf < mn)
            {
                mn = t->inf;
            }
        }
        return mn;
    }
    void pop_head()
    {
        if (first == nullptr)
        {
            return;
        }
        Item *t = first;
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
    }
    void delete_value(T value)
    {
        Item *t = first;
        while (t != nullptr)
        {
            if (t->inf == value)
            {
                Item *toDelete = t;
                t = t->next;
                erase(toDelete);
            }
            else
            {
                t = t->next;
            }
        }
    }
    void print()
    {
        for (Item *t = first; t != nullptr; t = t->next)
            cout << t->inf << " ";
        cout << endl;
    }
    void reverse_print()
    {
        for (Item *t = last; t != nullptr; t = t->prev)
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
    int m = lst.get_min();
    lst.delete_value(m);
    lst.print();
    lst.reverse_print(); // Пруф, что двусвязный список работает
    system("pause");
}
