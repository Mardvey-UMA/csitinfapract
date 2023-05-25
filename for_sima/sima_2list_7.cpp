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
    ~List()
    {
        while (first != nullptr)
        {
            this->pop_back();
        }
    }
    void delete_povtor(){
        {
    if (size <= 1)
    {
        return;
    }

    Item *current = first->next;
    Item *prev = first;

    while (current != nullptr)
    {
        if (current->inf == prev->inf)
        {
            Item *temp = current;
            current = current->next;
            prev->next = current;
            if (current != nullptr)
            {
                current->prev = prev;
            }
            delete temp;
            size--;
        }
        else
        {
            prev = current;
            current = current->next;
        }
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
};

int main()
{
    List<int> lst;
    int t, n = 14;
    cout << "Enter list, size = " << n << endl;
    for (int i = 0; i < n; i++){
        cin >> t;
        lst.add(t);
    }
    // Ввели список размера n
    lst.delete_povtor();
    // Применили функцию которая удаляет то что нужно в задаче
    cout << "Result\n";
    lst.print(); // Выводим результат
    lst.reverse_print(); // Выводим в обратном порядке чтобы показать, что у тебя список работает двусвязно
    system("pause");
    // 1 2 3 3 3 4 5 6 6 6 8 9 8 9 - test (14 чисел)
    //  1 2 3 4 5 6 8 9 8 9 - res
}