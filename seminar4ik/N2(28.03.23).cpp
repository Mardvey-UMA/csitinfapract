#include <iostream>
#include <string>

using namespace std;

void selectionSort(string* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j].length() < arr[min_idx].length())
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            string temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите количество строк: ";
    cin >> n;

    string* arr = new string[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    selectionSort(arr, n);

    cout << "Отсортированный массив строк по длине: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    delete[] arr;

}
