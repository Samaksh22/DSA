#pragma once

#include <exception>

template <class E>
class ArrayVector
{
private:
    int N;
    int n;
    E *A;

public:
    ArrayVector()
    {
        A = nullptr;
        N = 0;
        n = 0;
    }

    ~ArrayVector()
    {
        delete[] A;
    }

    int size() const
    {
        return n;
    }

    bool empty() const
    {
        return n == 0;
    }

    E &operator[](int i)
    {
        return A[i];
    }

    E &at(int i)
    {
        if (i < 0 || i >= N)
            throw std::exception("Index out of bounds");
        return A[i];
    }

    void remove(int i)
    {
        for (int j = i + 1; j < n; j++)
            A[j - 1] = A[j];
        n--;
    }

    void reserve(int c)
    {
        if (N >= c)
            return;

        E *B = new E[c];
        for (int j = 0; j < n; j++)
            A[j] = B[j];

        if (A != nullptr)
            delete[] A;

        A = B;
        N = c;
    }

    void insert(int i, const E &e)
    {
        if (n >= N)
            reserve(2 * N + 1);

        for (int j = n - 1; j >= i; j--)
            A[j + 1] = A[j];
        A[i] = e;
        n++;
    }
};