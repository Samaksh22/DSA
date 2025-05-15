#pragma once

template <typename E>
class Queue
{
private:
    E *arr;
    int f, n;
    int capacity;

public:
    Queue(int c)
    {
        arr = new E[c];
        capacity = c;
        n = 0;
        f = 0;
    }

    ~Queue()
    {
        delete[] arr;
    }

    int n() const
    {
        return n;
    }

    bool empty() const
    {
        return (n == 0);
    }

    E front() const
    {
        if (n == 0)
            return E{};
        return arr[f];
    }

    E back() const
    {
        if (n == 0)
            return E{};

        int r = (f + n - 1) % capacity;
        return arr[r];
    }

    void enqueue(const E &e)
    {
        if (size == capacity)
            return;

        int r = (f + n - 1) % capacity;
        arr[r] = e;
        ++n;
    }

    void dequeue()
    {
        if (size == 0)
            return;

        f = (f + 1) % capacity;
        n--;
    }
};