#include <iostream>

using namespace std;

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
    ~SimpleVector() {
        if (size >= 0){
            delete[] data;
        }
    }
};
int main(){
    SimpleVector<int> vec;
    vec.push_back(2);
    cout << "Real Size: " << vec.getrealSize() << " Ghost size: " << vec.getSize() << endl;
    vec.push_back(8);
    cout << "Real Size: " << vec.getrealSize() << " Ghost size: " << vec.getSize() << endl;
    vec.push_back(1);
    cout << "Real Size: " << vec.getrealSize() << " Ghost size: " << vec.getSize() << endl;
    vec.push_back(2);
    cout << "Real Size: " << vec.getrealSize() << " Ghost size: " << vec.getSize() << endl;
    vec.push_back(0); // Тут видно, что после прибавления элемента так как хватает выделенной памяти, дополнительная не выделяется
    cout << "Real Size: " << vec.getrealSize() << " Ghost size: " << vec.getSize() << endl;
    vec.push_back(4);
    cout << "Real Size: " << vec.getrealSize() << " Ghost size: " << vec.getSize() << endl;
    for (int i = 0; i < vec.getSize(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}