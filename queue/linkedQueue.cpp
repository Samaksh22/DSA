#include <iostream>
#include <string>
#include "CircularList.hpp"

using namespace std;

template <typename E>
class Queue
{
private:
    CircularList<E> q;

public:
    Queue() : q() {}

    int size() const
    {
        return q.size();
    }

    bool empty() const
    {
        return q.empty();
    }

    E &front()
    {
        return q.front();
    }

    void enqueue(const E &e)
    {
        q.add(e);
        q.advance();
    }

    void dequeue()
    {
        if (empty())
            return;
        q.remove();
    }
};

int main()
{
    Queue<int> q;
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(3);
    q.enqueue(2);
    cout << q.front() << endl;
    q.dequeue();
    cout << q.front() << endl;
    q.dequeue();
    cout << q.front() << endl;
    q.dequeue();
    cout << q.front() << endl;
    q.dequeue();
}