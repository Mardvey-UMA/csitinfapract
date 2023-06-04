#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cmath>
using namespace std;
//Найти два идущих подряд звука, совпадающих по высоте
class Sound{
    int hight_note, time;
    public:
    Sound() : hight_note(0), time(0) {}
    Sound (int h_n, int _time) : hight_note(h_n), time(_time) {}
    int get_high(){
        return this->hight_note;
    }
    void print_sound(){
        cout << "Note :" << this -> hight_note << " Duration: " << this->time << " sec" << endl;
    }
};
int main(){
vector <Sound> melody;
melody.push_back({12, 1});
melody.push_back({10, 3});
melody.push_back({4, 5});
melody.push_back({6, 7});
melody.push_back({6, 76});
melody.push_back({10, 4});
melody.push_back({4, 10});
melody.push_back({45, 4});
melody.push_back({4, 11});
melody.push_back({12, 6});
melody.push_back({12, 18});
melody.push_back({12, 4});
melody.push_back({2, 6});
    auto it = adjacent_find(melody.begin(), melody.end(), [](Sound &s1, Sound &s2){
        return s1.get_high() == s2.get_high();
    });
    while (it != melody.end()){
            it->print_sound();
            (it+1)->print_sound();
            cout << endl;
            it = adjacent_find((it+1), melody.end(), [](Sound &s1, Sound &s2){
                return s1.get_high() == s2.get_high();
            });
    }

system("pause");
}