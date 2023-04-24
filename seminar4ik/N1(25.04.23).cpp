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
	  lst.print();
    //lst.pop_back();
    lst.duplicateEven();
    lst.print();
    lst.~List();
    system("pause");
}
