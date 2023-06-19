#include <iostream>
#include <list>
using namespace std;

template<typename T>
class Queue: public list<T>
{
public:
    Queue() {}

    void push(T value) { list<T>::push_back(value); }
    T pop() 
    { 
        T elem = list<T>::back();
        list<T>::pop_back(); 
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