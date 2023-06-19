#include <iostream>
#include <list>
using namespace std;

template<typename T>
class Queue
{
    list<T>* _list;
public:
    Queue()
    {
        _list = new list<T>;
    }

    void push(T value) { _list->push_back(value); }
    T pop()
    {
        T elem = _list->back();
        _list->pop_back();
        return elem;
    }
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