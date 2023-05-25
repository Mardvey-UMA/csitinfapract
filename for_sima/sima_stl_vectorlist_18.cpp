#include <vector>
#include <list>
#include <iostream>

using namespace std;
int countDivisors(int n)
{
    int count = 0;
    for (int i = 1; i <= abs(n); i++)
    {
        if (n % i == 0)
        {
            count++;
        }
    }
    return count;
}

int main()
{

    /* А - лучше делать вектором, так как взятие элемента по
    индексу в векторе происходит за O(1), а в списке за O(n)
    Б - лучше делать листом, так как удаление в списке по указателю
    выполняется за O(1), плюс на первый и последний элемент есть указатели прямо в stl
    */
    // A
    vector<int> vec{20, 1, 3, 4, 5, 18, 18, 11, 12, 13, 14};
    cout << "Start vector\n";
    for (auto x : vec)
    {
        cout << x << " ";
    }
    cout << endl;
    if (vec.size() % 2 == 0)
    {
        cout << "Sorry size of vector must be odd\n";
    }
    else
    {
        if (countDivisors(vec[0]) == countDivisors(vec[vec.size() / 2]))
        {
            vec[0] = 0;
            vec[vec.size() / 2] = 0;
        }
        cout << "Result\n";
        for (auto x : vec)
        {
            cout << x << " ";
        }
    }
    cout << endl;
    //B
    list <int> lst{7, 1, 3, 4, 5, 18, 18, 11, 12, 13, 3};
    cout << "Start list\n";
    for (auto x : lst)
    {
        cout << x << " ";
    }
    cout << endl;
    auto fit = lst.begin();
    auto eit = lst.end();
    if (countDivisors(*fit) == 2 && countDivisors(*eit) == 2){
        lst.pop_back();
        lst.erase(fit);
    }
    cout << "Result\n";
    for (auto x : lst)
    {
        cout << x << " ";
    }
    cout << endl;
    system("pause");
}