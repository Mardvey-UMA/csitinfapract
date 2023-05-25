#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

class Stack{
struct Elem{
    int value;
    Elem *next;
    Elem(int x, Elem* p) : value(x), next(p) {}
};
Elem *head;
public:
    Stack() : head(0) {}
    bool isEmpty(){
        return head == 0;
    }
    int Pop(){
        if (isEmpty()){
            return 0;
        }else{
            Elem* r = head;
            int temp_value = r -> value;
            head = r -> next;
            delete r;
            return temp_value;
        }
    }
    void Push(int data){
        head = new Elem(data, head);
    }
    int Top(){
        if (isEmpty()){
            return 0;
        }else{
            return head -> value;
        }
    }
};
void removeDuplicates(Stack& s){
    Stack tempStack; // Создали временный стек
    int currentElement;
    while(!s.isEmpty()){ // Пока основной стек не пуст
        currentElement = s.Pop(); // Считываем элемент из стека
        if(tempStack.isEmpty() || tempStack.Top() != currentElement){ // Если взятый элемент не равен следующему ему
            // То пишем во временной стек это значение
            tempStack.Push(currentElement);
        }
    }
    // Переписываем все что уникальное насобирали в основной стек
    while(!tempStack.isEmpty()){
        s.Push(tempStack.Pop());
    }
}
int main(){
    Stack s;
    int t, n = 14;
    cout << "Enter stack, size = " << n << endl;
    for (int i = 0; i < n; i++){
        cin >> t;
        s.Push(t);
    }
    removeDuplicates(s);
    cout << "Result\n";
    while (!s.isEmpty()){
        cout << s.Pop() << " ";
    }
    cout << endl;
    system("pause");
     // 1 2 3 3 3 4 5 6 6 6 8 9 8 9 - test (14 чисел)
    //  1 2 3 4 5 6 8 9 8 9 - res
}