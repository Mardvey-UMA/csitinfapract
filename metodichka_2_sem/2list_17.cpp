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
    for (int i = 0; i < n; i++){
        cin >> t;
        lst.add(t);
    }
    List<int> newLst(lst.get_all_negative());
    newLst.add_list(lst.get_all_positive());
    newLst.print();
    newLst.reverse_print();
    system("pause");
}
