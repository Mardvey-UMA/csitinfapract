#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;
int rand_between(const int from, const int to) {
  if (to == from)
    return to;
  if (to < from)
    return rand_between(to, from);
  return from + rand() % (to-from+1);
}
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
    ~Stack(){
        if (this->isEmpty() != 0){
            while (this->isEmpty() != 0){
                int y = this->Pop();
                if (this->isEmpty() == 0){
                    break;
                }
                }
            }
    }
};
int main(){
    srand(time(NULL));
    Stack orStack;
    for(int i=0; i<20; i++){
        orStack.Push(rand_between(-10, 10)); 
    }

    Stack newStack;
    Stack tempStack; 
    int x;
    while(!orStack.isEmpty()){
        x = orStack.Pop();
        if(x < 0){
            newStack.Push(x); 
        }else{
            tempStack.Push(x); 
        }
    }
    while(!tempStack.isEmpty()){
        x = tempStack.Pop();
        newStack.Push(x); 
    }
    while(!newStack.isEmpty()){
        cout << newStack.Pop() << " ";
    }
    cout << endl;
    system("pause");
}
