#include <iostream>

using namespace std;

template <typename T>
class List // Своя реализация односвязного списка (половина кода с методички)
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
    void erase(Item *t) // Удаление элемента по указателю
    {
        if (t == nullptr)
        {
            return;
        }
        if (t == first)
        {
            this -> pop_head();
            return;
        }

        if (t == last)
        {
            this -> pop_back();
            return;
        }
        Item *prev_t = first;
        while (prev_t != nullptr && prev_t->next != t)
        {
            prev_t = prev_t->next;
        }
        prev_t->next = t->next;
        delete t;
        size--;
    }
void delete_povtor(){ // Функция для удаления последовательностей одинаковых (собственно что там и нужно было в задаче)
    if (first == nullptr){
        return;
    }
    Item *prev_t = first;
    Item *t = first->next;
    while (t != nullptr){
        if (t->inf == prev_t->inf){
            erase(t);
            t = prev_t->next;
        }else{
            prev_t = t;
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
    system("pause");
    // 1 2 3 3 3 4 5 6 6 6 8 9 8 9 - test (14 чисел)
    //  1 2 3 4 5 6 8 9 8 9 - res
}