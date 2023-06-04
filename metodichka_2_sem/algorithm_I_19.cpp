/*
а) удалить все точки из квадрата со 
стороной A с центром в начале координат
b) подсчитать количество точек, 
лежащих правее оси y
c) найти самую близкую к началу 
координат среди точек, лежащих выше y = |x|
d) расположить в порядке приближения к началу 
координат, сохраняя исходный порядок при одинаковом расстоянии*/
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cmath>
using namespace std;

void define_vector(vector <pair<int, int>> &points){
    points.clear();
    int A;
    A = 2;
    points.push_back({A/2, -A/2});
    points.push_back({-A/2, -A/2});
    points.push_back({A/2, A/2});
    points.push_back({-A/2, A/2});
    A = 4;
    points.push_back({A/2, -A/2});
    points.push_back({-A/2, -A/2});
    points.push_back({A/2, A/2});
    points.push_back({-A/2, A/2});  
    A = 6;
    points.push_back({A/2, -A/2});
    points.push_back({-A/2, -A/2});
    points.push_back({A/2, A/2});
    points.push_back({-A/2, A/2});
    /////////////////////////
    points.push_back({0, -2});
    points.push_back({4, -5});
    points.push_back({5, -8});
    points.push_back({0, 2});
    points.push_back({1, 7});
    points.push_back({8, 10});
    points.push_back({-10, 34});
    ////////////////////////////
    points.push_back({0, 1});
    points.push_back({0, 2});
    points.push_back({0, 3});
    points.push_back({-1, 2});
    points.push_back({1, 2});
    points.push_back({1, 5});
    points.push_back({1, 1});
    points.push_back({2, 4});
    points.push_back({3, 2});
    points.push_back({3, 1});
    points.push_back({4, 4});
    ///////////////////////////
}
void print_vector(vector <pair<int, int>> &points){
    for (auto x: points){
        cout << "(" << x.first << "," << x.second << ") ";
    }
    cout << endl;
}
int main(){
    vector <pair<int, int>> points;    
    //a
    cout << "Solve probmlem a:\n";
    cout << "Start vector:\n";
    define_vector(points);
    print_vector(points);
    int A = 6;
    cout << "Delete all points inside square " << A << "x" << A << endl;
        points.erase(remove_if(points.begin(), points.end(), [A](pair<int, int> p){
        return (p.first >= -A/2 && p.first <= A/2 && p.second >= -A/2 && p.second <= A/2);
    }), points.end());
    cout << "Result:\n";
    print_vector(points);
    //b
    cout << "Solve probmlem b:\n";
    cout << "Start vector:\n"; 
    define_vector(points);
    print_vector(points);
    int ans =  count_if(points.begin(), points.end(), [](pair<int, int> p){
        return p.first > 0;
    });
    cout << "Count of points x > 0\n";
    cout << ans << endl;
    //c
    cout << "Solve probmlem c:\n";
    cout << "Start vector:\n";
    define_vector(points);
    points.erase( //Удаляем все точки ниже или лежащие на |x|
    remove_if(points.begin(), points.end(), [](pair<int, int> p)
    {
        return abs(p.second) <= abs(p.first);
    }), points.end()
    );
    // берем минимальный элемент из оставшихся с помощью собственного предиката
    auto it = *min_element(points.begin(), points.end(), [](pair<int, int> p1, pair<int, int> p2){
        return sqrt(p1.first*p1.first + p1.second*p1.second) < sqrt(p2.first*p2.first + p2.second*p2.second);
    });
    cout << "Nearest (0,0) point and upper y = |x|\n";
    cout << "(" << it.first << "," << it.second << ") " << endl;
    //d
    cout << "Solve probmlem d:\n";
    cout << "Start vector:\n";
    define_vector(points);
    stable_sort(points.begin(), points.end(), [](pair<int, int> p1, pair<int, int> p2){
        return sqrt(p1.first*p1.first + p1.second*p1.second) < sqrt(p2.first*p2.first + p2.second*p2.second);
    });
    cout << "Sorted vector:\n";
    print_vector(points);
    system("pause");
}