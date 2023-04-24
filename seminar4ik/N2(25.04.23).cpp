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

public:
    List() : first(nullptr), last(nullptr) {}
    List(const List &other){
        this->add(other.first->inf);
        Item* t = other.first;
        t = t -> next;
        while(t != nullptr){
            this->add(t -> inf);
            t = t -> next;
        }
    }
	void add(T x)
	{
		Item *item = new Item(x);
		if (last != nullptr)
			last->next = item;
		last = item;
		if (first == nullptr)
			first = last;
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
      return;
    }
    Item* t = first;
    while (t->next != last) // Шагаем до предпоследнего 
      t = t->next;
    delete last; // Удаляем последний
    last = t; // Переозначаем последний как предпоследний
    last->next = nullptr; // Ставим указатель следующего после последнего как nullptr
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
          Item* newItem = new Item(t->inf, t->next); 
          t->next = newItem; 
          if (t == last) // Если был добавлен элемент после последнего, то меняем указатель на последний элемент
            last = newItem;
          t = t->next; // Шагаем на следующий элемент, чтобы не зациклиться на дублировании
        }
        t = t->next; // Итерируемся
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

int main()
{
	List<int> lst;
    lst.add(1);
	lst.add(2);
	lst.add(3);
	lst.add(3);
	lst.add(6);
    cout << "lst: ";
	lst.print();
    //Создаем список и выводим его
    List<int> lst2(lst);
    cout << "lst2: ";
    lst2.print();
    //С помощью конструктора копирования созадем новый список
    lst2.duplicateEven();
    // Изменяем новый список, чтобы показать, что скопировались только значения, но не ссылки
    cout << "changed lst2: ";
    lst2.print();
    system("pause");
}
