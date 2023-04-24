#include <iostream>

using namespace std;

template <typename T>
class List
{
	struct Item
	{
		T inf;
		Item* next;
		Item(T x, Item* ref = nullptr) : inf(x), next(ref) {}
	} 
    *first = nullptr, *last = nullptr;
    unsigned int size = 0; 

public:
    List() : first(nullptr), last(nullptr), size(0) {}
    List(const List &other){
        this->add(other.first->inf);
        Item* t = other.first;
        t = t -> next;
        while(t != nullptr){
            this->add(t -> inf);
            t = t -> next;
        }
    }
    unsigned int getSize(){
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
    if (first == nullptr) // Если список пустой то нечего удалять
      return;
    if (first == last) // Если список состоит из однгого элемента
    {
      delete first;
      first = nullptr;
      last = nullptr;
      size--;
      return;
    }
    Item* t = first;
    while (t->next != last) // Шагаем до предпоследнего 
      t = t->next;
    delete last; // Удаляем последний
    last = t; // Переозначаем последний как предпоследний
    last->next = nullptr; // Ставим указатель следующего после последнего как nullptr
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
		for (Item* t = first; t != nullptr; t = t->next)
			cout << t->inf << " ";
		cout << endl;
	}
    void duplicateEven()
    {
      if (first == nullptr) // Проверка на пустоту списка
         return;
      Item* t = first;
      while (t != nullptr) // Цикл while вмето for, чтобы случайно не перешагнуть
      {
        if (t->inf % 2 == 0)
        {
          size++;
          Item* newItem = new Item(t->inf, t->next); 
          t->next = newItem; 
          if (t == last) // Если был добавлен элемент после последнего, то меняем указатель на последний элемент
            last = newItem;
          t = t->next; // Шагаем на следующий элемент, чтобы не зациклиться на дублировании
        }
        t = t->next; // Итерируемся
      }
    }

T& operator[](int index)
  {
    if (index < 0 || index >= size)
      cout << "Index out of range" << endl;
    Item* t = first;
    for (int i = 0; i < index; i++)
      t = t->next;
    return t->inf;
  }

    T get_first() // Получить значение первого элемента списка
    {
    if (first != nullptr)
      return first->inf;
    cout << "Empty list";
    }

    T get_last() // Получить значение последнего элемента списка
    {
    if (last != nullptr)
      return last->inf;
    cout <<  "Empty list";
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
        Item* t = first;
        for (int i = 0; i < index; i++)
        {
            t = t->next;
        }
        Item* newItem = new Item(x, t->next);
        t->next = newItem;
        size++;
    }
    }

     ~List() // Деструктор для очистки памяти после работы со списком
    {
    while (first != nullptr) // Удаляем пока первый не станет пустым
    {
      this->pop_back();
      //cout << "Clear memory" << endl;
    }
  }
};

template<typename T>
class SimpleVector{
private:
    T* data;
    unsigned int size, curr_size;
public:
    SimpleVector(): data(nullptr), size(0), curr_size(1) {} // size - для реального размера с которым работает юзер
    // curr_size - количество ячеек памяти выделенных для работы
    void push_back(T value){
        if (size + 1 < curr_size){
            data[size] = value;
            size++;
        }else if (size == 0){
            data = new T[curr_size];
            *data = value;
            size++;
        }else{
            curr_size*=2;
            T* temp = new T[curr_size];
            for (int i = 0; i < size; i++){
                *(temp + i) = *(data + i);
            }
            *(temp + size) = value;
            delete[] data;
            data = temp;
            size++;
        }
    }
    void pop_head(){
        if (size > 0){
            for (int i = 0; i < size-1; i++){
                *(data + i) = *(data + i + 1);
            }
            size--;
        }
    }
    void pop_back(){
        if (size > 0){
            T* temp = new T[curr_size];
            for (int i = 0; i < size - 1; i++){
                *(temp + i) = *(data + i);
            }
            size--;
        }
    }
    T& operator[](int index) {
        if (index >= size)
        {
            cout << "Error: index out of range" << endl;
            exit(1);
        }
        return *(data+index);
    }
    unsigned int getSize(){
        return this->size;
    }
    unsigned int getrealSize(){
        return this->curr_size;
    }
    void insert(int index, T item) { // Метод для вставки элемента в массив после указанного индекса
        if (index >= size){
            push_back(item);
        }   
        else {
        T* temp = new T[size+1];
        for (int i = 0; i <= index; ++i){
            *(temp + i) = *(data + i);
        }
        *(temp + index + 1) = item;
        for (int i = index + 1; i < size; i++){
            *(temp + i + 1) = *(data + i);
        }
        delete[] data;
        data = temp;
        size++;
        }
        }
    
    void print(){
        for (int i = 0; i < size; i++){
            cout << *(data + i) << " ";
        }
        cout << endl;
    }
    ~SimpleVector() {
        if (size >= 0){
            delete[] data;
        }
    }
};

int main(){
    SimpleVector<int> vec;
    vec.push_back(2);
    vec.push_back(8);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(8); 
    vec.push_back(4);
    List<int> lst;
    lst.add(10);
	lst.add(20);
	lst.add(3);
	lst.add(3);
	lst.add(6);
    lst.add(7);
//5(a)
    cout << "5(a)\n";
    //List:
        int x = lst.get_last();
        lst.add(x);
        lst.print();
    //SimpleVector:
        x = vec[vec.getSize() - 1];
        vec.push_back(x);
        vec.print();
//5(б)
    cout << "5(b)\n";
    //List:
        lst.pop_head();
        lst.print();
    //SimpleVector:
        vec.pop_head();
        vec.print();
//5(в)
    cout << "5(B)\n";
    //List:
    int idx = 0;
    int mn = 34534;
    //cout << lst.getSize() << endl;
    for (int i = 0; i < lst.getSize(); i++){
        if (lst[i] < mn){
            idx = i;
            mn = lst[i];
        }
    }
    cout << idx << endl;
    lst.insert(idx - 1, 0);
    lst.insert(idx + 1, 0);
    lst.print();
    //SimpleVector:
    idx = 0;
    mn = vec[idx];
    for (int i = 0; i < vec.getSize(); i++){
        if (vec[i] < mn){
            idx = i;
            mn = vec[i];
        }
    }
    vec.insert(idx - 1, 0);
    vec.insert(idx + 1, 0);
    vec.print();
//5(g)
    cout << "5(g)\n";
    //List:
    int fo;
    for (int i = lst.getSize() - 1; i >= 0; i--){
        if (lst[i] % 2 == 0){
            fo = lst[i];
            break;
        }
    }
    lst[lst.getSize() / 2] = fo;
    lst.print();
    //SimpleVector:
    fo;
    for (int i = vec.getSize() - 1; i >= 0; i--){
        if (vec[i] % 2 == 0){
            fo = vec[i];
            break;
        }
    }
    vec[vec.getSize() / 2] = fo;
    vec.print();
    system("pause");
}
