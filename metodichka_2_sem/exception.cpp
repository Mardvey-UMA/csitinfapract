#include "string"
using namespace std;

class QueueException{
private:
    string str;
public:
    QueueException(string message) : str(message) {}
    string what(){
        return str;
    }
};