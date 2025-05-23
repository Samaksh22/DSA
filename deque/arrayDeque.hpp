#pragma once

#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE 10

template <class E>
class Deque
{
private:
    E *arr;
    int capacity;
    int n;
    int i;

public:
    Deque(int c) : capacity(c), n(0), i(0)
    {
        arr = new E[c];
    }

    ~Deque()
    {
        delete[] arr;
    }

    void printDeque()
    {
        cout << "Deque: ";

        int t = 0;
        while (t < capacity)
        {
            int j = (i + t) % capacity;
            if (t < n)
                cout << arr[j] << " ";
            else
                cout << "_ ";

            ++t;
        }

        cout << endl;
    }

    int size()
    {
        return n;
    }

    E &front()
    {
        if (n == 0)
            return E{};
        return arr[i];
    }

    E &back()
    {
        if (n == 0)
            return E{};
        int j = (i + n - 1) % capacity;
        return arr[j];
    }

    void addFront(E e)
    {
        if (n == capacity)
            cout << "Deque is Full ..." << endl;
        else
        {
            i = (i - 1) % capacity;
            ++n;
            arr[i] = e;
        }
    }

    void addBack(E e)
    {
        if (n == capacity)
            cout << "Deque is Full ..." << endl;
        else
        {
            int j = (i + n) % capacity;
            ++n;
            arr[j] = e;
        }
    }

    void removeFront()
    {
        if (n == 0)
            cout << "Deque is Empty ..." << endl;
        else
        {
            i = (i + 1) % capacity;
            --n;
        }
    }

    void removeBack()
    {
        if (n == 0)
            cout << "Deque is Empty ..." << endl;
        else
        {
            --n;
        }
    }
};
