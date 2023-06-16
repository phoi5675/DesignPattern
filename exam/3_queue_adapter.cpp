#include <iostream>
#include <list>
using namespace std;

template<typename T>
class Queue
{
    list<T> _list;
public:
    Queue() {}

    void push(T value) {}
    T pop() {return;}
};
int main()
{
    Queue<int> q;
    q.push(10);
    q.push(20);

    cout << q.pop() << endl;
    cout << q.pop() << endl;

    return 0;
}